#include "thread.hpp"
#include <queue>


template<typename T>
class blockQueue{
public:
    void push(const T& val)
    {
        // _lock.lock();
        lockGuard lock(_lock);
        while (isFull())
        {
            std::cout << "Queue is full,waiting consumer..." << std::endl;
            _consumer_cond.wait(_lock);
        }
        _con.push(val);
        _producer_cond.signal();
        // _lock.unlock();

    }
    void pop(T* out)
    {
        // _lock.lock();
        lockGuard lock(_lock);
        while(isEmpty())
        {
            std::cout << "Queue is empty,waiting producer..." << std::endl;
            _producer_cond.wait(_lock);
        }

        *out = _con.front();
        _con.pop();
        _consumer_cond.signal();
        // _lock.unlock();
    }

    blockQueue(int capacity = 10):_capacity(capacity){}
    ~blockQueue(){}

private:
    bool isEmpty() { return _con.empty(); }
    bool isFull() { return _con.size() == _capacity; }
    mutex _lock;
    condition _consumer_cond;
    condition _producer_cond;
    std::queue<T> _con;
    int _capacity;
};

// template<typename T>
// class blockQueue{
// public:
//     void push(const T& val)
//     {
//         // pthread_mutex_lock(&_lock);
//         _lock.lock();

//         while(isFull())
//         {
//             std::cout << "Queue is full,waiting consumer..." << std::endl;
//             // pthread_cond_wait(&_producer_cond, &_lock);
//             _consumer_cond.wait(_lock);
//         }
//         // std::cout << "producer is awake !" << std::endl;
//         _con.push(val);
//         _producer_cond.signal();
//         _lock.unlock();
//         // pthread_cond_signal(&_consumer_cond);
//         // pthread_mutex_unlock(&_lock);
//     }

//     void pop(T* out)
//     {
//         // pthread_mutex_lock(&_lock);
//         _lock.lock();

//         while(isEmpty())
//         {
//             std::cout << "Queue is empty,waiting producer..." << std::endl;
//             // pthread_cond_wait(&_consumer_cond, &_lock);
//             _producer_cond.wait(_lock);
//         }

//         // std::cout << "consumer is awake !" << std::endl;
//         *out = _con.front();
//         _con.pop();
//         _consumer_cond.signal();
//         _lock.unlock();
//         // pthread_cond_signal(&_producer_cond);
//         // pthread_mutex_unlock(&_lock);
//     }

//     blockQueue(int capacity = 10) 
//     :_lock(),_consumer_cond(),_producer_cond(),_capacity(capacity)
//     {
//         // pthread_mutex_init(&_lock, nullptr);
//         // pthread_cond_init(&_consumer_cond, nullptr);
//         // pthread_cond_init(&_producer_cond, nullptr);
//     }
//     ~blockQueue()
//     {
//         // pthread_mutex_destroy(&_lock);
//         // pthread_cond_destroy(&_consumer_cond);
//         // pthread_cond_destroy(&_producer_cond);  
//     }

// private:
//     bool isEmpty() { return _con.empty(); }
//     bool isFull() { return _con.size() == _capacity; }
//     // pthread_mutex_t _lock;
//     // pthread_cond_t _consumer_cond;
//     // pthread_cond_t _producer_cond;
//     mutex _lock;
//     condition _consumer_cond;
//     condition _producer_cond;
//     std::queue<T> _con;
//     int _capacity;
// };