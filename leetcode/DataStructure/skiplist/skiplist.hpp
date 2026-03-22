#include <vector>
#include <time.h>
#include <stdlib.h>
template <class T>
class SkipList
{
public:
	struct node
	{
		T _val;
		std::vector<node *> _nexts;
		node(const T &val, int level) : _val(val), _nexts(level, nullptr) {}
	};
	SkipList(int level) : _dummy(new node(T(), level))
	{
		srand(time(0));
	}
	bool Insert(const T &target)
	{
		// record prev pointers when traversing backwards
		std::vector<node *> prevs;
		if (Search(target, &prevs) == true)
		{
			return false;
		}
		int cur_level = RandomLevel();
		if (cur_level > _maxLevel)
		{
			_maxLevel = cur_level;
			_dummy->_nexts.resize(_maxLevel, nullptr);
		}
		node *newNode = new node(target, cur_level);
		for (int i = 0; i < cur_level; ++i)
		{
			newNode->_nexts[i] = prevs[i]->_nexts[i];
			prevs[i]->_nexts[i] = newNode;
		}
		return true;
	}
	int RandomLevel()
	{
		int level = 1;
		while (rand() < RAND_MAX * _probability && level < _maxLevel)
		{
			++level;
		}
		return level;
	}
	bool Search(const T &target, std::vector<node *> *out = nullptr)
	{
		// higher the level is, further it can jump
		int level = _dummy->_nexts.size() - 1;
		node *cur = _dummy;
		std::vector<node *> prevs(_maxLevel, _dummy);
		while (level >= 0)
		{
			auto &next = cur->_nexts[level];
			if (next == nullptr || next->_val > target)
			{
				prevs[level] = cur;
				--level;
			}
			else if (next->_val < target)
			{
				cur = next;
			}
			else
			{
				if (out != nullptr)
				{
					*out = prevs;
				}
				return true;
			}
		}
		return false;
	}
	bool Remove(const T &val)
	{
		std::vector<node *> prevs;
		if (Search(target, &prevs) == false)
		{
			return false;
		}
		if (prevs[0]->_nexts[0] == nullptr || prevs[0]->_nexts[0]->_val != num)
		{
			return false;
		}
		node *waste = prevs[0]->_nexts[0];
		for (int i = 0; i < waste->_nexts.size(); ++i)
		{
			prevs[i]->_nexts[i] = waste->_nexts[i];
		}
		delete waste;

		// 如果删除最高层节点，把头节点的层数也降一下
		int i = _dummy->_nextV.size() - 1;
		while (i >= 0)
		{
			if (_dummy->_nextV[i] == nullptr)
				--i;
			else 
				break;
			
		}
		_dummy->_nexts.resize(i + 1) 
		return true;
	}

private:
	node *_dummy;
	int _maxLevel = 5;
	double _probability = 0.5;
};