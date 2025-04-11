#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_universal(const string& s) {
  string r(s.rbegin(), s.rend());
  return s < r;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string r;
  cin >> r;

  if (is_universal(r)) {
    cout << "YES" << endl;
  } else {
    if (k == 0) {
      cout << "NO" << endl;
    } else {
      unordered_set<char> chars(r.begin(), r.end());
      if (chars.size() == 1) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
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
