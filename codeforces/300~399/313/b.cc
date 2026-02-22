#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> p(n);
  for (int i = 0; i < n-1; ++i) {
    if (s[i] == s[i+1]) {
      p[i]++;
    }
  }
  for (int i = 1; i < n; ++i) {
    p[i] += p[i-1];
  }

  int m = 0;
  cin >> m;
  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;

    int total = p[r-1];
    if (l > 0) {
      total -= p[l-1];
    }
    ans.push_back(total);
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
