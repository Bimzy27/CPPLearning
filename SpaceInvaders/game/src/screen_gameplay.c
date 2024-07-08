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

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
Vector2 playerCoord;
static const int maxBullets = 256;
int bulletCoordX[256];
int bulletCoordY[256];
int activeBullets = 0;

int min(int x, int y)
{
    return (x < y) ? x : y;
}

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    playerCoord.x = gridWidth / 2;
    playerCoord.y = gridHeight - 2;
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        PlaySound(fxCoin);
    }

    // Movement Game Tick
    if (framesCounter % 12 == 0)
    {
        // Move Player
        if (IsKeyDown(KEY_LEFT) && playerCoord.x > 1)
        {
            playerCoord.x -= 1;
        }
        else if (IsKeyDown(KEY_RIGHT) && playerCoord.x < gridWidth - 2)
        {
            playerCoord.x += 1;
        }
    }

    // Bullet Game Tick
    if (framesCounter % 30 == 0)
    {
        // Shoot Player Bullet
        if (IsKeyDown(KEY_SPACE))
        {
            bulletCoordX[activeBullets % maxBullets] = playerCoord.x;
            bulletCoordY[activeBullets % maxBullets] = playerCoord.y;
            activeBullets += 1;
        }
    }
    if (framesCounter % 6 == 0)
    {
        // Move Player Bullets
        for (size_t i = 0; i < min(activeBullets, maxBullets); i++)
        {
            bulletCoordY[i] -= 1;
        }
    }

    framesCounter += 1;
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // Draw Background
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

    // Draw Player Bullets
    for (size_t i = 0; i < min(activeBullets, maxBullets); i++)
    {
        if (bulletCoordY[i] >= 0)
        {
            DrawRectangle(gridSize + (bulletCoordX[i] * gridSize) + (gridSize * 0.25), gridSize + (bulletCoordY[i] * gridSize) + (gridSize * 0.25), gridSize * 0.5, gridSize * 0.5, CLITERAL(Color){ 0, 7 * (gridHeight - bulletCoordY[i]), 255 - (7 * (gridHeight - bulletCoordY[i])), 255 });
        }
    }

    // Draw Player
    DrawRectangle(gridSize + ((playerCoord.x - 1) * gridSize), gridSize + (playerCoord.y * gridSize), gridSize * 3, gridSize, BLUE);
    DrawRectangle(gridSize + ((playerCoord.x) * gridSize), gridSize + ((playerCoord.y - 1) * gridSize), gridSize, gridSize, BLUE);

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