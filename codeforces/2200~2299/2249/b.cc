#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

void solve() {
  int n = 0;
  cin >> n;
  int m = n-1;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  vector<i64> f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  vector<pair<int,int>> p;
  int idx = 0;
  while (idx < m) {
    int j = idx;
    while (j+1 < m && a[j+1] == a[j]) {
      j++;
    }
    int len = j-idx+1;
    p.push_back({a[idx], len});

    idx = j+1;
  }

  int max_index = max_element(p.begin(), p.end()) - p.begin();
  int l = max_index-1, r = max_index+1;
  int size = p.size();

  int current = p[max_index].first;
  if (current != n-1) {
    cout << "0" << endl;
    return;
  }

  i64 ans = 2;
  int spot = p[max_index].second - 1;

  while (l >= 0 || r < size) {
    int left = l >= 0 ? p[l].first : -1;
    int right = r < size ? p[r].first : -1;
    if (left > right) {
      if (left >= current) {
        cout << "0" << endl;
        return;
      }

      for (int k = current-1; k > left; --k) {
        ans *= spot;
        ans %= MOD;
        spot--;
      }

      spot += p[l].second-1;

      current = left;
      l--;
    } else {
      if (right >= current) {
        cout << "0" << endl;
        return;
      }

      for (int k = current-1; k > right; --k) {
        ans *= spot;
        ans %= MOD;
        spot--;
      }

      spot += p[r].second-1;

      current = right;
      r++;
    }
  }

  ans *= f[current-1];
  ans %= MOD;
  cout << ans << endl;
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
