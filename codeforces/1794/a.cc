#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(const string& s) {
  string r(s.rbegin(), s.rend());
  return r == s;
}

void solve() {
  int n = 0;
  cin >> n;
  int m = (n-1) * 2;
  vector<string> strs(m);
  for (int i = 0; i < m; ++i) cin >> strs[i];

  vector<string> starts, ends;
  for (string& a : strs) {
    int len = a.length();
    if (len == 1) starts.push_back(a);
    if (len == n-1) ends.push_back(a);
  }

  vector<array<int,4>> possible = {{0, 0, 1, 1}, {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 1, 0, 0}};
  for (array<int, 4>& index : possible) {
    auto [i1, i2, i4, i3] = index;
    string p1 = starts[i1] + ends[i2];
    string p2 = ends[i3] + starts[i4];
    if (p1 == p2) {
      if (is_palindrome(p1)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      return;
    }
  }
  assert(false);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
