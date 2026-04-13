#include <iostream>
using namespace std;

int main(int argc,char* argv[],char* env[]){
    for(int i=0;env[i];++i)
        cout<<env[i]<<endl;
    return 0;
}
