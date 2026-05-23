#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "state.h"
#include "maze.h"
#include "stack.h"
#include "queue.h"
#include "priority_queue.h"

void process_solution(char* algo_name, int maze[MAX_N][MAX_N], int N, State* final_state, int iterations, int start_x, int start_y, int target_x, int target_y) {
    printf("\n--- Resultados %s ---\n", algo_name);
    print_maze_with_path(maze, N, final_state, start_x, start_y, target_x, target_y);
    printf("Costo del camino: %d\n", final_state->g);
    printf("Iteraciones: %d\n", iterations);
}

void solve_dfs(int maze[MAX_N][MAX_N], int N, int start_x, int start_y, int target_x, int target_y) {
    return NULL
}

void solve_bfs(int maze[MAX_N][MAX_N], int N, int start_x, int start_y, int target_x, int target_y) {

    return NULL;

}



void solve_astar(int maze[MAX_N][MAX_N], int N, int start_x, int start_y, int target_x, int target_y) {

    return NULL;

}
