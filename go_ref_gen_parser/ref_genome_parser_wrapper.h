#ifndef _REFERENCE_GENOME_PARSER_WRAPPER_HPP_
#define _REFERENCE_GENOME_PARSER_WRAPPER_HPP_

#ifdef __cplusplus
extern "C" {
#endif

struct base_counts {
    unsigned long long a;
    unsigned long long c;
    unsigned long long g;
    unsigned long long t;
};
typedef struct base_counts base_counts_t;

struct ref_gen_parser {
    void* handle;
};
typedef struct ref_gen_parser ref_gen_parser_t;

ref_gen_parser_t* ref_gen_parser_create(const char* s);
void ref_gen_parser_destroy(ref_gen_parser_t* r);

void get_version(ref_gen_parser_t* r, char* v, unsigned int size);

base_counts_t get_number_of_base_occurrences(ref_gen_parser_t* r);
void get_base_count_info(ref_gen_parser_t* r, char* s);

#ifdef __cplusplus
}
#endif

#endif // _REFERENCE_GENOME_PARSER_WRAPPER_HPP_
