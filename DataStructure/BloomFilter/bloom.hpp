#include "hashFunc.hpp"
#include "bitSet.hpp"
#include <string>
//预计插入N个值，根据大量计算，开(4~5)*N 个位置效率比较好
template<size_t N,class T= std::string,class Hash1=BKDRHash,class Hash2 = APHash,class Hash3 = DJBHash>
class BloomFilter
{
	public:
		void Set(const T& key)
		{
			size_t pos1 = _hash1(key) % (N*5);
			size_t pos2 = _hash2(key) % (N*5);
			size_t pos3 = _hash3(key) % (N*5);
			_bitset.Set(pos1);
			_bitset.Set(pos2);
			_bitset.Set(pos3);
		}

		bool IsSet(const T& key)
		{
			size_t pos1 = _hash1(key) % (N*5);
			size_t pos2 = _hash2(key) % (N*5);
			size_t pos3 = _hash3(key) % (N*5);
			if (!_bitset.IsSet(pos1)) return false;
			if (!_bitset.IsSet(pos2)) return false;
			if (!_bitset.IsSet(pos3)) return false;
			// 所有位都设置了，（可能有误判）
			return true;
		}
	private:
	BitSet<N * 5> _bitset;
	Hash1 _hash1;
	Hash2 _hash2;
	Hash3 _hash3;
};