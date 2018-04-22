#include <iostream>

bool solve(int board[9][9], int curr_r, int curr_c);

int h_axis(int board[9][9], int r, int target);

int v_axis(int board[9][9], int c, int target);

int subgrid(int board[9][9], int r, int c, int target);

bool check_finished(int board[9][9]);

void print_grid(int board[9][9]);

//taken from https://github.com/irawoodring/263/blob/master/backtracking/sample_code/backtracking.cpp
bool find_spot(int board[9][9], int & r, int & c);

/**
 * Program that solves a sudoku board using backtracking
 *
 * Note: Compiles but does not run correctly
 *
 * @author Logan Karney
 * @version Winter 2018
 */
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
	
	solve(board, 0, 0);
}


/*
 * Solves the board recursively
 *
 * @param board
 * 	sudoku board being used
 * @param curr_r
 * 	current row value
 * @param curr_c
 * 	current c value
 */
bool solve(int board[9][9], int curr_r, int curr_c){
	
	//if the program cannot find an empty spot
	if(find_spot(board, curr_r, curr_c) == false){
		return true;
	}

	//attempts to use all possible guesses
	int guess = 1;
	while(guess < 10){

		//if the current guess can be placed on the board
		if(h_axis(board,curr_r,guess) == 0 && v_axis(board, curr_c, guess) == 0 && subgrid(board, curr_r, curr_c, guess) == 0){
			board[curr_r][curr_c] = guess;
	
			print_grid(board);
			std::cout << std::endl;

			//if the puzzle is finished, returns true
			if(solve(board,curr_r,curr_c))
				return true;

			//else, the guess wasn't correct, removes it
			else
				board[curr_r][curr_c] = 0;
		}
		else{
			//increments guess
			guess++;
		}
	}

	//All possibilities could not be used, returns false
	return false;
}

/*
 * Method that checks the subgrid to find the ammount of occurances of target
 *
 */
int subgrid(int board[9][9], int r, int c, int target){
	
	r = 3 * (r/3);
	c = 3 * (c/3);

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

/*
 * Method that checks the row to find the ammount of occurances of target
 */
int h_axis(int board[9][9], int r, int target){
	//number of occurances of target
	int rtn = 0;

	for(int i = 0; i < 9; i++){
		if(board[r][i] == target)
			rtn++;
	}

	return rtn;
}

/*
 * Method that checks the column to find the ammount of occurances of target
 */
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

/*
 * Method that prints out all values of the board
 */
void print_grid(int board[9][9]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/**
 * Method that checks that all moves are valid
 */
bool check_finished(int board[9][9]){
	for(int i = 0; i < 9; i+= 3){
                for(int j = 0; j < 9; j+= 3){	
			for(int t = 1; t < 10; i++){
				if(subgrid(board,i,j,t) != 1)
					return false;
			}
		}
	}

	for(int x = 0; x < 9; x++){
		for(int t = 1; t < 10; t++){
			if(h_axis(board,x,t) != 1 || !v_axis(board,x,t) != 1)
				return false;
		}
	}

	return true;
}

//taken from https://github.com/irawoodring/263/blob/master/backtracking/sample_code/backtracking.cpp
/**
 * Method that finds an empty spot
 */
bool find_spot(int board[9][9], int & r, int & c){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(board[i][j] == 0){
				r = i;
				c = j;
				return true;
			}
		}
	}
	return false;
}
