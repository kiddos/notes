#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;

  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  map<int, int> index;
  for (int i = 1; i <= n; ++i) {
    if (index.count(x - a[i])) {
      cout << index[x-a[i]] << " " << i << endl;
      return;
    }
    index[a[i]] = i;
  }

  cout << "IMPOSSIBLE" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
