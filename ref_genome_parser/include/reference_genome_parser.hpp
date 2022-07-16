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

    void count_base_occurrences();

    const std::vector<uint64_t>& get_number_of_base_occurrences();

    std::string get_base_count_info();

    std::string get_version_hash();

private:
    bool m_done = false;
    std::map<std::string, uint64_t> m_map_base_counts;
    std::string m_reference_genome;
    std::vector<uint64_t> m_base_counts;
};

} // end namespace GenomeParser

#endif // _REFERENCE_GENOME_PARSER_HPP_
