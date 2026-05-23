#ifndef STATE_H
#define STATE_H
#include "config.h"

typedef struct State {
    int x;
    int y;
    int g; 
    int f; 
    struct State* parent;
} State;

int is_final_state(State* state, int target_x, int target_y);
State* transition(State* current, int action, int maze[MAX_N][MAX_N], int N, int target_x, int target_y);
int manhattan_distance(int x, int y, int target_x, int target_y);

#endif