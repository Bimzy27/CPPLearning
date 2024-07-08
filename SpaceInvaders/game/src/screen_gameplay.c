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

// Player
Vector2 playerCoord;
static const int pMaxBullets = 256;
int pBulletCoordX[256];
int pBulletCoordY[256];
int pActiveBullets = 0;

// Enemies
int enemyCoordX[256];
int enemyCoordY[256];
int enemyCount = 0;
// TODO maybe add enemy bullets?
//static const int eMaxBullets = 2048;
//int eBulletCoordX[2048];
//int eBulletCoordY[2048];
//int eActiveBullets = 0;

int min(int x, int y)
{
    return (x < y) ? x : y;
}

Color getPlayerBulletColor(int i)
{
    return CLITERAL(Color) { 0, 7 * (gridHeight - pBulletCoordY[i]), 255 - (7 * (gridHeight - pBulletCoordY[i])), 255 };
}

Color getEnemyColor(int i)
{
    return CLITERAL(Color) { 255, 7 * (gridHeight - enemyCoordY[i]), 0, 255 };
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
    if (framesCounter % 12 == 0)
    {
        // Move Enemies
        for (size_t i = 0; i < enemyCount; i++)
        {
            if (enemyCoordX[i] >= gridWidth - 1)
            {
                enemyCoordY[i] += 3;
                enemyCoordX[i] = gridWidth - 2;
            }
            else if (enemyCoordX[i] <= 0)
            {
                enemyCoordY[i] += 3;
                enemyCoordX[i] = 1;
            }
            else if (enemyCoordY[i] % 2 == 0)
            {
                enemyCoordX[i] += 1;
            }
            else
            {
                enemyCoordX[i] -= 1;
            }

            if (enemyCoordX[i] > gridHeight)
            {
                finishScreen = 1;
            }
        }
    }

    // enemy spawner
    if (framesCounter % 120 == 0)
    {
        enemyCoordX[enemyCount] = 1;
        enemyCount += 1;
    }

    // Bullet Game Tick
    if (framesCounter % 30 == 0)
    {
        // Shoot Player Bullet
        if (IsKeyDown(KEY_SPACE))
        {
            pBulletCoordX[pActiveBullets % pMaxBullets] = playerCoord.x;
            pBulletCoordY[pActiveBullets % pMaxBullets] = playerCoord.y;
            pActiveBullets += 1;
        }
    }
    if (framesCounter % 6 == 0)
    {
        // Move Player Bullets
        for (size_t i = 0; i < min(pActiveBullets, pMaxBullets); i++)
        {
            pBulletCoordY[i] -= 1;
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
    for (size_t i = 0; i < min(pActiveBullets, pMaxBullets); i++)
    {
        if (pBulletCoordY[i] >= 0)
        {
            DrawRectangle(gridSize + (pBulletCoordX[i] * gridSize) + (gridSize * 0.25), gridSize + (pBulletCoordY[i] * gridSize) + (gridSize * 0.25), gridSize * 0.5, gridSize * 0.5, getPlayerBulletColor(i));
        }
    }

    // Draw Enemies
    for (size_t i = 0; i < enemyCount; i++)
    {
        DrawRectangle(gridSize + (enemyCoordX[i] * gridSize), gridSize + (enemyCoordY[i] * gridSize), gridSize, gridSize, getEnemyColor(i));
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