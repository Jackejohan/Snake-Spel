#pragma once
/* Detta �r klassen som anv�nds f�r att skapa grid- systemet som spelet anv�nder sig 
utav f�r att placera ut saker p� spelplanen i det h�r fallet ormen och maten*/
struct Location
{
	void Add(const Location& value)
	{
		x += value.x;
		y += value.y;
	}
	bool operator == (const Location& rhs) const
	{
		return y == rhs.y && x == rhs.x;
	}
	int x;
	int y;
};