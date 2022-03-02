#include <iostream>
#include <iomanip>

int size = 5;



int solveTurn(int x, int y, int moves, int sol[5][5], int xMove[8], int yMove[8]) {
//	std::cout << "here" << std::endl;
	int nextX, nextY;

	if(moves == size * size) {
		return 1;
	}

	for(int i = 0; i<8; i++) {
		nextX = x + xMove[i];
		nextY = y + yMove[i];

		//Next spot is in range of the board and not already taken
		if(nextX >= 0 && nextX < size && nextY >= 0 && nextY < size && sol[nextX][nextY] && sol[nextX][nextY] == -1) {
			sol[nextX][nextY] = moves;

			//Call function recursivly for the next move. If i
			if(solveTurn(nextX, nextY, moves + 1, sol, xMove, yMove) == 1) {
				return 1;
			}
			else {
				//If it fails that move will be back tracked
				sol[nextX][nextY] = -1;
			}
		}	

	}
	
	return 0;
}


void solveBoard(int size, int startingX, int startingY) {
	int sol[5][5];

	//Creates empty array with -1 of size board
	for(int x = 0; x < size; x++) {
		for(int y = 0; y < size; y++) {
			sol[x][y] = -1;
		}
	}
	
	int xMoves[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
	int yMoves[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

	sol[startingX][startingY] = 0;

	if(solveTurn(startingX, startingY, 1, sol, xMoves,  yMoves) == 0) {
		std::cout <<  "No solution found";
		return;
	} else {
		//print solution

		for(int i = 0; i< size; i++) {
			for(int j = 0; j< size; j++) {
				std::cout << std::setw(2) << sol[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}	



};



int main() {
	
	solveBoard(size, 2, 2);	
	return 0;
}
