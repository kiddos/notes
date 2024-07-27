#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    if (n == 0) return 0;

    vector<int> count(n+1);
    for (int c : citations) {
      if (c >= n) count[n]++;
      else count[c]++;
    }

    int total = 0;
    for (int h = n; h >= 0; --h) {
      total += count[h];
      if (total >= h) return h;
    }
    return 0;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> citation(n);
    for (int i = 0; i < n; ++i) cin >> citation[i];

    int ans = Solution().hIndex(citation);
    cout << "h index: " << ans << endl;
  }
  return 0;
}
