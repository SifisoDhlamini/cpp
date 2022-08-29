#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Write a function that takes a rectangular board with only +'s and 0's, and returns two collections:
* one containing all of the row numbers whose row is completely passable by snakes, and
* the other containing all of the column numbers where the column is completely passable by snakes.
Sample Inputs:
board1 = [['+', '+', '+', '0', '+', '0', '0'],
['0', '0', '0', '0', '0', '0', '0'],
['0', '0', '+', '0', '0', '0', '0'],
['0', '0', '0', '0', '+', '0', '0'],
['+', '+', '+', '0', '0', '0', '+']]
board2 = [['+', '+', '+', '0', '+', '0', '0'],
['0', '0', '0', '0', '0', '+', '0'],
['0', '0', '+', '0', '0', '0', '0'],
['0', '0', '0', '0', '+', '0', '0'],
['+', '+', '+', '0', '0', '0', '+']]
board3 = [['+', '+', '+', '0', '+', '0', '0'],
['0', '0', '0', '0', '0', '0', '0'],
['0', '0', '+', '+', '0', '+', '0'],
['0', '0', '0', '0', '+', '0', '0'],
['+', '+', '+', '0', '0', '0', '+']]
board4 = [['+']]
All test cases:
findPassableLanes(board1) => Rows: [1], Columns: [3, 5]
findPassableLanes(board2) => Rows: [], Columns: [3]
findPassableLanes(board3) => Rows: [1], Columns: []
findPassableLanes(board4) => Rows: [], Columns: []
*/

vector<vector<int>> findPassableLanes(vector<vector<char>> &board)
{
    vector<vector<int>> result;
    int rows = board.size();
    int cols = board[0].size();
    vector<int> row;
    vector<int> col;
    // check if all columns of row i are passable ('0')
    for (int i = 0; i < rows; i++)
    {
        if (all_of(board[i].begin(), board[i].end(), [](int i){ return i == '0'; }))
        {
            row.push_back(i);
        }
    }
    // check if all rows of column j are passable ('0')
    for (int j = 0; j < cols; j++)
    {
        if (all_of(board.begin(), board.end(), [j](vector<char> &v){ return v[j] == '0'; }))
        {
            col.push_back(j);
        }
    }
    result.push_back(row);
    result.push_back(col);
    return result;
}

int main()
{
    vector<vector<char>> board1{{'+', '+', '+', '0', '+', '0', '0'},
                                {'0', '0', '0', '0', '0', '0', '0'},
                                {'0', '0', '+', '0', '0', '0', '0'},
                                {'0', '0', '0', '0', '+', '0', '0'},
                                {'+', '+', '+', '0', '0', '0', '+'}};
    vector<vector<char>> board2{{'+', '+', '+', '0', '+', '0', '0'},
                                {'0', '0', '0', '0', '0', '+', '0'},
                                {'0', '0', '+', '0', '0', '0', '0'},
                                {'0', '0', '0', '0', '+', '0', '0'},
                                {'+', '+', '+', '0', '0', '0', '+'}};
    vector<vector<char>> board3{{'+', '+', '+', '0', '+', '0', '0'},
                                {'0', '0', '0', '0', '0', '0', '0'},
                                {'0', '0', '+', '+', '0', '+', '0'},
                                {'0', '0', '0', '0', '+', '0', '0'},
                                {'+', '+', '+', '0', '0', '0', '+'}};
    vector<vector<char>> board4{{'+'}};

    vector<int> rows;
    vector<int> cols;
    vector<vector<int>> boards = {rows, cols};

    boards = findPassableLanes(board1);

    // board1
    cout << "Rows: [";
    for (size_t i = 0; i < boards[0].size(); i++)
    {
        cout << boards[0][i];
        if (i < boards[0].size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "], Columns: [";
    for (size_t i = 0; i < boards[1].size(); i++)
    {
        cout << boards[1][i];
        if (i < boards[1].size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    boards.clear();
    // board2
    boards = findPassableLanes(board2);
    cout << "Rows: [";
    for (size_t i = 0; i < boards[0].size(); i++)
    {
        cout <<boards[0][i];
        if(i < boards[0].size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "], Columns: [";
    for (size_t i = 0; i < boards[1].size(); i++)
    {
        cout << boards[1][i];
        if (i < boards[1].size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    boards.clear();
    // board3
    boards = findPassableLanes(board3);
    cout << "Rows: [";
    for (size_t i = 0; i < boards[0].size(); i++)
    {
        cout << boards[0][i];
        if (i < boards[0].size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "], Columns: [";
    for (size_t i = 0; i < boards[1].size(); i++)
    {
        cout << boards[1][i];
        if (i < boards[1].size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    boards.clear();
    // board4
    boards = findPassableLanes(board4);
    cout << "Rows: [";
    for (size_t i = 0; i < boards[0].size(); i++)
    {
        cout << boards[0][i];
        if (i < boards[0].size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "], Columns: [";
    for (size_t i = 0; i < boards[1].size(); i++)
    {
        cout << boards[1][i];
        if (i < boards[1].size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}