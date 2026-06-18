#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int min_ops(const string& t, const string& s) {
  bool is_subseq = false;
  int n = t.length(), m = s.length();
  for (int i = 0, j = 0; i < n; ++i) {
    if (t[i] == s[j]) {
      j++;
    }
    if (j == m) {
      is_subseq = true;
      break;
    }
  }
  if (is_subseq) {
    return n - m;
  }
  return numeric_limits<int>::max();
}

void solve() {
  i64 n = 0;
  cin >> n;

  string s0 = to_string(n);
  int ans = numeric_limits<int>::max();
  for (i64 d = 1; d * d <= n; ++d) {
    i64 sq = d*d;
    string s = to_string(sq);
    int ops = min_ops(s0, s);
    ans = min(ans, ops);
  }
  if (ans == numeric_limits<int>::max()) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
