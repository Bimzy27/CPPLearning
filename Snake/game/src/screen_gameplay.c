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
Vector2 playerCoord;
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
    playerCoord.x = gridWidth / 2;
    playerCoord.y = gridHeight / 2;
    pickupCoord.x = playerCoord.x + 15;
    pickupCoord.y = playerCoord.y;

    srand(time(NULL));
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    framesCounter += 1;

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
        PlaySound(fxCoin);
    }

    // User Input
    if (IsKeyDown(KEY_RIGHT))
    {
        direction = 0;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        direction = 1;
    }
    else if (IsKeyDown(KEY_UP))
    {
        direction = 2;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        direction = 3;
    }

    // Movement
    if (framesCounter % 10 == 0)
    {
        switch (direction)
        {
        case 0:
        default:
            playerCoord.x += 1;
            break;
        case 1:
            playerCoord.x -= 1;
            break;
        case 2:
            playerCoord.y -= 1;
            break;
        case 3:
            playerCoord.y += 1;
            break;
        }
    }

    // Bounds collision
    if (playerCoord.x < 0 || playerCoord.x >= gridWidth || playerCoord.y < 0 || playerCoord.y >= gridHeight)
    {
        finishScreen = 1;
    }

    // Pickup collision
    if (playerCoord.x == pickupCoord.x && playerCoord.y == pickupCoord.y)
    {
        // Relocate pickup
        bool relocated = false;
        while (!relocated)
        {
            int x = rand() % gridWidth;
            int y = rand() % gridHeight;
            if (playerCoord.x != x && playerCoord.y != y)
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
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);

    // Draw Pickup
    DrawRectangle(gridSize + (pickupCoord.x * gridSize), gridSize + (pickupCoord.y * gridSize), gridSize, gridSize, RED);

    // Draw Player
    DrawRectangle(gridSize + (playerCoord.x * gridSize), gridSize + (playerCoord.y * gridSize), gridSize, gridSize, DARKBLUE);

    Rectangle outlineRect;
    outlineRect.x = gridSize;
    outlineRect.y = gridSize;
    outlineRect.width = GetScreenWidth() - (gridSize * 2);
    outlineRect.height = GetScreenHeight() - (gridSize * 2);
    DrawRectangleLinesEx(outlineRect, 2, BLACK);

    /*Vector2 pos = { 20, 10 };
    DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize*3.0f, 4, MAROON);
    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);*/
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