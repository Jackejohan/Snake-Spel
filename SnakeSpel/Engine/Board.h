#pragma once
#include "Graphics.h"
#include "Location.h"

// Denna klass gör i princip det som namnet säger att det gör, den sätter upp brädan.
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

