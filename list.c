/**
 * William Herrmann
 * Header for queue type and queue functions
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue Function Prototypes
List * newList()
{
  List *list = (List*) malloc(sizeof(List));
  list->head = NULL;
  return list;
}

void deleteList(List *list)
{
  ListNode *temp;

  while(list->head != NULL)
  {
    temp = list->head;
    list->head = list->head->nextNode;
    deleteQueue(temp->queue);
    free(temp);
  }  
  free(list);
}

void add(char *strr, int line, List *list) //check for existing identifier or add a new node
{
  ListNode *temp =  list->head;
  ListNode *newNode;
  char *str = (char *) malloc(sizeof(char)*128);
  strcpy(str, strr);

  if(isListEmpty(list)){
    newNode = (ListNode*) malloc(sizeof(ListNode));
    list->head = newNode;
    newNode->identifier = str;
    newNode->queue = newQueue();
    enqueue(line, newNode->queue);
  } else {
    do{
      if(strcmp(temp->identifier,str) == 0){//found a matching identifier
	enqueue(line, temp->queue);
	return; //return after enqueuing
      }
      if(temp->nextNode == NULL)//no matching identifiers
	break;
      temp = temp->nextNode;
    } while(1);

    //no matching identifiers section
    newNode = (ListNode*) malloc(sizeof(ListNode));
    temp->nextNode = newNode;
    newNode->identifier = str;
    newNode->queue = newQueue();
    newNode->nextNode = NULL;
    enqueue(line, newNode->queue);
  }  
}


void print(List *list, FILE *fout)
{
  if(isListEmpty(list))
    fprintf(fout,"There are no identifiers.\n");
  else
  {
    ListNode *current = list->head;
    while(current != NULL)
    {
      fprintf(fout,"Identifier: %s\n", current->identifier);
      fprintf(fout,"Line Numbers: ");
      while(!isEmpty(current->queue)){
	fprintf(fout,"%d ",dequeue(current->queue));
      }
      fprintf(fout,"\n\n");
      current = current->nextNode;
    }
  }
}

int isListEmpty(List *list)
{
  return list->head == NULL;
}
