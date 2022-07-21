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

std::string
ReferenceGenomeParser::get_longest_common_subsequence(
        const std::string& s1,
        const std::string& s2)
{
    if (s1.empty() || s2.empty()) {
        return "";
    }
    // initialize the memoizer
    auto memoizer = std::vector<std::vector<int>>( s1.size()+1, std::vector<int>(s2.size()+1, 0));
    auto rows = s1.size()+1;
    auto cols = s2.size()+1;
    // build the memoizer matrix
    for (auto i=1; i < rows; i++) {
        for (auto j=1; j < cols; j++) {
            if (s1[i-1] == s2[j-1]) {
                memoizer[i][j] = memoizer[i-1][j-1] + 1;
            } else {
                memoizer[i][j] = std::max(memoizer[i-1][j], memoizer[i][j-1]);
            }
        }
    }

    auto total_lcs_chars = memoizer[rows-1][cols-1];
    std::string lcs;
    lcs.resize(total_lcs_chars);

    // bottom up
    auto chars = total_lcs_chars;
    auto row = rows-1;
    auto col = cols-1;
    while(chars > 0) {
        if (memoizer[row-1][col] != memoizer[row][col-1]) {
            if (memoizer[row-1][col] > memoizer[row][col-1]) {
                row = row - 1;
            } else {
                col = col - 1;
            }
        } else {
            // diagonal
            lcs[chars - 1] = s1[row-1];
            chars = chars - 1;
            row = row - 1;
            col = col - 1;
        }
    }

    return lcs;
}


} // end namespace GenomeParser
