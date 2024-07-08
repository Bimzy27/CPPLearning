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
int direction = 0;
Vector2 playerPosition;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    playerPosition.x = GetScreenWidth() / 2;
    playerPosition.y = GetScreenHeight() / 2;
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
    if (framesCounter % 20 == 0)
    {
        switch (direction)
        {
        case 0:
        default:
            playerPosition.x += 10;
            break;
        case 1:
            playerPosition.x -= 10;
            break;
        case 2:
            playerPosition.y -= 10;
            break;
        case 3:
            playerPosition.y += 10;
            break;
        }
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
    DrawRectangle(playerPosition.x, playerPosition.y, 10, 10, DARKBLUE);

    Rectangle outlineRect;
    outlineRect.x = 10;
    outlineRect.y = 10;
    outlineRect.width = GetScreenWidth() - 20;
    outlineRect.height = GetScreenHeight() - 20;
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