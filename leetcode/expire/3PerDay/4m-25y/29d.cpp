#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Long = long long;
int main()
{
    int n; cin>>n;
    vector<Long> s(3*n, 0);

    for (int i = 0;i<3*n;++i)
    {
        cin >> s[i];
    }
    sort(s.begin(),s.end());
    Long ans = 0;

    for (int i = 0, j = 3*n - 1; i < j;--j,++i)
    {
        ans += s[--j];
    }
    cout << ans;
    return 0;
}