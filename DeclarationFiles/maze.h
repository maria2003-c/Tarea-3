#ifndef MAZE_H
#define MAZE_H

#include "config.h"

struct State; 

void generate_maze(int maze[MAX_N][MAX_N], int N, int difficulty, int start_x, int start_y, int target_x, int target_y);
void print_maze_with_path(int maze[MAX_N][MAX_N], int N, struct State* final_state, int start_x, int start_y, int target_x, int target_y);

#endif