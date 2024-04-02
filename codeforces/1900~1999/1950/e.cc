#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  
  vector<int> lens;
  for (int d = 1; d *d <= n;++d) {
    if (n % d == 0) {
      lens.push_back(d);
      lens.push_back(n / d);
    }
  }

  auto diff = [&](const string& s1, const string& s2) -> int {
    int l = s1.length();
    int d = 0;
    for (int i = 0; i < l; ++i) {
      d += s1[i] != s2[i];
    }
    return d;
  };

  auto possible = [&](const string& x) -> bool {
    const int l = x.length();
    int total = 0;
    for (int i = 0; i < n; i += l) {
      string s2 = s.substr(i, l);
      int d = diff(s2, x);
      if (d > 1) return false;
      if (d == 1) total++;
    }
    return total <= 1;
  };

  sort(lens.begin(), lens.end());
  for (int len : lens) {
    if (len == n) {
      cout << n << endl;
      return;
    }
    if (possible(s.substr(0, len)) || possible(s.substr(len, len))) {
      cout << len << endl;
      return;
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
