#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;


pair<int, int> EndPosition(int N, int R, int C, int Sr, int Sc, string instructions)
{

    // TODO: implement this method to return the row and column where the robot
    // finishes.
    //map represents the row and visited columns
    map<int, set<int>> m;
    pair<int, int> p;
    p = make_pair(Sr - 1, Sc - 1);
    if (instructions.length())
    { 
        m[p.first].insert(p.second);

        for (size_t i = 0; i < instructions.length(); i++)
        {
            if (instructions[i] == 'W')
            {
                // check if the next column exists in the set
                while (m[p.first].find(p.second - 1) != m[p.first].end())
                {
                    p.second--;
                }
                m[p.first].insert(p.second - 1);
                p.second--;
            }
            else if (instructions[i] == 'E')
            {
                // check if the next column exists in the set
                while (m[p.first].find(p.second + 1) != m[p.first].end())
                {
                    p.second++;
                }
                m[p.first].insert(p.second + 1);
                p.second++;
            }
            else if (instructions[i] == 'N')
            {
                //check if the next row exists in the map
                while (m[p.first - 1].find(p.second) != m[p.first - 1].end())
                {
                    p.first--;
                }
                m[p.first - 1].insert(p.second);
                p.first--;
            }
            else if (instructions[i] == 'S')
            {
                //check if the next row exists in the map
                while (m[p.first + 1].find(p.second) != m[p.first + 1].end())
                {
                    p.first++;
                }
                m[p.first + 1].insert(p.second);
                p.first++;
            }
        }
    }

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
