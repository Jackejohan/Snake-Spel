#include "Goal.h"

static const Color Green = Colors::Green;

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng, brd, snake);

}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(2, brd.GetGridWidth() - 3);
	std::uniform_int_distribution<int> yDist(2, brd.GetGridHeight() - 3);

	Location newloc;
	do
	{
		newloc.x = xDist(rng);
		newloc.y = yDist(rng);
	} while (snake.IsInTile(newloc));

	loc = newloc;
}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, Green);
}

const Location& Goal::GetLocation() const
{
	return loc;
}