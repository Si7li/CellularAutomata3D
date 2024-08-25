#pragma once
#include <vector>

class Grid3d
{
	public:
		Grid3d(int width, int height, int length, int cellSize)
			:rows(height / cellSize), columns(width / cellSize), slices(length / cellSize),cellSize(cellSize), cells(rows, std::vector<std::vector<int>>(columns, std::vector<int>(slices, 0))) { };
		void Draw();
		void setValue(int row, int column,int slice, int value);
		int GetValue(int row, int column, int slice);
		bool IsWithinBound(int row, int column, int slice);
		int GetRows() { return rows; }
		int GetColumns() { return columns; }
		int GetSlices() { return slices; }
		void FillRandom();
		void Clear();
	private:
		int rows;
		int columns;
		int slices;
		int cellSize;
		std::vector<std::vector<std::vector<int>>> cells;
};