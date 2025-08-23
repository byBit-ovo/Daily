//分组
#include <iostream>
#include <vector>
#include <unordered_map>

bool check(std::unordered_map<int,int>& hash,int a,int m)
{
    int groups = 0;
    for(auto& p: hash)
    {
        int count = p.second;
        groups += (count/a + (count%a==0?0:1));
    }
    return groups <= m;
}

int main()
{
    int n,m; std::cin>>n>>m;
    std::vector<int> style(n);
    int q = 0;
    std::unordered_map<int,int> hash;
    for(int i=0;i<n;++i)
    {
        std::cin>>style[i];
        ++hash[style[i]];
        if( hash[ style[i] ] > q)
        {
            q = hash[style[i]];
        }
    }
    
    int ans = -1;
    for(int i=1;i<=q;++i)
    {
        if(check(hash,i,m))
        {
            ans = i;
            break;
        }
    }

    //二分优化
    int l=1,r=q;
    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(check(hash,mid,m))
        {
            ans = mid;
            r = mid;
        }
        else
        {
            l = mid+1;
        }
    }
    
    
    std::cout<<ans<<std::endl;
    return 0;
}