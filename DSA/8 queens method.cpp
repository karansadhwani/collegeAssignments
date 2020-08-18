/*
                                       Assignment No.9
STATEMENT:
A classic problem that can be solve by backtracking is called Eight queens problem,which comes from the game chess the chess board consist of 64 sqare arranged in an 8 by 8 grid. The board normally alternates black nad white sqaure, but this is revelent for the present problem. the queue can move as far as wants in any direction , as long as she follows the straight line, vertically horizontly, or diagonaly. Write C++ program with recursive function for genrating all possible configuration for 4-queens problem.
------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 4
using namespace std;


void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)

    {

        for (int j = 0; j < N; j++)

            cout<<board[i][j]<<"  ";

        cout<<endl;

    }
}


bool isSafe(int board[N][N], int row, int col)

{

    int i, j;

    for (i = 0; i < col; i++)

    {

        if (board[row][i])
            return false;

    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)

    {

       if (board[i][j])
          return false;
    }


    for (i = row, j = col; j >= 0 && i < N; i++, j--)

    {

        if (board[i][j])

            return false;

    }

 

    return true;

}


bool solveNQUtil(int board[N][N], int col)

{

    if (col >= N)

        return true;

    for (int i = 0; i < N; i++)

    {

        if ( isSafe(board, i, col) )

        {

            board[i][col] = 1;

            if (solveNQUtil(board, col + 1) == true)

                return true;

            board[i][col] = 0;

        }

    }

    return false;

}


bool solveNQ()

{
    int board[N][N] = {0};
    if (solveNQUtil(board, 0) == false)
    {
        cout<<"Solution does not exist"<<endl;
        return false;

    }

    printSolution(board);

    return true;

}


int main()

{

    solveNQ();

    return 0;

}

/*OUTPUT-----------------------------------------

student@L1LAB-Desktop:~$ gedit assignment_9.cpp
student@L1LAB-Desktop:~$ g++ assignment_9.cpp -o a
student@L1LAB-Desktop:~$ ./a
0  0  1  0  
1  0  0  0  
0  0  0  1  
0  1  0  0  

------------------------------------------------------------------------------*/