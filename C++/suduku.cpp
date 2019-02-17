#include<vector>
using namespace std;

int listt[9][2] = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};

bool solver(vector<vector<char>>& board, int pos)
{
    if (pos >= 81)
    {
        return true;
    }
    while (board[pos / 9][pos - (pos / 9) * 9] != '.' && pos < 80)
        ++pos;
    int row = pos / 9;
    int col = pos - row * 9;
    bool validNum[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] != '.')
        {
            if (validNum[board[row][i] - '0'])
                validNum[board[row][i] - '0'] = false;
        }
        if (board[i][col] != '.')
        {
            if (validNum[board[i][col] - '0'])
                validNum[board[i][col] - '0'] = false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (row - listt[i][0] < 3 && col - listt[i][1] < 3)
        {
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (board[listt[i][0] + x][listt[i][1] + y] != '.')
                    {
                        if (validNum[board[listt[i][0] + x][listt[i][1] + y] - '0'])
                            validNum[board[listt[i][0] + x][listt[i][1] + y] - '0'] = false;
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
            if (solver(board, pos + 1))
                return true;
        }
    }
    return false;
}


void solveSudoku(vector<vector<char>>& board) 
{
    solver(board, 0);
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    return 0;
}
