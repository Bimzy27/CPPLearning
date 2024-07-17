#include "Structure.h"
#include <raylib.h>
#include <Main.h>

void Structure::Initialize()
{
}

void Structure::Deinitialize()
{

}

void Structure::Update()
{
	DrawRectangle(0 - CELL_SIZE, GROUND_HEIGHT - CELL_SIZE * 2, CELL_SIZE * 2, CELL_SIZE * 2, ORANGE);
}