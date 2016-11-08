/**
 * William Herrmann
 * Header for list type and list functions
 */

#ifndef LIST_H
#define LIST_H

#include "queue.h"
#include <stdio.h>
// List Structures

typedef struct ListNodeStruct
{
  char *identifier;
  Queue *queue;
  struct ListNodeStruct *nextNode; 
} ListNode;

typedef struct ListStruct
{
  ListNode *head;
} List;

// Queue Function Prototypes
List * newList();
void deleteList(List *list);
void add(char *str, int line, List *list); //check for existing identifier or add a new node
void print(List *list, FILE *fout);
int  isListEmpty(List *list);

#endif
