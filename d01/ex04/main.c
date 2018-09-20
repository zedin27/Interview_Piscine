#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue *elem;
	elem = queueInit();
	printf("%d\n", isEmpty(elem));
	enqueue(elem, "420");
	enqueue(elem, "lit");
	enqueue(elem, "360");
	printf("%s\n", dequeue(elem));
	// printf("%d\n", isEmpty(elem));
	// printf("%s\n", peek(elem));
	// printf("%s\n", dequeue(elem));
	// printf("%d\n", isEmpty(elem));
	return (0);
}



// Function used for the test
// Don't go further :)
