#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "state.h"
#include "maze.h"
#include "stack.h"
#include "queue.h"
#include "priority_queue.h"

void process_solution(char* algo_name, int maze[MAX_N][MAX_N], int N, State* final_state, int iterations, int start_x, int start_y, int target_x, int target_y) 
{
    printf("\n--- Resultados %s ---\n", algo_name);
    print_maze_with_path(maze, N, final_state, start_x, start_y, target_x, target_y);
    printf("Costo del camino: %d\n", final_state->g);
    printf("Iteraciones: %d\n", iterations);
}

void solve_dfs(int maze[MAX_N][MAX_N], int N, int start_x, int start_y, int target_x, int target_y) 
{
    int visited[MAX_N][MAX_N] = {0};
    Stack* s = stack_create();
    int iterations = 0;

    State* start = (State*)malloc(sizeof(State));
    start->x = start_x; start->y = start_y; start->g = 0; start->parent = NULL;

    stack_push(s, start);

    while (stack_top(s) != NULL) 
    {
        State* current = (State*)stack_pop(s);
        iterations++;

        if (is_final_state(current, target_x, target_y)) 
        {
            process_solution("DFS", maze, N, current, iterations, start_x, start_y, target_x, target_y);
            stack_clean(s);
            return;
        }

        if (visited[current->x][current->y]) continue;
        visited[current->x][current->y] = 1;

        for (int i = 1; i <= 4; i++) 
        {
            State* next = transition(current, i, maze, N, target_x, target_y);
            if (next != NULL && !visited[next->x][next->y]) {
                stack_push(s, next);
            }
        }
    }
    printf("\nDFS no encontro solucion.\n");
    stack_clean(s);
}

void solve_bfs(int maze[MAX_N][MAX_N], int N, int start_x, int start_y, int target_x, int target_y) 
{
    int visited[MAX_N][MAX_N] = {0};
    Queue* q = queue_create();
    int iterations = 0;

    State* start = (State*)malloc(sizeof(State));
    start->x = start_x; start->y = start_y; start->g = 0; start->parent = NULL;

    queue_insert(q, start);

    while (queue_front(q) != NULL) 
    {
        State* current = (State*)queue_remove(q);
        iterations++;

        if (is_final_state(current, target_x, target_y)) 
        {
            process_solution("BFS", maze, N, current, iterations, start_x, start_y, target_x, target_y);
            queue_clean(q);
            return;
        }

        if (visited[current->x][current->y]) continue;
        visited[current->x][current->y] = 1;

        for (int i = 1; i <= 4; i++) 
        {
            State* next = transition(current, i, maze, N, target_x, target_y);
            if (next != NULL && !visited[next->x][next->y]) {
                queue_insert(q, next);
            }
        }
    }
    printf("\nBFS no encontro solucion.\n");
    queue_clean(q);
}

void solve_astar(int maze[MAX_N][MAX_N], int N, int start_x, int start_y, int target_x, int target_y) 
{
    int visited[MAX_N][MAX_N] = {0};
    PriorityQueue* pq = init_pq();
    int iterations = 0;

    State* start = (State*)malloc(sizeof(State));
    start->x = start_x; start->y = start_y; start->g = 0; 
    start->f = manhattan_distance(start_x, start_y, target_x, target_y); 
    start->parent = NULL;
    pq_insert(pq, start);

    while (!is_pq_empty(pq)) 
    {
        State* current = pq_pop(pq);
        iterations++;

        if (is_final_state(current, target_x, target_y)) 
        {
            process_solution("A*", maze, N, current, iterations, start_x, start_y, target_x, target_y);
            return;
        }

        if (visited[current->x][current->y]) continue;
        visited[current->x][current->y] = 1;

        for (int i = 1; i <= 4; i++) 
        {
            State* next = transition(current, i, maze, N, target_x, target_y);
            if (next != NULL && !visited[next->x][next->y]) {
                pq_insert(pq, next);
            }
        }
    }
    printf("\nA* no encontro solucion.\n");
}