/**
 * William Herrmann
 * Implementation of the queue
 */
#include "queue.h"

/*
 * newQueue() creates and initializes a queue to an empty queue
 */
Queue * newQueue()
{
  Queue *q = (Queue*) malloc(sizeof(Queue));
  return q;
}

/*
 * deleteQueue() clears the queue
 */
void deleteQueue(Queue *q)
{
  queueNode *temp;

  q->tail = NULL;
  while(q->head != NULL)
  {
    temp = q->head;
    q->head = q->head->next;
    free(temp);
  }

  free(q);
}

/*
 * enqueue() adds an item to the end of the queue
 */
void enequeue(int val, Queue *q)
{
  queueNode *temp;
  temp = (queueNode*) malloc(sizeof(queueNode));
  temp->intValue = val;
  temp->next = NULL;

  if(isEmpty(q))
    q->head = q->tail = temp;
  else
  {
    q->tail->next = temp;
    q->tail = temp;
  }
}

/*
 * dequeue() removes the first node of the queue and returns its value
 */
int dequeue(Queue *q)
{
  int result;
  queueNode *temp;
  
  if(isEmpty(q))
    result = 0;
  else
  {
    result = q->head->intValue;
    temp = q->head;
    q->head = q->head->next;
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