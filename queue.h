/**
 * William Herrmann
 * Header for queue type and queue functions
 */
#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNodeStruct
{
  int intValue;
  struct QueueNodeStruct *nextNode; 
} QueueNode;

typedef struct QueueStruct
{
  QueueNode *head, *tail;
} Queue;

// Queue Function Prototypes
Queue * newQueue();
void deleteQueue(Queue *q);
void enqueue(int val, Queue *q);
int  dequeue(Queue *q);
int  isEmpty(Queue *q);

#endif
