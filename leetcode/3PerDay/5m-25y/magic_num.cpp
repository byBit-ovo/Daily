#include <iostream>
#include <cmath>

int hash[100] = {0};

bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(n);++i)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

void load()
{
    for (int i = 2; i < 100;++i)
    {
        if(is_prime(i))
        {
            hash[i] = 1;
        }
    }
}
bool is_magic_number(int num)
{
    std::string q = std::to_string(num);
    int len = q.size();

    for (int i = 0; i < len;++i)
    {
        for (int j = i + 1; j < len;++j)
        {
            int a = q[i]-'0';
            int b = q[j]-'0';
            int possible = a * 10 + b;
            if(possible>10 && hash[possible])
            {
                return true;
            }
            possible = b * 10 + a;

            if(possible>10 && hash[possible])
            {
                return true;
            }

        }
    }
    return false;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    load();
    int ans = 0;
    
    for (int i = a; i <= b; ++i)
        if(is_magic_number(i))
            ++ans;

    std::cout << ans << std::endl;
    return 0;
}