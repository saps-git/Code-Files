#include<bits/stdc++.h>
using namespace std;

void printMaze(int** sol, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<sol[i][j]<<" ";
    }
    cout<<endl; 
}

void mazeHelp(int maze[][20], int n, int** sol, int x, int y)
{
    if(x == n-1 && y == n-1)
        printMaze(sol, n);
    if(x < 0 || x >= n || y < 0 || y >= n || sol[x][y] == 1)
        return;

    sol[x][y] = 1;
    mazeHelp(maze, n, sol, x-1, y);
    mazeHelp(maze, n, sol, x+1, y);
    mazeHelp(maze, n, sol, x, y-1);
    mazeHelp(maze, n, sol, x, y+1);
    sol[x][y] = 0;
}

void ratInMaze(int maze[][20], int n)
{
    int** sol = new int*[n];
    for(int i=0;i<n;i++)
        sol[i] = new int[n];

    mazeHelp(maze, n, sol, 0, 0);
    delete[] sol;
}

int main()
{
    int n = 3;
    int maze[][20] = {{1,0,1},{1,1,1},{1,1,1}};
    ratInMaze(maze, n);
}