
def canPlace(sudoku,i,j,num):

    for x in range(0,9):
        if(sudoku[i][x]==num or sudoku[x][j]==num):
            return False
    subrow=(int(i/3))*3
    subcol=(int(j/3))*3
    for x in range(subrow,subrow+3):
        for y in range(subcol,subcol+3):
            if(sudoku[x][y]==num): return False
    return True



def solve(sudoku,i,j):
    if(i==9):
        return True
    if(j==9):
        return solve(sudoku,i+1,0)
    if(sudoku[i][j]!=0):
        return solve(sudoku,i,j+1)
    for x in range(1,10):
        if(canPlace(sudoku,i,j,x)):
            sudoku[i][j]=x
            if(solve(sudoku,i,j+1)):
                return True
            sudoku[i][j]=0
    return False

sudoku=[[5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]
        ]
print(solve(sudoku,0,0))
for x in sudoku:
    print(x)
