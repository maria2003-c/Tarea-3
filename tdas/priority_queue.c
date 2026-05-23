#include <stdlib.h>
#include "priority_queue.h"

PriorityQueue* init_pq() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->head = NULL; return pq;
}

void pq_insert(PriorityQueue* pq, State* state) {
    PQNode* node = (PQNode*)malloc(sizeof(PQNode));
    node->state = state;
    if (pq->head == NULL || pq->head->state->f >= state->f) {
        node->next = pq->head; pq->head = node;
    } else {
        PQNode* curr = pq->head;
        while (curr->next != NULL && curr->next->state->f < state->f) curr = curr->next;
        node->next = curr->next; curr->next = node;
    }
}

State* pq_pop(PriorityQueue* pq) {
    if (is_pq_empty(pq)) return NULL;
    PQNode* temp = pq->head; State* state = temp->state;
    pq->head = pq->head->next; free(temp); return state;
}

int is_pq_empty(PriorityQueue* pq) { 
    return pq->head == NULL; 
}