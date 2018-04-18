#include <iostream>

bool solve(int board[9][9]);

int h_axis(int board[9][9], int r, int target);

int v_axis(int board[9][9], int c, int target);

bool subgrid(int board[9][9], int r, int c, int target);

bool check_finished(int board[9][9]);

void print_grid(int board[9][9]);

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
	
	solve(board);
}

bool solve(int board[9][9]){

	int target = 1;

	return true;
}

bool subgrid(int board[9][9], int r, int c, int target){
	//number of occurances of target
	int rtn = 0;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[i+r][j+c] == target)
				rtn++;
		}
	}
	return rtn;
}

int h_axis(int board[9][9], int r, int target){
	//number of occurances of target
	int rtn = 0;

	for(int i = 0; i < 9; i++){
		if(board[r][i] == target)
			rtn++;
	}

	return rtn;
}

int v_axis(int board[9][9], int c, int target){	
	//number of occurances of target
	int rtn = 0;

	for(int i = 0; i < 9; i++){
		if(board[i][c] == target){
			rtn++;
		}
	}
	return rtn;
}

void print_grid(int board[9][9]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool check_finished(int board[9][9]){
	
	for(int i = 0; i < 9; i+=3){
		for(int j = 0; j < 9; j+=3){
			for(int t = 1; t < 10; i++){
				if(subgrid(board,i,j,t) > 1)
					return false;
			}
		}
	}

	for(int x = 0; x < 9; x++){
		for(int t = 1; t < 10; t++){
			if(h_axis(board,x,t) > 1 || !v_axis(board,x,t) > 1)
				return false;
		}
	}

	return true;
}
