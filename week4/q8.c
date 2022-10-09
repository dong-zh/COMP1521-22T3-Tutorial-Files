// A topographic map!
// This helpful tool will tell explorers how much they need to climb to
// reach various points of interest.
// Given an array of points, `my_points`, it can look up individual cells
// in the 2D map and print their height.

#include <stdio.h>

#define MAP_SIZE 5
#define N_POINTS 4

// 2D representation of a point, stored as a single struct
struct point2D {
    int row;
    int col;
} typedef point2D_t;

// 2D grid representing the height data for an area.
int topography_grid[MAP_SIZE][MAP_SIZE] = {
    {0, 1, 1, 2, 3},
    {1, 1, 2, 3, 4},
    {1, 2, 3, 5, 7},
    {3, 3, 4, 5, 6},
    {3, 4, 5, 6, 7},
};

// Points of interest to print heights for, as a 1D array.
point2D_t my_points[N_POINTS] = {
    {1, 2},
    {2, 3},
    {0, 0},
    {4, 4},
};

int main() {
    // Loop over all elements, and print their data
    for (int i = 0; i < N_POINTS; i++) {
        int row = my_points[i].row;
        int col = my_points[i].col;
        int height = topography_grid[row][col];
        printf("Height at %d,%d=%d\n", row, col, height);
    }
    return 0;
}


if (prime[i])

if (prime[i] != 0)
