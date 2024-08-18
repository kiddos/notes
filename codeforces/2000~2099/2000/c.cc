#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)  {
    cin >> a[i];
  }
  int m = 0;
  cin >> m;

  auto check = [&](string& s) -> bool {
    if ((int) s.length() != n) {
      return false;
    }

    constexpr int INF = numeric_limits<int>::min();
    vector<int> m1(26, INF);
    map<int, int> m2;
    for (int j = 0; j < n; ++j) {
      int c = s[j]-'a';
      if (m1[c] != INF && m1[c] != a[j]) {
        return false;
      }
      m1[c] = a[j];
      if (m2.count(a[j]) && m2[a[j]] != c) {
        return false;
      }
      m2[a[j]] = c;
    }
    return true;
  };

  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    if (check(s)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
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
