#include <iostream>
#include <cmath>
using namespace std;
const int DIM = 9;

bool canPlace(int num, int board[][DIM], int x, int y){
    for(int i = 0; i < DIM; ++i){
        if (board[i][y] == num) return false;
        if (board[x][i] == num) return false; 
    }

    int rootDim = sqrt(DIM);
    int subBoxRow = (x/3)*3; 
    int subBoxCol = (y/3)*3; 
    for(int i = subBoxRow; i < subBoxRow + rootDim; ++i){
        for(int j = subBoxCol; j < subBoxCol + rootDim; ++j){
            if (board[i][j] == num) return false;
        }
    }
    return true;
}

void printBoard(int board[][DIM]){
    for(int i = 0; i < DIM; ++i){
        for (int j = 0; j < DIM; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


bool sudoku(int board[][DIM], int i, int j){
    // if all cells filled
    if (i == 9) return true;

    if (j == 9){
        return sudoku(board, i + 1, 0);
    }

    if (board[i][j] != 0){
        return sudoku(board, i ,j + 1);
    }

    for(int curNum = 1; curNum <= DIM; ++curNum){
        if (canPlace(curNum, board, i,j)){
            board[i][j] = curNum;
            bool success = sudoku(board, i, j + 1);
            if (success) return true;
            board[i][j] = 0;    // restore
        }
    } 
    return false;
}


int main() {
    int board[][DIM] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    bool isSuccessful = sudoku(board, 0, 0);
    if (isSuccessful) {
        printBoard(board);
    }
    else {
        cout << "Hey man! get it solved from someone else!";
    }
}