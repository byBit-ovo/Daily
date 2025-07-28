#include <list>
#include <iostream>


int main()
{
    std::list<int> ls;
    ls.emplace_back(1);
    ls.emplace_back(2);
    ls.emplace_back(3);
    ls.emplace_back(4);
    for(auto iter=ls.begin();iter!=ls.end();++iter)
    {
        std::cout<<*iter<<" ";
    }
    std::cout<<std::endl;
    std::cout<<*ls.rend();
    return 0;
}