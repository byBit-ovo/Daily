#include <vector>
#include "sem.hpp"
#include "mythread.hpp"
static int dftSize = 10;
template<typename T>
class ringQueue
{
public:
    ringQueue(int cap = dftSize):
    _con(cap),_cap(cap),
    _head(0),_tail(0),
    _room(_cap), _data(0)
    {}

    void push(const T& val)
    {
        _room.P(); // apply for room,room - 1 //预定空间,满则休眠,等待消费者room.V()
        {
            lockGuard guard(_clock);//解决多生产者问题
            _con[_tail++] = val;
            _tail %= _cap;
        }
        _data.V(); //add for data  , data + 1 //给出数据
    }
    void pop(T* out)
    {
        _data.P(); // apply for room,room - 1 //预定数据，空则休眠，等待生产者data.V()
        {
            lockGuard guard(_plock);//解决多消费者问题
            *out = _con[_head++];
            _head %= _cap;
        }
        _room.V(); // add for data  , data + 1 //留出空间
    }

private:
    std::vector<T> _con;
    int _cap;
    int _head;
    int _tail;
    sem _room; //解决生产者和消费者之间的互斥同步关系
    sem _data; //解决生产者和消费者之间的互斥同步关系
    mutex _plock;//解决生产者内，消费者内的关系
    mutex _clock;//两把锁让生产者和消费者并发
};