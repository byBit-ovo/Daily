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
		bool Insert(const T &val)
		{
			//record prev pointer when traversing backwards
			std::vector<node*> prevs(_maxLevel,_dummy);
			

		}
		bool Search(const T &target)
		{
			//higher the level is, further it can jump 
			int level = _dummy->_nexts.size() - 1;
			node* cur = _dummy;
			while(level >= 0)
			{
				auto &next = cur->_nexts[level];
				if(next == nullptr || next->_val > target)
				{
					--level;
				}
				else if(next->_val < target)
				{
					cur = next;
				}
				else
				{
					return true;
				}
				
			}
			return false;
		}
		bool Remove(const T &val);

	private:
		node *_dummy;
		int _maxLevel = 5;
};