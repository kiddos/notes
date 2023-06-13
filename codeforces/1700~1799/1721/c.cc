#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<int> index(n);
  iota(index.begin(), index.end(), 0);
  sort(index.begin(), index.end(), [&](int i1, int i2) {
    return a[i1] < a[i2];
  });

  multiset<int> s(b.begin(), b.end());

  vector<int> dmin(n), dmax(n);
  dmax[index.back()] = *s.rbegin() - a[index.back()];
  for (int i = n-2; i >= 0; --i) {
    auto it = s.lower_bound(a[index[i+1]]);
    s.erase(it);
    dmax[index[i]] = *s.rbegin() - a[index[i]];
  }

  s = multiset<int>(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    auto it = s.lower_bound(a[index[i]]);
    dmin[index[i]] = *it - a[index[i]];
  }

  for (int i = 0; i < n; ++i) {
    cout << dmin[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << dmax[i] << " ";
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
