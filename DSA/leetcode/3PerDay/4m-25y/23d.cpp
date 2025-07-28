#include <iostream>
#include <string>
#include <cstring>
int main()
{
    int n;std::cin>>n;
    std::string str; std::cin>>str;
    std::string contain(n,0);
    int hash[26]={0};
    memset(hash,0,26);
    int maxpos = 0;
    
    for(int i=0;i<n;++i)
    {
        ++hash[str[i]-'a'];
        if(hash[str[i]-'a'] > hash[maxpos])
        {
            maxpos = str[i]-'a';
        }
    }
    
    if(hash[maxpos] > (n+1)/2)
    {
        std::cout<<"no"<<std::endl;
    }
    else
    {
        int i = 0;
        while(hash[maxpos]--)
        {
            contain[i] = maxpos + 'a';
            i+=2;
        }
        for(int j = 0; j < 26;++j)
        {
            while(j!=maxpos && hash[j]--)   //为什么j!=maxpos必须要加
            {
                if(i >= n)
                {
                    i=1;
                }
                contain[i] = j + 'a';
                i+=2;
                
            }
        }
        std::cout<<"yes\n"<<contain<<std::endl;
        
    }
    return 0;
}