#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"
#include "state.h"

static void build_safe_path(int x, int y, int target_x, int target_y, int safe[MAX_N][MAX_N], int visited[MAX_N][MAX_N], int N) {
    safe[x][y] = 1; visited[x][y] = 1;
    if (x == target_x && y == target_y) return;

    int dx = (target_x > x) ? 1 : ((target_x < x) ? -1 : 0);
    int dy = (target_y > y) ? 1 : ((target_y < y) ? -1 : 0);

    if (dx != 0 && dy != 0) {
        if (rand() % 2 == 0) build_safe_path(x + dx, y, target_x, target_y, safe, visited, N);
        else build_safe_path(x, y + dy, target_x, target_y, safe, visited, N);
    } else if (dx != 0) {
        build_safe_path(x + dx, y, target_x, target_y, safe, visited, N);
    } else if (dy != 0) {
        build_safe_path(x, y + dy, target_x, target_y, safe, visited, N);
    }
}

void generate_maze(int maze[MAX_N][MAX_N], int N, int difficulty, int start_x, int start_y, int target_x, int target_y) {
    int safe[MAX_N][MAX_N] = {0};
    int visited[MAX_N][MAX_N] = {0};

    build_safe_path(start_x, start_y, target_x, target_y, safe, visited, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (safe[i][j] == 1) {
                maze[i][j] = 0; 
            } else {
                int r = rand() % 100;
                if (r < difficulty) {
                    maze[i][j] = 1; 
                } else {
                    maze[i][j] = 0; 
                }
            }
        }
    }
}

void print_maze_with_path(int maze[MAX_N][MAX_N], int N, State* final_state, int start_x, int start_y, int target_x, int target_y) {
    char visual[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) visual[i][j] = maze[i][j] == 1 ? '#' : '.';
    }

    State* current = final_state;
    while (current != NULL) {
        visual[current->x][current->y] = '+';
        current = current->parent;
    }
    visual[start_x][start_y] = 'I'; 
    visual[target_x][target_y] = 'M';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%c ", visual[i][j]);
        printf("\n");
    }
}