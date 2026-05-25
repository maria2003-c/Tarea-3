#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "state.h"

typedef struct PQNode 
{  
  State* state; 
  struct PQNode* next; 
} PQNode;

typedef struct PriorityQueue {
  PQNode* head; 
}PriorityQueue;

PriorityQueue* init_pq();
void pq_insert(PriorityQueue* pq, State* state);
State* pq_pop(PriorityQueue* pq);
int is_pq_empty(PriorityQueue* pq);

#endif