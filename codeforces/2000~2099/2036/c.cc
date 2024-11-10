#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  set<int> indices;
  for (int i = 0; i <= n-4; ++i) {
    if (s.substr(i, 4) == "1100") {
      indices.insert(i);
    }
  }

  int q = 0;
  cin >> q;
  for (int k = 0; k < q; ++k) {
    int i = 0;
    char v = 0;
    cin >> i >> v;
    i--;
    s[i] = v;

    for (int j = max(i-3, 0); j <= i; ++j) {
      if (s.substr(j, 4) == "1100") {
        indices.insert(j);
      } else {
        indices.erase(j);
      }
    }

    if (indices.empty()) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
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
