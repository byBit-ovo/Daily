#include <vector>

template<size_t N>
class BitSet
{
	public:
		BitSet():_bits(N / 32 + 1){}
		void Set(size_t pos)
		{
			_bits[pos/32] |= (1 << (pos%32));
		}
		void ReSet(size_t pos)
		{
			_bits[pos/32] &= (~(1 << (pos%32)));
		}
		bool IsSet(size_t pos) 
		{
			return ( _bits[pos/32] & (1 << (pos%32)) );
		}
	private:
		std::vector<int> _bits; 
};