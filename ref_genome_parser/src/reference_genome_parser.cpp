#include "../include/reference_genome_parser.hpp"
#include "../include/version.hpp"

namespace GenomeParser {

ReferenceGenomeParser::ReferenceGenomeParser(const std::string& ref_gen)
    : m_reference_genome(ref_gen)
{
    m_map_base_counts["A"] = 0;
    m_map_base_counts["C"] = 0;
    m_map_base_counts["G"] = 0;
    m_map_base_counts["T"] = 0;

    m_base_counts.resize(4);
    std::fill(m_base_counts.begin(), m_base_counts.end(), 0);
}

void ReferenceGenomeParser::count_base_occurrences() {
    if (!m_done) {
        std::for_each(m_reference_genome.begin(), m_reference_genome.end(), [&](char c) {
            switch (c) {
                case 'A':
                    m_map_base_counts["A"] += 1;
                    break;
                case 'C':
                    m_map_base_counts["C"] += 1;
                    break;
                case 'G':
                    m_map_base_counts["G"] += 1;
                    break;
                case 'T':
                    m_map_base_counts["T"] += 1;
                    break;
                default:
                    break;
            }
        });

        int idx = 0;
        for(auto it = m_map_base_counts.begin(); it != m_map_base_counts.end(); it++) {
            m_base_counts[idx] = it->second;
            idx += 1;
        }

        m_done = true;
    }
}

const std::vector<uint64_t>&
ReferenceGenomeParser::get_number_of_base_occurrences() {
    count_base_occurrences();
    return m_base_counts;
}

std::string
ReferenceGenomeParser::get_base_count_info() {
    count_base_occurrences();
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
