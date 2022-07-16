#ifndef _REFERENCE_GENOME_PARSER_HPP_
#define _REFERENCE_GENOME_PARSER_HPP_

#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace GenomeParser {

class ReferenceGenomeParser {
public:
    explicit ReferenceGenomeParser(const std::string& ref_gen);

    const std::vector<uint64_t>& get_number_of_base_occurrences();

    std::string get_base_pair_count_info();

    std::string get_version_hash();

private:
    std::string m_reference_genome;
    std::vector<uint64_t> m_base_counts;
};

} // end namespace GenomeParser

#endif // _REFERENCE_GENOME_PARSER_HPP_
