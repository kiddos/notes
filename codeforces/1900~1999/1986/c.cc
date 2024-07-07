#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> ind(m);
  for (int i = 0; i < m; ++i) {
    cin >> ind[i];
    ind[i]--;
  }
  string c;
  cin >> c;

  sort(c.begin(), c.end());

  vector<int> counts(n);
  for (int i = 0; i < m; ++i) {
    counts[ind[i]]++;
  }
  
  for (int i = 0; i < n; ++i) {
    while (counts[i] > 1) {
      counts[i]--;
      c.pop_back();
    }
  }
  for (int i = n-1; i >= 0; --i) {
    if (counts[i] > 0) {
      s[i] = c.back();
      c.pop_back();
    }
  }

  cout << s << endl;
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
