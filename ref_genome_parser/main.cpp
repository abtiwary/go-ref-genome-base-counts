#include <iostream>
#include <string>
#include <vector>

#include "include/reference_genome_parser.hpp"

int main() {
    std::string ref_genome = "GGGCGGCGACCTCGCGGGTTTTCGCTATTTATGAAAATTTTCCGGTTTAAGGCGTTTCCGTTCTTCTTCGTCATAACTTAATGTTTTTATTTAAAATACCCTCTGAAAAGAAAGGAAACGACAGGTGCTGAAAGCGAGGC";

    GenomeParser::ReferenceGenomeParser parser{ref_genome};
    auto counts = parser.get_number_of_base_occurrences();

    std::cout << parser.get_base_count_info() << '\n';

    std::cout << "This version: " << parser.get_version_hash() << '\n';

    auto s1 = "sentence";
    auto s2 = "insolent";
    auto lcs = parser.get_longest_common_subsequence(s1, s2);

    return 0;
}