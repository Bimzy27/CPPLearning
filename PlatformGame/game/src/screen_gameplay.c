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

Vector2 playerPos;
float playerSpeed;
int map[gridHeight][gridWidth] = { 0 };

Color getColorFromMapVal(int val)
{
    switch (val)
    {
    case 0:
    default: //SKY
        return SKYBLUE;
    case 1:
        return DARKBROWN;
    case 2:
        return DARKGREEN;
    case 3:
        return (Color) { 0, 142, 44, 255 };
    }
}

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;

    playerPos.x = screenWidth * 0.5;
    playerPos.y = screenHeight - (gridSize * 4);
    playerSpeed = 250.0f;

    // Initialize map ints
    for (int row = 0; row < gridHeight; row++) 
    {
        for (int col = 0; col < gridWidth; col++) 
        {
            if (row == gridHeight - 1 || row == gridHeight - 2) {
                map[row][col] = 1;
            }
            else if (row == gridHeight - 3) {
                map[row][col] = col % 4 == 0 ? 3 : 2;
            }
        }
    }
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
        PlaySound(fxCoin);
    }

    if (IsKeyDown(KEY_LEFT))
    {
        playerPos.x -= GetFrameTime() * playerSpeed;
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        playerPos.x += GetFrameTime() * playerSpeed;
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // Draw Map
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
    for (int row = 0; row < gridHeight; row++)
    {
        for (int col = 0; col < gridWidth; col++)
        {
            DrawRectangle(col * gridSize, row * gridSize, gridSize, gridSize, getColorFromMapVal(map[row][col]));
        }
    }

    // Draw Player
    DrawRectangle(playerPos.x, playerPos.y, gridSize, gridSize, RED);
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