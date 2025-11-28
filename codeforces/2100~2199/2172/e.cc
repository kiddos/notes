#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string compute_diff(const string& a, const string& b) {
  int same = 0;
  int len = a.length();
  for (int i = 0; i < len; ++i) {
    same += a[i] == b[i];
  }
  int diff = len - same;
  return to_string(same) + "A" + to_string(diff) + "B";
}

void solve() {
  int n = 0, j = 0, k = 0;
  cin >> n >> j >> k;
  string s = to_string(n);
  int t = 1;
  string a, b;
  do {
    if (t == j) {
      a = s;
    }
    if (t == k) {
      b = s;
    }
    t++;
  } while (next_permutation(s.begin(), s.end()));

  cout << compute_diff(a, b) << endl;
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
