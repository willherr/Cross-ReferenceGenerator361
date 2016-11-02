/**
 * William Herrmann
 * Header for queue type and queue functions
 */
#ifndef queue
#define queue

// Queue Structure

typedef struct QueueNodeStruct
{
  int intValue;
  struct QueueStruct *nextNode; 
} QueueNode;

typedef struct QueueStruct
{
  QueueNode *head, *tail;
} Queue;

// Queue Function Prototypes
Queue * newQueue();
void deleteQueue(Queue *q);
void enequeue(int val, Queue *q);
int  dequeue(Queue *q);
int  isEmpty(Queue *q);


#endif
