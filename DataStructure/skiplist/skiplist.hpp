#include <vector>

template<class T>
class SkipList
{
	public:
		struct node
		{
			T _val;
			std::vector<node*> _nexts;
			node(const T& val,int level):
			_val(val),_nexts(level,nullptr){}
		};
		SkipList():_dummy(new node(T(),5))
		{

		}
		bool Insert(const T &val);
		bool Search(const T &val)
		{
			int level = _dummy->_nexts.size() - 1;
			node* cur = _dummy;
			while(level >= 0)
			{
				const T& nxt = cur->_nexts[level]->_val;
				if(val > nxt)
				{
					cur = cur->_nexts[level];	//jump
				}
				else if(val < nxt)
				{
					--level;  		// sink
				}
				else
				{
					return true;
				}

			}
		}
		bool Remove(const T &val);

	private:
		node *_dummy;
};