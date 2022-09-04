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
    p = make_pair(Sr, Sc);
    if (instructions.length())
    { 
        m[p.first].insert(p.second);

        for (size_t i = 0; i < instructions.length(); i++)
        {
            if (instructions[i] == 'W')
            {                
                    // check if the next column exists in the set
                    if (get<1>(m[p.first].insert(p.second - 1)) == false)
                    {
                        // get the pointer of element (p.second - 1)
                        auto it = m[p.first].find(p.second - 1);
                        // get the element before (p.second - 1) if any
                        auto it2 = it--;
                        // get the difference between the two elements
                        int diff = *it - *it2;
                        while (diff == 1 && it2 != m[p.first].begin())
                        {
                            // get the element before (p.second - 1) if any
                            it = it2;
                            it2--;
                            // get the difference between the two elements
                            if (it2 != m[p.first].begin())
                                diff = *it - *it2;
                        }
                        p.second = *it - 1;
                        m[p.first].insert(p.second);
                    }
                    else
                    {
                        m[p.first].insert(p.second - 1);
                        p.second--;
                    }
                
            }
            else if (instructions[i] == 'E')
            {
                // check if the next column exists in the set
                if (get<1>(m[p.first].insert(p.second + 1)) == false)
                {
                    // get the pointer of element (p.second + 1)
                    auto it = m[p.first].find(p.second + 1);
                    // get the element after (p.second + 1) if any
                    auto it2 = it++;
                    // get the difference between the two elements
                    int diff = *it2 - *it;
                    while (diff == 1 && it2 != m[p.first].end())
                    {
                        // get the element after (p.second + 1) if any
                        it = it2;
                        it2++;
                        // get the difference between the two elements
                        if (it2 != m[p.first].end())
                            diff = *it2 - *it;
                    }
                    p.second = *it2 + 1;
                    m[p.first].insert(p.second);
                }
                else
                {
                    m[p.first].insert(p.second + 1);
                    p.second++;
                }
            }
            else if (instructions[i] == 'N')
            {
                //check if that column and row exist
                if (get<1>(m[p.first - 1].insert(p.second)) == false){
                    //get the value of p.first - 1
                    int currentKey = p.first - 1;
                    //get the pointer of element (p.first - 1)
                    auto it = m.find(currentKey);
                    //get the element after (p.first - 1) if any
                    auto it2 = it--;
                    while ((it != m.begin()) && (get<1>(m[it2->first].insert(p.second)) == false))
                    {
                        //get the element after (p.first - 1) if any
                        it = it2;
                        it2--;
                    }
                    p.first = it->first - 1;
                    m[p.first].insert(p.second);     
                    
                }
                else
                {
                    m[p.first - 1].insert(p.second);
                    p.first--;
                }
            }
            else if (instructions[i] == 'S')
            {
                //check if that column and row exist
                if (get<1>(m[p.first + 1].insert(p.second)) == false){
                    //get the value of p.first + 1
                    int currentKey = p.first + 1;
                    //get the pointer of element (p.first + 1)
                    auto it = m.find(currentKey);
                    //get the element after (p.first + 1) if any
                    auto it2 = it++;
                    while ((it != m.end()) && (get<1>(m[it2->first].insert(p.second)) == false))
                    {
                        //get the element after (p.first + 1) if any
                        it = it2;
                        it2++;

                    }
                    p.first = it->first + 1;
                    m[p.first].insert(p.second);
                }
                else
                {
                    m[p.first + 1].insert(p.second);
                    p.first++;
                }
            }
        }
    }
    return p;
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
