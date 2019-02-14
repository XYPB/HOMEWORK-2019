#include<vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) 
{
        int list[9][2] = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        for (int i = 0; i < 9; i++)
        {
            bool ex1[10] = {0};
            bool ex2[10] = {0};
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.' && ex1[board[i][j] - '0'])
                    return false;
                else if (board[i][j] != '.')
                    ex1[board[i][j] - '0'] = true;
                if (board[j][i] != '.' && ex2[board[j][i] - '0'])
                    return false;
                else if (board[j][i] != '.')
                    ex2[board[j][i] - '0'] = true;
            }
        }
        for (int s = 0; s < 9; s++)
        {
            bool ex3[10] = {0};
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3;j++)
                {
                    if (board[list[s][0] + i][list[s][1] + j] != '.' && ex3[board[list[s][0] + i][list[s][1] + j] - '0'])
                        return false;
                    else if (board[list[s][0] + i][list[s][1] + j] != '.')
                        ex3[board[list[s][0] + i][list[s][1] + j] - '0'] = true;
                }
            }
        }
        return true;
    }

int list[9][2] = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
vector<vector<char>> trueBoard;

void solver(vector<vector<char>> board, int pos)
{
    if (pos == 81)
    {
        trueBoard = board;
        return;
    }
    while (board[pos / 9][pos - (pos / 9) * 9] != '.')
        ++pos;
    int row = pos / 9;
    int col = pos - row * 9;
    bool validNum[10] = {1};
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] != '.')
        {
            if (validNum[board[row][i] - '0'])
                validNum[board[row][i] - '0'] = false;
        }
        if (board[i][col] != '.')
        {
            if (validNum[board[i][col]] - '0')
                validNum[board[row][i] - '0'] = false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (row - list[i][0] < 3 && col - list[i][1] < 3)
        {
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (board[list[i][0] + x][list[i][1] + y] != '.')
                    {
                        if (validNum[board[list[i][0] + x][list[i][1] + y] - '0'])
                            validNum[board[list[i][0] + x][list[i][1] + y] - '0'] = false;
                    }
                }
            }
            break;
        }
    }
	for (int i = 1; i <= 9; i++)
	{
        if (validNum[i])
        {
            board[row][col] = i +'0';
            solver(board, pos + 1);
        }
    }
    return;
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board, 0);
        board = trueBoard;
    }
};