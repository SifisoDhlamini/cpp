#include <iostream>
#include <string>
#include <utility>
#include<algorithm>
#include<vector>
using namespace std;

void west(vector<vector<int>>& v, pair<int, int>& p){
    //check while position pair in vector == 1 move left
    while (v[p.first][p.second] == 1){
        p.second--;
    }
    v[p.first][p.second] = 1;
}

void east(vector<vector<int>>& v, pair<int, int>& p){
    //check while position pair in vector == 1 move right
    while (v[p.first][p.second] == 1){
        p.second++;
    }
    v[p.first][p.second] = 1;
}

void north(vector<vector<int>>& v, pair<int, int>& p){
    //check while position pair in vector == 1 move up
    while (v[p.first][p.second] == 1){
        p.first--;
    }
    v[p.first][p.second] = 1;
}

void south(vector<vector<int>>& v, pair<int, int>& p){
    //check while position pair in vector == 1 move down
    while (v[p.first][p.second] == 1){
        p.first++;
    }
    v[p.first][p.second] = 1;
}



pair<int, int> EndPosition(int N, int R, int C, int Sr, int Sc, string instructions)
{
    pair<int, int> p = {0, 0};
    // TODO: implement this method to return the row and column where the robot
    // finishes.
    vector<vector<int>> v(N, vector<int>(N, 0));
    v[Sr - 1][Sc - 1] = 1;
    p.first = Sr - 1;
    p.second = Sc - 1;
    for (size_t i = 0; i < instructions.size(); i++)
    {
        if (instructions[i] == 'W')
        {
            west(v, p);
        }
        else if (instructions[i] == 'E')
        {
            east(v, p);
        }
        else if (instructions[i] == 'N')
        {
            north(v, p);
        }
        else if (instructions[i] == 'S')
        {
            south(v, p);
        }
    }
    if (p.first == 0 && p.second == 0)
        return p;
    return {p.first + 1, p.second + 1};
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int N, R, C, Sr, Sc;
        string instructions;
        cin >> N >> R >> C >> Sr >> Sc >> instructions;
        auto ans = EndPosition(N, R, C, Sr, Sc, instructions);
        cout << "Case #" << t << ": " << ans.first << " " << ans.second << endl;
    }
}
