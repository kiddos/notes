#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  vector<int> a_index(n+1);
  for (int i = 1; i <= n; ++i) {
    a_index[a[i]] = i;
  }

  int max_seen_so_far = -1;
  for (int i = 1; i <= n; ++i) {
    int i1 = a_index[b[i]];
    if (i1 < max_seen_so_far) {
      cout << "NO" << endl;
      return;
    }
    max_seen_so_far = max(max_seen_so_far, i1);
  }
  cout << "YES" << endl;
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
