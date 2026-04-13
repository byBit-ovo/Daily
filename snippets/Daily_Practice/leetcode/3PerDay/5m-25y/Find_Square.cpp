//找出距离n最近的平方数
#include <iostream>
#include <cmath>
using Long = long long;
int main()
{
    double n; std::cin>>n;
    Long a = sqrt(n);
    Long b = a+1;
    
    Long ans = a;
    if(b*b - n < n - a*a)
    {
        ans = b;
    }
    std::cout<<ans*ans<<std::endl;
    return 0;
}