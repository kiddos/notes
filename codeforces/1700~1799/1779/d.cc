#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a, vector<int>& b, int n, vector<int>& x, int m) {
  for (int i = 0; i < n; ++i) {
    if (b[i] > a[i]) {
      cout << "NO" << endl;
      return;
    }
  }

  vector<int> remove;
  vector<int> s;
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && s.back() < b[i]) {
      s.pop_back();
    }
    if (a[i] == b[i]) continue;
    if (s.empty() || b[i] < s.back()) {
      remove.push_back(b[i]);
      s.push_back(b[i]);
    }
  }

  multiset<int> razor(x.begin(), x.end());
  for (int r : remove) {
    auto p = razor.find(r);
    if (p == razor.end()) {
      cout << "NO" << endl;
      return;
    }
    razor.erase(p);
  }

  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int m = 0;
    cin >> m;
    vector<int> x(m);
    for (int i = 0; i < m; ++i) cin >> x[i];

    solve(a, b, n, x, m);
  }
  return 0;
}
