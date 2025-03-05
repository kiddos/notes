#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_magical(vector<int>& a) {
  int n = a.size();
  set<int> excluded;
  for (int i = 0; i <= n+1; ++i) {
    excluded.insert(i);
  }

  vector<int> prefix_min = a;
  for (int i = 1; i < n; ++i) {
    prefix_min[i] = min(prefix_min[i], prefix_min[i-1]);
  }

  for (int i = n-1; i > 0; --i) {
    excluded.erase(a[i]);
    int mex = *excluded.begin();
    if (prefix_min[i-1] < mex) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int zeros = 0;
  for (int i = 0; i < n; ++i) {
    zeros += a[i] == 0;
  }
  if (zeros == 0) {
    cout << n << endl;
    return;
  }

  bool add_zero = false;
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      b.push_back(a[i]);
    } else {
      if (!add_zero) {
        add_zero = true;
        b.push_back(a[i]);
      }
    }
  }

  if (is_magical(b)) {
    cout << b.size() << endl;
  } else{
    cout << b.size()-1 << endl;
  }
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
