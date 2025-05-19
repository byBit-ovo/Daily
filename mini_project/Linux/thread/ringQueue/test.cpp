#include "ringQueue.hpp"
ringQueue<int> superMarket;
void produce()
{
    int data = 0;
    while (true)
    {
        superMarket.push(data);
        ++data;
        sleep(1);
    }
}

void consume()
{
    int data = 0;
    sleep(3);
    while (true)
    {
        superMarket.pop(&data);
        std::cout << "consume a data: " << data << std::endl;
    }
}
int main()
{
    std::vector<myThread> producers;
    std::vector<myThread> consumers;
    for (int i = 0; i < 1; ++i)
        producers.emplace_back(produce);

    for (int i = 0; i < 3; ++i)
        consumers.emplace_back(consume);

    for (auto &e : producers)
        e.start();
    for (auto &e : consumers)
        e.start();

    for (auto &e : producers)
        e.join();
    for (auto &e : consumers)
        e.join();
    return 0;
}