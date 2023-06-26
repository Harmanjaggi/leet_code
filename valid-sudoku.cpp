#include "iostream"
#include "vector"

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    if (board.size() != 9 || board[0].size() != 9)
        return false;
    vector<vector<bool>> col_check(9, vector<bool>(9));
    vector<vector<bool>> box_check(9, vector<bool>(9));
    for (int r = 0; r < 9; r++)
    {
        vector<bool> row_check(9);
        for (int c = 0; c < 9; c++)
        {
            if (board[r][c] == '.')
                continue;
            int ele_num = board[r][c] - '1';
            // row
            if (row_check[ele_num])
            {
                cout << "row_check";
                return false;
            }
            row_check[ele_num] = true;
            // column
            if (col_check[c][ele_num])
            {
                cout << "col_check";
                return false;
            }
            col_check[c][ele_num] = true;
            // box
            int box_num = r / 3 + c / 3;
            if (box_check[box_num][ele_num])
            {
                cout << "box_check";
                return false;
            }
            box_check[box_num][ele_num] = true;
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board(9, vector<char>(9));
    for (auto &row : board)
        for (char &ele : row)
            cin >> ele;
    isValidSudoku(board);
}