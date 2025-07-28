#include"processPool.hpp"
#include "task.hpp"

int main(int argc,char* argv[]){
    if(!checkArg(argc)){
        std::cout << "example: bin num" << std::endl;
        exit(0);
    }
    Pool pool(argv[1]);
    pool.dispatchTask(10);
    return 0;
}