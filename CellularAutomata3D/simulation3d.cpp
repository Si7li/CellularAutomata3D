#include "simulation3d.hpp"
#include <tuple>
#include <vector>
#include <chrono>
#include <iostream>

void Simulation::Draw()
{
	grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int slice, int value)
{
	grid.setValue(row, column, slice, value);
}

int Simulation::CountLiveNeighbors(int row, int column, int slice)
{
	int liveNeighbors = 0;
	std::vector<std::tuple<int, int, int>> neighborOffsets = {
		std::tuple<int, int, int>{1,0,0},
		std::tuple<int, int, int>{0,1,0},
		std::tuple<int, int, int>{0,0,1},
		std::tuple<int, int, int>{-1,0,0},
		std::tuple<int, int, int>{0,-1,0},
		std::tuple<int, int, int>{0,0,-1},
		std::tuple<int, int, int>{1,1,0},
		std::tuple<int, int, int>{-1,1,0},
		std::tuple<int, int, int>{1,-1,0},
		std::tuple<int, int, int>{1,0,1},
		std::tuple<int, int, int>{-1,0,1},
		std::tuple<int, int, int>{1,0,-1},
		std::tuple<int, int, int>{0,1,1},
		std::tuple<int, int, int>{0,-1,1},
		std::tuple<int, int, int>{0,1,-1},
		std::tuple<int, int, int>{-1,-1,0},
		std::tuple<int, int, int>{-1,0,-1},
		std::tuple<int, int, int>{0,-1,-1},
		std::tuple<int, int, int>{1,1,1},
		std::tuple<int, int, int>{-1,1,1},
		std::tuple<int, int, int>{1,-1,1},
		std::tuple<int, int, int>{1,1,-1},
		std::tuple<int, int, int>{1,-1,-1},
		std::tuple<int, int, int>{-1,1,-1},
		std::tuple<int, int, int>{-1,-1,1},
		std::tuple<int, int, int>{-1,-1,-1}
	};
	for (const auto& offset : neighborOffsets)
	{
		int neighborRow = (row + std::get<0>(offset)) % grid.GetRows();
		int neighborColumn = (column + std::get<1>(offset)) % grid.GetColumns();
		int neighborSlice = (slice + std::get<2>(offset)) % grid.GetSlices();
		liveNeighbors += grid.GetValue(neighborRow, neighborColumn, neighborSlice);
	}
	return liveNeighbors;
}

void Simulation::Update()
{
	if (IsRunning())
	{
		for (int row = 0; row < grid.GetRows(); row++)
		{
			for (int column = 0; column < grid.GetColumns(); column++)
			{
				for (int slice = 0; slice < grid.GetSlices(); slice++)
				{
					int liveNeighbors = CountLiveNeighbors(row, column, slice);
					int cellValue = grid.GetValue(row, column, slice);

					if (cellValue == 1)
					{
						if (liveNeighbors == 4)
						{
							tempGrid.setValue(row, column, slice, 1);
						}
						else
						{
							tempGrid.setValue(row, column, slice, 0);
						}
						
					}
					else
					{
						if (liveNeighbors == 4)
						{
							tempGrid.setValue(row, column, slice, 1);
						}
						else
						{
							tempGrid.setValue(row, column, slice, 0);
						}
					}
				}
			}
		}

		grid = tempGrid;
	}
}

void Simulation::CreateRandomnState()
{
	if (!IsRunning())
	{
		grid.FillRandom();
	}
}

void Simulation::ClearGrid()
{
	if (!IsRunning())
	{
		grid.Clear();
	}
}
