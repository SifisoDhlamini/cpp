#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void west(set<pair<int, int>> &v, pair<int, int> &p)
{
    // check while position pair exists move left
    while (v.find(p) != v.end())
    {
        --p.second;
    }

    v.insert(p);
}

void east(set<pair<int, int>> &v, pair<int, int> &p)
{
    // check while position pair exists move right
    while (v.find(p) != v.end())
    {
        ++p.second;
    }

    v.insert(p);
}

void north(set<pair<int, int>> &v, pair<int, int> &p)
{
    // check while position pair exists move up
    while (v.find(p) != v.end())
    {
        --p.first;
    }
    v.insert(p);
}

void south(set<pair<int, int>> &v, pair<int, int> &p)
{
    // check while position pair exists move down
    while (v.find(p) != v.end())
    {
        ++p.first;
    }
    v.insert(p);
}

pair<int, int> EndPosition(int N, int R, int C, int Sr, int Sc, string instructions)
{

    // TODO: implement this method to return the row and column where the robot
    // finishes.
    set<pair<int, int>> v;
    pair<int, int> p;
    if (instructions.length())
    {
        p = make_pair(Sr - 1, Sc - 1);
        v.insert(p);

        for (size_t i = 0; i < instructions.length(); i++)
        {
            if (instructions[i] == 'W')
            {
                p.second--;
                west(v, p);
                ;
            }
            else if (instructions[i] == 'E')
            {
                p.second++;
                east(v, p);
            }
            else if (instructions[i] == 'N')
            {
                p.first--;
                north(v, p);
            }
            else if (instructions[i] == 'S')
            {
                p.first++;
                south(v, p);
            }
        }
    }

    // if (p.first == Sr && p.second == Sc)
    //     return {Sr, Sc};
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
