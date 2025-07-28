#include "hash.h"
#include "unordered_Map.h"
#include "unordered_Set.h"
#include <unordered_map>
#include<stack>

int main(){
    unordered_Map<int, int> hash;
    hash.insert(std::pair<int, int>(1e6, 1));

    std::cout << hash.bucket_size() << std::endl;
    return 0;
}