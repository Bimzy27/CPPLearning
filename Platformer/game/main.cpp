/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

For a C++ project simply rename the file to .cpp and run premake 

-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty. In no event 
--will the authors be held liable for any damages arising from the use of this software.

--Permission is granted to anyone to use this software for any purpose, including commercial 
--applications, and to alter it and redistribute it freely, subject to the following restrictions:

--  1. The origin of this software must not be misrepresented; you must not claim that you 
--  wrote the original software. If you use this software in a product, an acknowledgment 
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

*/

#include "raylib.h"
#include <Player.h>
#include <Main.h>
#include <Map.h>

int main ()
{
	Map map;
	Player player;

	// set up the window
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Platformer");
	map.Initialize();
	player.Initialize();


	// game loop
	while (!WindowShouldClose())
	{
		// drawing
		BeginDrawing();
		ClearBackground(SKYBLUE);
		
		map.Update();
		player.Update();
		
		EndDrawing();
	}

	// cleanup
	player.Deinitialize();
	map.Deinitialize();
	CloseWindow();
	return 0;
}