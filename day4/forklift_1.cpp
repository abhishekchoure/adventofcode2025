#include<bits/stdc++.h>
#include<fstream>

bool isPaperRollAccessible(char** grid, int rows, int cols, int row, int col){
	int MAX_ADJACENT_ROLLS = 4;

	if(row == 0){
		if(col == 0){
			return true;	
		}else if(col == cols - 1){
			return true;	
		}else{
			int count = 0;
			if(grid[row][col - 1] == '@') count++;
			if(grid[row][col + 1] == '@') count++;
			if(grid[row + 1][col] == '@') count++;
			if(grid[row + 1][col - 1] == '@') count++;
			if(grid[row + 1][col + 1] == '@') count++;

			return count < MAX_ADJACENT_ROLLS;
		}
	}else if(row == rows - 1){
		if(col == 0){
			return true;	
		}else if(col == cols - 1){
			return true;	
		}else{
			int count = 0;
			if(grid[row][col - 1] == '@') count++;
			if(grid[row][col + 1] == '@') count++;
			if(grid[row - 1][col] == '@') count++;
			if(grid[row - 1][col - 1] == '@') count++;
			if(grid[row - 1][col + 1] == '@') count++;

			return count < MAX_ADJACENT_ROLLS;
		}
	}else{

		if(col == 0){
			int count = 0;
			if(grid[row][col + 1] == '@') count++;
			if(grid[row - 1][col + 1] == '@') count++;
			if(grid[row + 1][col + 1] == '@') count++;
			if(grid[row + 1][col] == '@') count++;
			if(grid[row - 1][col] == '@') count++;

			return count < MAX_ADJACENT_ROLLS;
				
		}else if (col == cols - 1){
			int count = 0;
			if(grid[row][col - 1] == '@') count++;
			if(grid[row - 1][col - 1] == '@') count++;
			if(grid[row + 1][col - 1] == '@') count++;
			if(grid[row + 1][col] == '@') count++;
			if(grid[row - 1][col] == '@') count++;

			return count < MAX_ADJACENT_ROLLS;
		}else{
			int count = 0;
			if(grid[row][col - 1] == '@') count++;
			if(grid[row][col + 1] == '@') count++;
			if(grid[row - 1][col - 1] == '@') count++;
			if(grid[row - 1][col + 1] == '@') count++;
			if(grid[row + 1][col - 1] == '@') count++;
			if(grid[row + 1][col + 1] == '@') count++;
			if(grid[row + 1][col] == '@') count++;
			if(grid[row - 1][col] == '@') count++;

			return count < MAX_ADJACENT_ROLLS;
		}
	}

	return false;
}

int getTotalNoOfRows(std::string filePath){
	std::ifstream inputFile(filePath);
	if(!inputFile){
		std::cerr << "Error opening file! : " << filePath << std::endl;
	}

	std::string line;
	int rows = 0;
	while(std::getline(inputFile, line)){
		rows++;
	}

	inputFile.close();
	return rows;
}

int getTotalNoOfColumns(std::string filePath){	
	std::ifstream inputFile(filePath);
	if(!inputFile){
		std::cerr << "Error opening file! : " << filePath << std::endl;
	}

	std::string line;
	int columns = 0;
	while(std::getline(inputFile, line)){
		for(char c: line) columns++;
		break;
	}

	inputFile.close();
	return columns;
}

void printGrid(char** grid, int rows, int cols){
	std::cout << std::endl;
	for(int i=0; i < rows; i++){
		for(int j=0; j<cols; j++){
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void initializeGrid(char** grid, int rows, int cols, std::string filePath){
	std::ifstream inputFile(filePath);
	if(!inputFile){
		std::cerr << "Error opening file! : " << filePath << std::endl;
	}

	std::string line;
	int row = 0;
	while(std::getline(inputFile, line)){
		int col = 0;
		for(char ch: line){
			grid[row][col++] = ch;
		}
		row++;
	}

	inputFile.close();
}

int main(){
	int rolls = 0;
	int rows = getTotalNoOfRows("./input.txt");
	int cols = getTotalNoOfColumns("./input.txt");

	std::cout << "GRID : [" << rows << "," << cols << "]" << std::endl;
	char** grid = new char*[rows];
	char** finalGrid = new char*[rows];

	for(int i=0; i< rows; i++){
		grid[i] = new char[cols];
		finalGrid[i] = new char[cols];
	}

	initializeGrid(grid, rows, cols, "./input.txt");
	initializeGrid(finalGrid, rows, cols, "./input.txt");

	printGrid(grid, rows, cols);

	for(int row = 0; row < rows; row++){
		for(int col=0; col < cols; col++){
			if(grid[row][col] == '@'){
				bool isAccessible = isPaperRollAccessible(grid, rows, cols, row, col);
				if(isAccessible){
					finalGrid[row][col] = 'x';
					rolls++;
				}
			}
		}
	}

	printGrid(finalGrid, rows, cols);
	std::cout << rolls << std::endl;
}
