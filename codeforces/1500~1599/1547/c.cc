#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);

  int k = 0, n = 0, m = 0;
  cin >> k >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  int total = n + m;
  int current = k;
  vector<int> ans;
  for (int k = 0, i = 0, j = 0; k < total; ++k) {
    if (i < n && a[i] <= current) {
      if (a[i] == 0) current++;
      ans.push_back(a[i]);
      i++;
    } else if (j < m && b[j] <= current) {
      if (b[j] == 0) current++;
      ans.push_back(b[j]);
      j++;
    } else {
      cout << "-1" << endl;
      return;
    }
  }

  for (int e : ans) {
    cout << e << " ";
  }
  cout << endl;
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
