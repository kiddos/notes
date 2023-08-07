#include <bits/stdc++.h>

using namespace std;

void solve() {
  string blank;
  getline(cin, blank);

  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> u(n+1);
  for (int i = 1; i <= n; ++i) cin >> u[i];

  map<int, int> min_index, max_index;
  for (int i = 1; i <= n; ++i) {
    if (!min_index.count(u[i])) {
      min_index[u[i]] = i;
    }
    max_index[u[i]] = max(max_index[u[i]], i);
  }

  for (int i = 0; i < k; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    if (!min_index.count(a) || !max_index.count(b)) {
      cout << "NO" << endl;
    } else {
      int a_index = min_index[a];
      int b_index = max_index[b];
      if (a_index < b_index) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
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
