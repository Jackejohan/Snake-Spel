#pragma once
#include "Graphics.h"
#include "Location.h"

// Denna klass g�r i princip det som namnet s�ger att det g�r, den s�tter upp br�dan.
class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c) const;
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location& loc) const;
	void SetBorder();

private:
	static constexpr int Dimension = 25;
	static constexpr int width = 32;
	static constexpr int height = 24;
	Graphics& gfx;
};

