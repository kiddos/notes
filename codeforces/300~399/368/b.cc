#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<int> s;
  vector<int> d(n);
  for (int i = n-1; i >= 0; --i) {
    s.insert(a[i]);
    d[i] = s.size();
  }

  for (int i = 0; i < m; ++i) {
    int l = 0;
    cin >> l;
    l--;
    cout << d[l] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
