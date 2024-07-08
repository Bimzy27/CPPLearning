/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"
#include <time.h>
#include <stdlib.h>

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
int direction = 0;
int prevBlockDirection = -1;
int playerLength = 1;
int playerCoordX[4096];
int playerCoordY[4096];
Color playerColors[10];

Vector2 pickupCoord;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;

    playerCoordX[0] = gridWidth / 2;
    playerCoordY[0] = gridHeight / 2;
    playerColors[0] = RED;
    playerColors[1] = ORANGE;
    playerColors[2] = YELLOW;
    playerColors[3] = GREEN;
    playerColors[4] = SKYBLUE;
    playerColors[5] = BLUE;
    playerColors[6] = DARKBLUE;
    playerColors[7] = DARKPURPLE;
    playerColors[8] = PURPLE;
    playerColors[9] = PINK;

    pickupCoord.x = playerCoordX[0] + 15;
    pickupCoord.y = playerCoordY[0];

    srand(time(NULL));
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    framesCounter += 1;

    // User Input
    if (IsKeyDown(KEY_RIGHT))
    {
        if (playerLength == 1 || playerCoordX[0] >= playerCoordX[1])
        {
            direction = 0;
        }
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        if (playerLength == 1 || playerCoordX[0] <= playerCoordX[1])
        {
            direction = 1;
        }
    }
    else if (IsKeyDown(KEY_UP))
    {
        if (playerLength == 1 || playerCoordY[0] <= playerCoordY[1])
        {
            direction = 2;
        }
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        if (playerLength == 1 || playerCoordY[0] >= playerCoordY[1])
        {
            direction = 3;
        }
    }

    // Movement
    if (framesCounter % 15 == 0)
    {
        for (size_t i = 0; i < playerLength - 1; i++)
        {
            playerCoordX[playerLength - i - 1] = playerCoordX[playerLength - i - 2];
            playerCoordY[playerLength - i - 1] = playerCoordY[playerLength - i - 2];
        }

        switch (direction)
        {
            case 0:
            default:
                playerCoordX[0] += 1;
                break;
            case 1:
                playerCoordX[0] -= 1;
                break;
            case 2:
                playerCoordY[0] -= 1;
                break;
            case 3:
                playerCoordY[0] += 1;
                break;
        }
    }

    // Bounds collision
    if (playerCoordX[0] < 0 || playerCoordX[0] >= gridWidth || playerCoordY[0] < 0 || playerCoordY[0] >= gridHeight)
    {
        finishScreen = 1;
        PlaySound(fxCoin);
    }

    // Player collision
    for (size_t i = 0; i < playerLength - 1; i++)
    {
        
    }

    // Pickup collision
    if (playerCoordX[0] == pickupCoord.x && playerCoordY[0] == pickupCoord.y)
    {
        // Relocate pickup
        playerCoordX[playerLength] = playerCoordX[playerLength - 1];
        playerCoordY[playerLength] = playerCoordY[playerLength - 1];
        playerLength += 1;

        bool relocated = false;
        while (!relocated)
        {
            int x = rand() % gridWidth;
            int y = rand() % gridHeight;
            if (playerCoordX[0] != x && playerCoordY[0] != y)
            {
                pickupCoord.x = x;
                pickupCoord.y = y;
                relocated = true;
            }
        }
        PlaySound(fxCoin);
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // Draw Background
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

    // Draw Pickup
    DrawRectangle(gridSize + (pickupCoord.x * gridSize), gridSize + (pickupCoord.y * gridSize), gridSize, gridSize, PINK);

    // Draw Player
    int colorLength = sizeof(playerColors) / sizeof(playerColors[0]);
    for (size_t i = 0; i < playerLength; i++)
    {
        DrawRectangle(gridSize + (playerCoordX[i] * gridSize), gridSize + (playerCoordY[i] * gridSize), gridSize, gridSize, playerColors[i % colorLength]);
    }

    // Draw Outline
    Rectangle outlineRect;
    outlineRect.x = gridSize;
    outlineRect.y = gridSize;
    outlineRect.width = GetScreenWidth() - (gridSize * 2);
    outlineRect.height = GetScreenHeight() - (gridSize * 2);
    DrawRectangleLinesEx(outlineRect, 2, PURPLE);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}