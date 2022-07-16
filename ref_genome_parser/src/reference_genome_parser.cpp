#include "../include/reference_genome_parser.hpp"
#include "../include/version.hpp"

namespace GenomeParser {

ReferenceGenomeParser::ReferenceGenomeParser(const std::string& ref_gen)
    : m_reference_genome(ref_gen)
{}

const std::vector<uint64_t>&
ReferenceGenomeParser::get_number_of_base_occurrences() {
    std::map<std::string, uint64_t> map_base_counts;
    map_base_counts["A"] = 0;
    map_base_counts["C"] = 0;
    map_base_counts["G"] = 0;
    map_base_counts["T"] = 0;

    std::for_each(m_reference_genome.begin(), m_reference_genome.end(), [&](char c) {
        switch (c) {
            case 'A':
                map_base_counts["A"] += 1;
                break;
            case 'C':
                map_base_counts["C"] += 1;
                break;
            case 'G':
                map_base_counts["G"] += 1;
                break;
            case 'T':
                map_base_counts["T"] += 1;
                break;
            default:
                break;
        }
    });

    m_base_counts.clear();
    std::for_each(map_base_counts.begin(), map_base_counts.end(), [&](const auto& pair) {
        m_base_counts.push_back(pair.second);
    });

    return m_base_counts;
}

std::string
ReferenceGenomeParser::get_base_pair_count_info() {
    if (m_base_counts.size() != 4) return std::move(std::string(""));
    std::stringstream ss;
    ss << "A: " << m_base_counts[0]
       << ", C: " << m_base_counts[1]
       << ", G: " << m_base_counts[2]
       << ", T: " << m_base_counts[3];

    auto s = ss.str();
    return s;
}

std::string
ReferenceGenomeParser::get_version_hash() {
    return GIT_HASH;
}


} // end namespace GenomeParser
