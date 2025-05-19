#include "Stack.h"
#include "MyQueue.h"
int main()
{
	MyQueue* qu = myQueueCreate();
	myQueuePush(qu, 1);
	myQueuePush(qu, 2);
	myQueuePush(qu, 3);
	myQueuePush(qu, 4);

	while (!myQueueEmpty(qu))
	{
		printf("%d ", myQueuePop(qu));
	}
}