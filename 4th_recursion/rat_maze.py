def solve_maze(maze,i,j,end_i,end_j,move):
    if(i==end_i and end_j==j):
        maze[i][j]=move
        for x in maze:
            print(x)
        return True
    if(i+1<=end_i and maze[i+1][j]==0):
        maze[i][j]=move
        if(solve_maze(maze,i+1,j,end_i,end_j,move+1)):
            return True
        maze[i][j]=0
        return False
    if(j+1<=end_j and maze[i][j+1]==0):
        maze[i][j]=move
        if(solve_maze(maze,i,j+1,end_i,end_j,move+1)):
            return True
        maze[i][j]=0
        return False
maze=[
[0, 'x', 'x', 'x'], 
[0, 0, 'x', 0], 
['x', 0, 'x', 'x'], 
[0, 0, 0, 0]
]
sol=[[]]
solve_maze(maze,0,0,3,3,0)