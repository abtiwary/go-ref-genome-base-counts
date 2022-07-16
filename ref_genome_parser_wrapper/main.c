#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ref_genome_parser_wrapper.h"

int main() {
    char partial_lambda_virus_genome[] = "GGGCGGCGACCTCGCGGGTTTTCGCTATTTATGAAAATTTTCCGGTTTAAGGCGTTTCCGTTCTTCTTCGTCATAACTTAATGTTTTTATTTAAAATACCCTCTGAAAAGAAAGGAAACGACAGGTGCTGAAAGCGAGGC";
    ref_gen_parser_t* r = ref_gen_parser_create(partial_lambda_virus_genome);

    char version[128];
    get_version(r, version, 128);
    printf("current version of the parser: %s\n", version);

    char count_info[128];
    get_base_count_info(r, count_info);
    printf("base occurrences: %s\n", count_info);

    base_counts_t counts;
    counts = get_number_of_base_occurrences(r);

    ref_gen_parser_destroy(r);

    return 0;
}