/**
 * William Herrmann
 * Implementation of the queue
 */
#include "queue.h"
#include <stdlib.h>

/*
 * newQueue() creates and initializes a queue to an empty queue
 */
Queue * newQueue()
{
  Queue *q = (Queue*) malloc(sizeof(Queue));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

/*
 * deleteQueue() clears the queue
 */
void deleteQueue(Queue *q)
{
  QueueNode *temp;

  q->tail = NULL;
  while(q->head != NULL)
  {
    temp = q->head;
    q->head = q->head->nextNode;
    free(temp);
  }

  free(q);
}

/*
 * enqueue() adds an item to the end of the queue
 */
void enequeue(int val, Queue *q)
{
  QueueNode *temp;
  temp = (QueueNode*) malloc(sizeof(QueueNode));
  temp->intValue = val;
  temp->nextNode = NULL;

  if(isEmpty(q))
    q->head = q->tail = temp;
  else
  {
    q->tail->nextNode = temp;
    q->tail = temp;
  }
}

/*
 * dequeue() removes the first node of the queue and returns its value
 */
int dequeue(Queue *q)
{
  int result;
  QueueNode *temp;
  
  if(isEmpty(q))
    result = 0;
  else
  {
    result = q->head->intValue;
    temp = q->head;
    q->head = q->head->nextNode;
    free(temp);
    
    if(isEmpty(q))
      q->tail = NULL;
  }
  return result;
}

/*
 * isEmpty() returns true if the queue is empty (head is NULL)
 */
int isEmpty(Queue *q){
  return q->head == NULL;
}
