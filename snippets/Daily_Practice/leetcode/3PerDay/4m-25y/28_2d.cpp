#include <iostream>
using namespace std;

bool Helper(string s1, string s2)
{
    int hash1[26] = {0};
    int hash2[26] = {0};
    for (auto e : s1)
        ++hash1[e - 'A'];
    for (auto e : s2)
        ++hash2[e - 'A'];
    int i = 0;
    for (; i < 26; ++i)
    {
        if (hash1[i] < hash2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    std::string s1, s2;
    while (cin >> s1 >> s2)
    {
        if (Helper(s1, s2))
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")