#include <bits/stdc++.h>
#define N 4
using namespace std;
class queens{
    public:
    bool solveNQ();
    void printSolution(int board[N][N]);
    bool isSafe(int board[N][N], int row, int col);
    bool solveNQUtil(int board[N][N], int col);
    
    
}que;

void queens:: printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}

bool queens:: isSafe(int board[N][N], int row, int col)
{
	int i, j;

	// Check this row on left side
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	// Check upper diagonal on left side
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	// Check lower diagonal on left side
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool queens:: solveNQUtil(int board[N][N], int col)
{
	
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) {
		
		
		if (isSafe(board, i, col)) {
			
			// Place this queen in board[i][col]
			board[i][col] = 1;

			// recur to place rest of the queens
			if (solveNQUtil(board, col + 1))
				return true;

			board[i][col] = 0; // BACKTRACK
		}
	}

	return false;
}


bool queens:: solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

// Driver program to test above function
int main()
{
	que.solveNQ();
	return 0;
}

