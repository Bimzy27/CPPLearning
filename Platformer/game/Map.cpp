#include "Map.h"
#include <Main.h>
#include <raylib.h>
#include <stdio.h>


#define MAP_WIDTH GRID_WIDTH * 3
#define MAP_WIDTH_OFFSET GRID_WIDTH * 1.5f * CELL_SIZE

int grid[MAP_WIDTH][GRID_HEIGHT];

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
    case 3:
        return CLITERAL(Color) { 0, 100, 44, 255 };
    }
}

void Map::Initialize()
{
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < GRID_HEIGHT; y++) 
        {
            if (y >= GRID_HEIGHT - 3)
            {
                grid[x][y] = 1;
                continue;
            }

            if (y >= GRID_HEIGHT - 4) // Green
            {
                grid[x][y] = x % 3 == 0 ? 3 : 2;
                continue;
            }

            grid[x][y] = 0;

            if (y == 0)
            {
                int cellX = (x + 0.5f) * CELL_SIZE - MAP_WIDTH_OFFSET;
                printf("Map %d: %d\n", x, cellX);
            }
        }
    }
}

void Map::Deinitialize()
{

}

void Map::Update()
{
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            int cellX = (x + 0.5f) * CELL_SIZE - MAP_WIDTH_OFFSET;
            int cellY = y * CELL_SIZE;

            DrawRectangle(cellX, cellY, CELL_SIZE, CELL_SIZE, getMapCellColor(grid[x][y]));
        }
    }
}