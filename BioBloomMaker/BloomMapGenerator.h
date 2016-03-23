/*
 * BloomMapGenerator.h
 *
 *  Created on: Mar 17, 2016
 *      Author: cjustin
 */

#ifndef BLOOMMAPGENERATOR_H_
#define BLOOMMAPGENERATOR_H_

#include <vector>
#include <string>
#include <stdint.h>
#include <google/dense_hash_map>
#include "bloomfilter/BloomMap.hpp"
#include "bloomfilter/RollingHashIterator.h"
#include "Common/Options.h"

using namespace std;

class BloomMapGenerator {
public:
	explicit BloomMapGenerator(vector<string> const &filenames,
			unsigned kmerSize, unsigned hashNum, size_t numElements);

	void generate(const string &filename, double fpr);

	virtual ~BloomMapGenerator();
private:

	unsigned m_kmerSize;
	unsigned m_hashNum;
	size_t m_expectedEntries;
	size_t m_totalEntries;
	vector<string> m_fileNames;
	google::dense_hash_map<ID,string> m_headerIDs;

	//helper methods
	//TODO: collision detection
	void loadSeq(BloomMap<ID> &bloomMap, const string& seq, ID value) {
		if (seq.size() < m_kmerSize)
			return;
		/* init rolling hash state and compute hash values for first k-mer */
		RollingHashIterator itr(seq, m_hashNum, m_kmerSize);
		while (itr != itr.end()) {
			bloomMap.insert(*itr, value);
			itr++;
		}
	}
};

#endif /* BLOOMMAPGENERATOR_H_ */
