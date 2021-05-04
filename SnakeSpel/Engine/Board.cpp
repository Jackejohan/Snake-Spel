#include "Board.h"
#include <assert.h>

static const Color borderColor = Colors::Blue;


Board::Board(Graphics& gfx) : gfx ( gfx )
{

}


void Board::DrawCell(const Location& loc, Color c) const
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x * Dimension, loc.y * Dimension,Dimension-3,Dimension-3,c);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 2 && loc.x < width -2 &&
		loc.y >= 2 && loc.y < height -2;
}

void Board::SetBorder()
{
	gfx.DrawRect(25, 25, 775, 47, borderColor);
	gfx.DrawRect(25, 47, 47, 575, borderColor);
	gfx.DrawRect(47, 553, 775, 575, borderColor);
	gfx.DrawRect(753, 47, 775, 553, borderColor);
}
