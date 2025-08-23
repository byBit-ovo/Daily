#include <iostream>
using namespace std;

int main()
{

    int s = 0, l = 0;
    std::string DNA;
    int maxC = 0, curC = 0, len = 0;
    std::cin >> DNA >> len;
    int i = 0, j = 0;

    while(j < DNA.size()) //ensure after last number is added,it is considered
    {
        char c = DNA[j];
        if (c == 'C' || c == 'G')
        {
            ++curC;
        }
        //Start from this line,[i...j] is our real array

        while(j-i+1> len) // 'if' is also optional
        {
            if(DNA[i]=='C' || DNA[i]=='G')
            {
                --curC;
            }
            ++i;
        }

        if(j-i+1==len && curC > maxC)// keep the Max_status in the mind
        {                            // 'j-i+1' is needed
            curC = maxC;
            s = i;
            l = j-i+1;
        }
        ++j;
    }

    std::cout << DNA.substr(s, l) << std::endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
