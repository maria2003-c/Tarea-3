#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "maze.h"
#include "search.h"

int main() {
    int maze[MAX_N][MAX_N];

    int N, difficulty, start_x, start_y, target_x, target_y;

    printf("Ingrese el tamaño del laberinto (maximo 50): \n");
    scanf("%d", &N);
    
    if (N > MAX_N) N = MAX_N;

    printf("Ingrese la dificultad (0-100): ");
    scanf("%d", &difficulty);

    printf("Ingrese coordenada X de INICIO (0 a %d): ", N - 1);
    scanf("%d", &start_x);
    
    printf("Ingrese coordenada Y de INICIO (0 a %d): ", N - 1);
    scanf("%d", &start_y);

    printf("Ingrese coordenada X de META (0 a %d): ", N - 1);
    scanf("%d", &target_x);
    printf("Ingrese coordenada Y de META (0 a %d): ", N - 1);
    scanf("%d", &target_y);

    if (start_x < 0 || start_x >= N || start_y < 0 || start_y >= N ||
        target_x < 0 || target_x >= N || target_y < 0 || target_y >= N) {
        printf("Error: Coordenadas fuera de los limites permitidos.\n");
        return 1;
    }

    printf("\nGenerando laberinto N=%d con dificultad %d...\n", N, difficulty);
    generate_maze(maze, N, difficulty, start_x, start_y, target_x, target_y);

    solve_dfs(maze, N, start_x, start_y, target_x, target_y);
    solve_bfs(maze, N, start_x, start_y, target_x, target_y);
    solve_astar(maze, N, start_x, start_y, target_x, target_y);

    return 0;
}