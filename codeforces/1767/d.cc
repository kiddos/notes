#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
  int n = s.length();
  deque<int> x;
  int m = 1 << n;
  for (int i = 1; i <= m; ++i) x.push_back(i);

  int smaller = 0, larger = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      int k = 1 << smaller;
      while (k-- > 0) x.pop_back();
      smaller++;
    } else if (s[i] == '1') {
      int k = 1 << larger;
      while (k-- > 0) x.pop_front();
      larger++;
    }
    // for (int p : x) cout << p << " ";
    // cout << endl;
  }
  // cout << smaller << ", " << larger << endl;
  for (int p : x) cout << p << " ";
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  solve(s);
  return 0;
}

// 1 2 3 4 5 6 7 8
//
// 111
// 1. 2 3 4 5 6 7 8
// 2. 4 5 6 7 8
// 3. 8
// ans = 8
//
// 100
// 1. 2 3 4 5 6 7 8
// 2. 2 3 4 5 6 7
// 3. 2 3 4 5
// ans = 2 3 4 5
//
// 101
// 1. 2 3 4 5 6 7 8
// 2. 2 3 4 5 6 7
// 3. 4 5 6 7
// ans = 4 5 6 7
//
// 001
// 1. 1 2 3 4 5 6 7
// 2. 1 2 3 4 5
// 3. 2 3 4 5
// ans = 2 3 4 5
