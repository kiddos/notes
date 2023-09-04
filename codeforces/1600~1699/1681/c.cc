#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<pair<int,int>> ans;
  vector<int> c = a;
  sort(c.begin(), c.end());
  for (int i = 0; i < n; ++i) {
    if (a[i] != c[i]) {
      for (int j = i+1; j < n; ++j) {
        if (a[j] == c[i]) {
          swap(a[i], a[j]);
          swap(b[i], b[j]);
          ans.emplace_back(i+1, j+1);
          break;
        }
      }
    }
  }

  c = b;
  sort(c.begin(), c.end());
  for (int i = 0; i < n; ++i) {
    if (b[i] != c[i]) {
      for (int j = i+1; j < n; ++j) {
        if (b[j] == c[i]) {
          swap(a[i], a[j]);
          swap(b[i], b[j]);
          ans.emplace_back(i+1, j+1);
          break;
        }
      }
    }
  }

  for (int i = 1; i < n; ++i) {
    if (a[i-1] > a[i]) {
      cout << "-1" << endl;
      return;
    }
  }

  cout << ans.size() << endl;
  for (auto& [i, j] : ans) {
    cout << i << " " << j << endl;
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
