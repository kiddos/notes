#include <bits/stdc++.h>

using namespace std;

int compute_mex(const vector<int>& a) {
  vector<int> b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());

  int m = b.size();
  for (int i = 0; i < m; ++i) {
    if (b[i] != i) {
      return i;
    }
  }
  return m;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  map<int, int> left, right;
  for (int i = 0; i < n; ++i) {
    right[a[i]] = i;
    if (!left.count(a[i])) left[a[i]] = i;
  }

  int mex = compute_mex(a);
  if (left.count(mex + 1)) {
    int L = left[mex + 1], R = right[mex + 1];
    for (int i = L; i <= R; ++i) {
      a[i] = mex;
    }
    int mx = compute_mex(a);
    if (mx == mex + 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] > mex || (left[a[i]] != right[a[i]])) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
