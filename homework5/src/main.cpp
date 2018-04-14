#include <iostream>

bool solve(int board[9][9]);

bool axises(int board[9][9], int r, int c, int target);

bool subgrid(int board[9][9], int r, int c, int target);

int main(void){
	int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
        	           { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
               		   { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
                           { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
                           { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
                           { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
                           { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
                           { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
                           { 0, 7, 0, 0, 0, 0, 0, 3, 0 }};
	
	/*for(int i = 0; i < 9; i+=3){
		for(int j = 0; j < 9; j+=3){
			subgrid(board, i, j);
		}
	}*/	

}

bool solve(int board[9][9]){
	return true;
}

bool axises(int board[9][9], int r, int c, int target){
	for(int x = 0; x < 9; x++){
		if(board[r][x] == target || board[x][c] == target)
			return false;
	}

	return true;
}

bool subgrid(int board[9][9], int r, int c, int target){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[i+r][j+c] == target)
				return false;
			//std::cout << board[i+r][j+c] << " ";
		}
		//std::cout << std::endl;
	}
	//std::cout << std::endl;
	return true;
}
