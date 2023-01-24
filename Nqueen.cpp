#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 8
void showboard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
                cout << "Q    ";
            else
                cout << "_    ";
        }
        cout << endl;
    }
}
bool canIplaceQueen(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}
bool placeincol(int board[N][N], int col)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if (canIplaceQueen(board, i, col))
        {
            board[i][col] = 1;
            //showboard(board);
            if (placeincol(board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
void solveNq()
{

    int board[N][N];
    memset(board,0,sizeof(board));

    placeincol(board, 0); // 0 column
    showboard(board);
}

int main()
{
    solveNq();
    return 0;
}