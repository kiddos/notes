#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    int m = s.length();
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
      if (i == 0 || s[i] != s[i-1]) {
        ans.push_back(i+1);
      } else {
        ans.push_back(ans.back());
      }
    }

    for (int a : ans) cout << a << " ";
    cout << endl;
  }
  return 0;
}

// 5
// 001110
// 1, 2 => (1)
// 1, 2, 3 => (1)
// 1, 2, 3, 4 => (2, 3, 4)
// 1, 2, 3, 4, 5 => (3, 4, 5)
// 1, 2, 3, 4, 5, 6 => (6, 5, 4)
// 1, 2, 3, 4, 5, 6, 7 => (1, 2, 3, 4, 5, 6)
//
// 1 1 3 3 3 6
