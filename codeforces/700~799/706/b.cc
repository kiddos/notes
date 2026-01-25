#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int m = 0;
    cin >> m;
    auto it = upper_bound(x.begin(), x.end(), m);
    int count = it - x.begin();
    cout << count << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
