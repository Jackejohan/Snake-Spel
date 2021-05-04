#pragma once
/* Detta är klassen som används för att skapa grid- systemet som spelet använder sig 
utav för att placera ut saker på spelplanen i det här fallet ormen och maten*/
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