#include "cycle_queue.h"
int main()
{
	MyCircularQueue* qu = myCircularQueueCreate(5);
	myCircularQueueEnQueue(qu, 1);
	myCircularQueueEnQueue(qu, 2);
	myCircularQueueEnQueue(qu, 3);
	myCircularQueueEnQueue(qu, 4);
	while (!myCircularQueueIsEmpty(qu))
	{
		printf("%d ", myCircularQueueFront(qu));
		myCircularQueueDeQueue(qu);
	}

}