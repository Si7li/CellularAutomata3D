#include "grid3d.hpp"

class Simulation
{
public:
	Simulation(int width, int height, int length, int cellSize)
		:grid(width, height, length, cellSize), tempGrid(width, height, length, cellSize), run(false) { };
	void Draw();
	void SetCellValue(int row, int column, int slice, int value);
	int CountLiveNeighbors(int row, int column, int slice);
	void Update();
	bool IsRunning() { return run; }
	void Start() { run = true; }
	void Stop() { run = false; }
	void ClearGrid();
	void CreateRandomnState();

private:
	Grid3d grid;
	Grid3d tempGrid;
	bool run;
};