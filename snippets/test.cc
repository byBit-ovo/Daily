// 请实现下面的函数, 中间不能调用其他任何标准库中的函数
// （Returns a pointer to the first occurrence of strSearch in string）.
// 		const char * strstr ( const char * str, const char * strSearch )
// 		{
// 			if(strSearch == nullptr)
// 			{
// 				return str;
// 			}
// 			//在str中找到strSearch
// 			while(str != nullptr)
// 			{
// 				const char* cur1 = str;
// 				const char* cur2 = strSearch;
// 				while(cur1 != nullptr && *cur1 == *cur2)
// 				{
// 					++cur1;	
// 					++cur2;
// 					if(cur2 == nullptr)
// 					{
// 						return str;
// 					}
// 				}
// 				++str;
// 			}
// 			return nullptr;
// 		}

// 	2)假设有从小到大顺序排列，不一定连续但没有重复的整数序列A={a1,a2,a3,…am-1,am,am+1,…,an-1,an}，
// 	将该序列重新排列为B={am,am+1,…an-1,an,a1,a2,…am-1}。试给出一个程序从一个符合B序列的数组中找到a1的位置。要求算法复杂度<O(N)。

// 	//1 2 3 4  5 6 7 8
// 	//5 6 7 8 *1 2 3 4
// 	int find(std::vector<int> &arr)
// 	{
// 		int left=0,right = arr.size() - 1;
// 		while(left < right)
// 		{
// 			int mid = left + (right-left)/2;
// 			if(arr[mid] < arr[0])
// 			{
// 				right = mid;
// 				if(arr[mid-1] > arr[mid])
// 				{
// 					return mid;
// 				}
// 			}
// 			else if(arr[mid] > arr[0])
// 			{
// 				left = mid + 1;
// 			}
// 		}
// 		return -1;
// 	}


// 	class Solution{
// 		public:
// 			Solution():_cache(31,-1){
// 				_cache[1] = 1;
// 				_cache[2] = 1;
// 				_cache[3] = 2;
// 			}
// 			int fib1(int i = 30)
// 			{
// 				if(i <=3){
// 					return _cache[i];
// 				}
// 				if(_cache[i] != -1){
// 					return _cache[i];
// 				}
// 				int ret = fib(i-1) + fib(i-2);
// 				_cache[i] = ret;
// 				return ret;
// 			}
// 			int fib2(int n = 30)
// 			{
// 				int a = 1,b = 1,c = 2;
// 				for(int i=3;i <= n;++i) 
// 				{
// 					c = a + b;
// 					a = b;
// 					b = c;
// 				}
// 				return c;
// 			}
// 		private:
// 			std::vector<int> _cache;
// 	};


	#include <iostream>
using namespace std;

class Base 
{
public:
   int iValue;
   virtual void fun1()
   {
      cout<<"Base fun1"<<endl;
      fun2();
   }

   void fun2 ()
   {
      cout<<"Base fun2"<<endl;
   }
};

class Derived : public Base
{
public:
   char* pValue;
   virtual void fun1()
   {
      cout<<"Derived fun1"<<endl;
      fun2();
      Base::fun1();
   }
   void fun2 ()
   {
      cout<<"Derived fun2"<<endl;
   }
};

class MoreDerived : public Derived
{
public:
   static double dValue;
};


int main(int argc, char* argv[])
{
   cout<<sizeof(Base)<<endl
      <<sizeof(Derived)<<endl
      <<sizeof(MoreDerived)<<endl;

   Derived d;

   Base& rB = d;
   rB.fun1();

   Base* pB = &d;
   pB->fun1();

   return 0;
}