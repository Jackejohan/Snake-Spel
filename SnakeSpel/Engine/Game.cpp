/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/


/* Här är klassen som uppdaterar framen och som får allting på skärmen att poppa fram*/

#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"
#include <string>

static const Color Yellow = Colors::Yellow;
static const Color White = Colors::White;

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng(std::random_device()()),
	snake ( {2,2} ),
	goal (rng,brd,snake)

{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!GameIsStarted)
	{
		while (!wnd.mouse.IsEmpty())
		{
			const auto e = wnd.mouse.Read();
			if (e.GetType() == Mouse::Event::Type::LPress)
			{
				if (wnd.mouse.GetPosX() >= 300 &&
					wnd.mouse.GetPosX() <= 500 &&
					wnd.mouse.GetPosY() >= 50 &&
					wnd.mouse.GetPosY() <= 150)
				{
					if (wnd.mouse.LeftIsPressed())
					{
						if (gb == 0)
						{
							gb = 255;
							acc = 1.02;
						}
						else if (gb == 255)
						{
							gb = 0;
							acc = 1;
						}
					}
				}

				if (wnd.mouse.GetPosX() >= 50 &&
					wnd.mouse.GetPosX() <= 250 &&
					wnd.mouse.GetPosY() >= 400 &&
					wnd.mouse.GetPosY() <= 500)
				{
					if (wnd.mouse.LeftIsPressed())
					{
						snakeMovePeriod = 5;
						gbH = 255;
						if (gbM == 255)
						{
							gbM = 0;
						}
						else
						{
							gbE = 0;
						}
					}
				}
			}
				if (wnd.mouse.GetPosX() >= 300 &&
					wnd.mouse.GetPosX() <= 500 &&
					wnd.mouse.GetPosY() >= 400 &&
					wnd.mouse.GetPosY() <= 500)
				{
					if (wnd.mouse.LeftIsPressed())
					{
						snakeMovePeriod = 10;
						gbM = 255;
						if (gbE == 255)
						{
							gbE = 0;
						}
						else
						{
							gbH = 0;
						}
					}
				}
			{
				if (wnd.mouse.GetPosX() >= 550 &&
					wnd.mouse.GetPosX() <= 750 &&
					wnd.mouse.GetPosY() >= 400 &&
					wnd.mouse.GetPosY() <= 500)
				{
					if (wnd.mouse.LeftIsPressed())
					{
						snakeMovePeriod = 15;
						gbE = 255;
						if (gbH == 255)
						{
							gbH = 0;
						}
						else
						{
							gbM = 0;
						}
					}
				}
			}
		}
	}
	if (GameIsStarted)
	{
		if (!GameIsOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				if (delta_loc.y == -1)
				{
					if (FörnekaHöger || FörnekaKnapp || KeyIsPressed)
					{
					}
					else
					{
						delta_loc = { 1, 0 };
						FörnekaHöger = true;
						FörnekaKnapp = true;
						KeyIsPressed = true;
					}
				}

				if (delta_loc.y == 1)
				{
					if (FörnekaHöger || FörnekaKnapp || KeyIsPressed)
					{
					}
					else
					{
						delta_loc = { -1, 0 };
						FörnekaHöger = true;
						FörnekaKnapp = true; 
						KeyIsPressed = true;
					}
				}

				if (delta_loc.x == -1)
				{
					if (FörnekaHöger || FörnekaKnapp || KeyIsPressed)
					{
					}
					else
					{
						delta_loc = { 0, -1 };
						FörnekaHöger = true;
						FörnekaKnapp = true;
						KeyIsPressed = true;
					}
				}

				if (delta_loc.x == 1)
				{
					if (FörnekaHöger || FörnekaKnapp || KeyIsPressed)
					{
					}
					else
					{
						delta_loc = { 0, 1 };
						FörnekaHöger = true;
						FörnekaKnapp = true;
						KeyIsPressed = true;
					}
				}
			}
			else 
			{
				FörnekaHöger = false;
			}



			if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				if (delta_loc.y == -1)
				{
					if (FörnekaVänster || FörnekaKnapp || KeyIsPressed)
					{
					}
					else
					{
						delta_loc = { -1, 0 };
						FörnekaVänster = true;
						FörnekaKnapp = true;
						KeyIsPressed = true;
					}
				}


				if (delta_loc.y == 1)
				{
					if (FörnekaVänster || FörnekaKnapp || KeyIsPressed)
					{
					}
					else
					{
						delta_loc = { 1, 0 };
						FörnekaVänster = true;
						FörnekaKnapp = true;
						KeyIsPressed = true;
					}
				}

				if (delta_loc.x == -1)
				{
					if (FörnekaVänster || FörnekaKnapp || KeyIsPressed)
					{
					}
					else
					{
						delta_loc = { 0, 1 };
						FörnekaVänster = true;
						FörnekaKnapp = true;
						KeyIsPressed = true;
					}
				}


				if (delta_loc.x == 1)
				{
					if (FörnekaVänster || FörnekaKnapp || KeyIsPressed)
					{
					}
					else
					{
						delta_loc = { 0, -1 };
						FörnekaVänster = true;
						FörnekaKnapp = true;
						KeyIsPressed = true;
					}
				}
			}
			else 
			{
				FörnekaVänster = false;
			}
			
			FörnekaKnapp = false;
			snakeMoveCounter+= 0.5;
			if (snakeMoveCounter >= snakeMovePeriod)
			{
				snakeMoveCounter = 0;
				KeyIsPressed = false;
				const Location next = snake.GetNextHeadLocation(delta_loc);
				if (!brd.IsInsideBoard(next) ||
					snake.IsInTileExceptEnd(next))
				{
					GameIsOver = true;
				}
				else
				{
					const bool eating = next == goal.GetLocation();
					if (eating)
					{
						snake.Grow();
					}
					snake.MoveBy(delta_loc);
					if (eating)
					{
						goal.Respawn(rng, brd, snake);
						snakeMovePeriod = snakeMovePeriod / acc;
					}
				}
			}
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		GameIsStarted = true;
	}

}

void Game::ComposeFrame()
{

	if (!GameIsStarted)
	{
		gfx.DrawRectA(300, 50, 500, 150, 255, gb, gb);

		gfx.DrawRectA(50, 400, 250, 500, 255, gbH, gbH);
		gfx.DrawRectA(300, 400, 500, 500, 255, gbM, gbM);
		gfx.DrawRectA(550, 400, 750, 500, 255, gbE, gbE);
		SpriteCodex::DrawTitle(295, 200, gfx);
	}
	else
	{
		snake.Draw(brd);
		goal.Draw(brd);
		brd.SetBorder();
		if (GameIsOver)
		{
			SpriteCodex::DrawGameOver(200, 200, gfx);
		}
	}
}
