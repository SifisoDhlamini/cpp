#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int maxVowels(string s, int k)
{
    int count = 0;
    int max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            count++;
        }
        if (i >= k)
        {
            if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u')
            {
                count--;
            }
        }
        max = max > count ? max : count;
    }
    return max;
}

int main()
{
    string s = "abciiidef";
    int k = 3;
    cout << maxVowels(s, k) << endl;
    return 0;
}