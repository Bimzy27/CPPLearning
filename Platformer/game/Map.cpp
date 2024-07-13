#include "Map.h"
#include <Main.h>
#include <raylib.h>

#define GRID_WIDTH 41
#define GRID_HEIGHT 26
#define CELL_SIZE 20

int grid[GRID_WIDTH][GRID_HEIGHT];

Color getMapCellColor(int colorIndex)
{
    switch (colorIndex)
    {
    default:
        return SKYBLUE;
    case 1:
        return DARKBROWN;
    case 2:
        return DARKGREEN;
    }
}

void Map::Initialize()
{
    for (int x = 0; x < GRID_WIDTH; x++) 
    {
        for (int y = 0; y < GRID_HEIGHT; y++) 
        {
            if (y >= GRID_HEIGHT - 3)
            {
                grid[x][y] = 1;
                continue;
            }

            if (y >= GRID_HEIGHT - 4)
            {
                grid[x][y] = 2;
                continue;
            }

            grid[x][y] = 0;
        }
    }
}

void Map::Deinitialize()
{

}

void Map::Update()
{
    for (int x = 0; x < GRID_WIDTH; x++) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            int cellX = x * CELL_SIZE;
            int cellY = y * CELL_SIZE;

            DrawRectangle(cellX, cellY, CELL_SIZE, CELL_SIZE, getMapCellColor(grid[x][y]));
        }
    }
}