#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;

Queue *queue_create(void);
void queue_insert(Queue *queue, void *data);
void *queue_remove(Queue *queue);
void *queue_front(Queue *queue);
void queue_clean(Queue *queue);

#endif