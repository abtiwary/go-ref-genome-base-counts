#include <string>
#include <vector>

#include <string.h>

#include "../ref_genome_parser/include/reference_genome_parser.hpp"
#include "ref_genome_parser_wrapper.h"

ref_gen_parser_t* ref_gen_parser_create(const char* s) {
    ref_gen_parser_t* r = nullptr;
    GenomeParser::ReferenceGenomeParser* p = nullptr;

    r = (ref_gen_parser_t*)malloc(sizeof(ref_gen_parser));
    if (r != nullptr) {
        r->handle = new GenomeParser::ReferenceGenomeParser(std::string{s});
    }
    return r;
}

void ref_gen_parser_destroy(ref_gen_parser_t* r) {
    if (r != nullptr) {
        auto h = static_cast<GenomeParser::ReferenceGenomeParser *>(r->handle);
        delete h;
        free(r);
    }
}

void get_version(ref_gen_parser_t* r, char* v, unsigned int size) {
    if (r != nullptr) {
        auto h = static_cast<GenomeParser::ReferenceGenomeParser *>(r->handle);
        if (h) {
            auto version = h->get_version_hash();
            if (size >= version.size()) {
                strcpy(v, version.c_str());
            }
        }
    }
}

base_counts_t get_number_of_base_occurrences(ref_gen_parser_t* r) {
    base_counts_t ret;
    if (r != nullptr) {
        auto h = static_cast<GenomeParser::ReferenceGenomeParser *>(r->handle);
        if (h) {
            auto counts = h->get_number_of_base_occurrences();
            if (counts.size() == 4) {
                ret.a = counts[0];
                ret.c = counts[1];
                ret.g = counts[2];
                ret.t = counts[3];
            }
        }
    }
    return ret;
}

void get_base_count_info(ref_gen_parser_t* r, char* s) {
    if (r != nullptr) {
        auto h = static_cast<GenomeParser::ReferenceGenomeParser *>(r->handle);
        if (h) {
            auto counts = h->get_base_count_info();
            strcpy(s, counts.c_str());
        }
    }
}
