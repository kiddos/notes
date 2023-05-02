#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int max_size = m + n + 2;
  vector<int> appear(max_size, -1);
  vector<int> count(max_size);
  for (int ai : a) {
    appear[ai] = 0;
  }

  for (int i = 0; i < m; ++i) {
    int p = 0, v = 0;
    cin >> p >> v;
    int x = a[p-1];
    count[x] += i - appear[x] + 1;
    a[p-1] = v;
    appear[x] = -1;
    appear[v] = i+1;
  }
  for (int x = 1; x < max_size; ++x) {
    if (appear[x] >= 0) {
      count[x] += m+1 - appear[x];
    }
  }

  // for (int x = 1; x < max_size; ++x) {
  //   cout << "x=" << x << ": appears " << count[x] << endl;
  // }

  ll ans = 0;
  for (int x = 1; x < max_size; ++x) {
    ans += (m+1) * m / 2 - (m+1-count[x]) * (m-count[x]) / 2;
  }
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
