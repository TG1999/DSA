# include <iostream>
using namespace std;

bool canPlace(int board[][9],int i,int j,int num)
{
    for(int x=0;x<9;x++)
    {
        if(board[i][x]==num||board[x][j]==num) return false;
    }
    int sx=(i/3)*3;
    int sy=(j/3)*3;
    for(int x=sx;x<sx+3;x++)
    {
        for(int y=sy;y<sy+3;y++)
        {
            if(board[x][y]==num) return false;
        }
    }
    return true;
}

bool solveSudoku(int board[][9],int i,int j)
{
    if(i==9)
    {return true;}
    if (j==9)
    {
        return solveSudoku(board,i+1,0);
    }
    if(board[i][j]!=0)
    {
        return solveSudoku(board,i,j+1);
    }
    for(int num=1;num<=9;num++)
    {
        if(canPlace(board,i,j,num))
        {
            board[i][j]=num;
            if(solveSudoku(board,i,j+1))
            {
                return true;
            }
        }
    }
    board[i][j]=0;
    return false;
}


int main() {
    int board[][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    bool isSuccessful = solveSudoku(board, 0, 0);
    if (isSuccessful) {
cout << "dfd";
    }
    else {
        cout << "Hey man! get it solved from someone else!";
    }
}