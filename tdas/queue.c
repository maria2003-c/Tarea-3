#include <stdlib.h>
#include "queue.h"

typedef struct QueueNode {
    void *data;
    struct QueueNode *next;
} QueueNode;


struct Queue {
    QueueNode *front; 
    QueueNode *rear; 
};

Queue *queue_create(void) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    return queue;
}

void queue_insert(Queue *queue, void *data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;

        if (queue->rear == NULL) {
            queue->front = newNode;
            queue->rear = newNode;
        } else {
            queue->rear->next = newNode;
            queue->rear = newNode;
        }
    }
}

void *queue_front(Queue *queue) {
    if (queue->front == NULL) return NULL;
    return queue->front->data;
}


void *queue_remove(Queue *queue) {
    if (queue->front == NULL) return NULL;

    QueueNode *temp = queue->front;
    void *data = temp->data;

    queue->front = queue->front->next;


    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}


void queue_clean(Queue *queue) {
    while (queue->front != NULL) {
        queue_remove(queue);
    }
    free(queue);
}