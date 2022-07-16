//go:build linux
// +build linux

package main

/*
#cgo CFLAGS: -Wall -I .
#cgo LDFLAGS: -L . -lref_genome_parser -lref_genome_parser_wrapper -lstdc++
#include "ref_genome_parser_wrapper.h"
#include <string.h>
#include <stdlib.h>
*/
import "C"
import (
	"fmt"
	"os"
	"unsafe"
)

func CountBaseOccurrences(genomeString string) string {
	genomeCString := C.CString(genomeString)
	defer C.free(unsafe.Pointer(genomeCString))

	cHandle := C.ref_gen_parser_create(genomeCString)
	defer C.ref_gen_parser_destroy(cHandle)

	ver := C.malloc(C.sizeof_char * 128)
	defer C.free(unsafe.Pointer(ver))
	C.get_version(cHandle, (*C.char)(ver), 128)
	verBytes := C.GoBytes(ver, 128)
	fmt.Fprintf(os.Stdout, "parser version: %v\n", string(verBytes))

	countInfo := C.malloc(C.sizeof_char * 128)
	defer C.free(unsafe.Pointer(countInfo))
	C.get_base_count_info(cHandle, (*C.char)(countInfo))
	countInfoBytes := C.GoBytes(countInfo, 128)
	fmt.Println(string(countInfoBytes))

	return ""
}
