#include <iostream>
#include <vector>
using namespace std;

int NumberOfRecordBreakingDays(int numberOfDays, vector<int> visitors) {
  // TODO: Complete this function to get the number of record breaking days
  int count = 0;
  int largest = 0;
  for (int i = 0; i < numberOfDays; i++)
  {
    if ((i == 0 && visitors[i] > largest) or (visitors[i] > largest)) {
      if (visitors[i] > largest)
      {
        largest = visitors[i];
      }
      if ((i == numberOfDays - 1) or (i < numberOfDays - 1 && visitors[i] > visitors[i + 1]))
      {
        count++;
      }
    }
  }

  return count;
}

int main() {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
      cin >> V[i];
    }
    cout << "Case #" << tc << ": " << NumberOfRecordBreakingDays(N, V) << endl;
  }
  return 0;
}
