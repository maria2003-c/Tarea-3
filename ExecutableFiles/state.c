#include <stdlib.h>
#include <math.h>
#include "state.h"

int is_final_state(State* state, int target_x, int target_y) 
{
    return (state->x == target_x && state->y == target_y);
}

int manhattan_distance(int x, int y, int target_x, int target_y) 
{
    return abs(x - target_x) + abs(y - target_y);
}

State* transition(State* current, int action, int maze[MAX_N][MAX_N], int N, int target_x, int target_y) 
{
    int nx = current->x, ny = current->y;
    if (action == 1) nx--;
    else if (action == 2) nx++;
    else if (action == 3) ny--;
    else if (action == 4) ny++;

    if (nx < 0 || nx >= N || ny < 0 || ny >= N || maze[nx][ny] == 1) return NULL;

    State* next_state = (State*)malloc(sizeof(State));
    next_state->x = nx;
    next_state->y = ny;
    next_state->g = current->g + 1;
    next_state->f = next_state->g + manhattan_distance(nx, ny, target_x, target_y);
    next_state->parent = current;

    return next_state;
}