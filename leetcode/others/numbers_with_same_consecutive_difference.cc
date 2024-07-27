#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void generate(int num, int N, int K, vector<int>& ans) {
    if (N == 1) {
      ans.push_back(num);
    } else {
      int digit = num % 10;
      if (digit + K <= 9) generate(num * 10 + digit + K, N-1, K, ans);
      if (K != 0 && digit - K >= 0) generate(num * 10 + digit - K, N-1, K, ans);
    }
  }

  vector<int> numsSameConsecDiff(int N, int K) {
    if (N == 1) return { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> ans;
    for (int i = 1; i <= 9; ++i) {
      generate(i, N, K, ans);
    }
    return ans;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N = 0, K = 0;
    cin >> N >> K;
    vector<int> ans = Solution().numsSameConsecDiff(N, K);
    for (int a : ans) {
      cout << a << " ";
    }
    cout << endl;
  }
  return 0;
}
