#ifndef SEARCH_H
#define SEARCH_H
#include "config.h"

void solve_dfs(int maze[MAX_N][MAX_N], int N, int start_x, int start_y, int target_x, int target_y);
void solve_bfs(int maze[MAX_N][MAX_N], int N, int start_x, int start_y, int target_x, int target_y);
void solve_astar(int maze[MAX_N][MAX_N], int N, int start_x, int start_y, int target_x, int target_y);

#endif