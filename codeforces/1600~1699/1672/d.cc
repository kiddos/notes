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

  map<int,int> pool;
  int i = n-1, j = n-1;
  while (i >= 0 && j >= 0) {
    if (j+1 < n && b[j+1] == b[j]) {
      pool[b[j]]++;
      --j;
      continue;
    }

    while (i > 0 && a[i] != b[j])  {
      if (pool[a[i]] == 0) {
        cout << "NO" << endl;
        return;
      }

      pool[a[i]]--;
      --i;
    }
    --i;
    --j;
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
