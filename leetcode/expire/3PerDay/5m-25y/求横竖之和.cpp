#include <iostream>
#include <vector>
using namespace std;
using Long = long long;
int main()
{
    int n,m; cin>>n>>m;
    vector<vector<Long>> matrix(n,vector<Long>(m,0));
    vector<Long> row(n);
    vector<Long> col(m);
    
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>matrix[i][j];
    
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            row[i] += matrix[i][j]; 
    }
    
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            col[i] += matrix[j][i];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<row[i]+col[j]-matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}