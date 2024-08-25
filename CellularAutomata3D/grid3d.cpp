#include "grid3d.hpp"
#include <raylib.h>

void Grid3d::Draw()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			for (int slice = 0; slice < slices; slice++)
			{
				if (cells[row][column][slice])
				{
					Color color = {(row*7), (column * 7) ,(slice * 7), 225};
					DrawCube({ (float)row * cellSize,(float)column * cellSize,(float)slice * cellSize }, cellSize, cellSize, cellSize, color);
				}
			}
		}
	}
}

void Grid3d::setValue(int row, int column, int slice, int value)
{
	if (IsWithinBound(row, column,slice))
	{
		cells[row][column][slice] = value;
	}
}

int Grid3d::GetValue(int row, int column, int slice)
{
	if (IsWithinBound(row, column, slice))
	{
		return cells[row][column][slice];
	}
	return 0;
}

bool Grid3d::IsWithinBound(int row, int column, int slice)
{
	if (row >= 0 && row < rows && column >= 0 && column < columns && slice >= 0 && slice < slices)
	{
		return true;
	}
	return false;
}

void Grid3d::FillRandom()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			for (int slice = 0; slice < slices; slice++)
			{
				int randomnValue = GetRandomValue(0, 50);
				cells[row][column][slice] = (randomnValue == 0) ? 1 : 0;
			}
		}
	}
}

void Grid3d::Clear()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			for (int slice = 0; slice < slices; slice++)
			{
				cells[row][column][slice] = 0;
			}
		}
	}
}
