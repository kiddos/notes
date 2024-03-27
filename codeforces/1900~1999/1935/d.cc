#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// x - y == 1 
// (0, 1), (1, 2), (2, 3)
// => (c+1 - 1)
// x - y == 2
// (0, 2), (1, 3)
// => (c+1 - 2)
// x - y == 3
// (0, 3)
// => (c+1 - 3)

// => (c+1 - s)


// x + y == 1
// (0, 1)
// => 1 / 2 + 1
// x + y == 2
// (0, 2), (1, 1)
// => 2 / 2 + 1
// x + y == 3
// (0, 3), (1, 2)
// => 3 / 2 + 1

// => (s / 2) + 1


// y - x == s1 and x + y == s2
// => 2*y = s1 + s2
// => y = (s1 + s2) / 2
// => x = (s1 + s2) / 2 - s1 = (s2 - s1) / 2

// for x,y to have solution: (s1 + s2), (s2 - s1) must be divisible by 2
// and s2 >= s1

void solve() {
  i64 n = 0, c = 0;
  cin >> n >> c;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  i64 total = (c+1 + 1) * (c+1) / 2;
  i64 sub = 0;
  i64 add = 0;
  for (int i = 0; i < n; ++i) {
    sub += (c+1 - s[i]);
    add += (s[i] / 2) + 1;
  }

  // cout << "total=" << total << endl;
  // cout << "sub=" << sub << endl;
  // cout << "add=" << add << endl;

  i64 both = 0;
  vector<int> count(2);
  for (int i = 0; i < n; ++i) {
    int m2 = s[i] % 2;
    count[m2]++;
    both += count[m2];
  }

  // cout << "both=" << both << endl;

  i64 ans = total - sub - add + both;
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}