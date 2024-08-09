#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 max_odd = -1;
  vector<i64> even;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      even.push_back(a[i]);
    } else {
      max_odd = max(max_odd, a[i]);
    }
  }
  if (max_odd < 0 || even.size() == 0) {
    cout << "0" << endl;
    return;
  }

  sort(even.begin(), even.end());

  for (int e : even) {
    if (e > max_odd) {
      // use the max even twice
      cout << even.size()+1 << endl;
      return;
    } else {
      max_odd += e;
    }
  }
  cout << even.size() << endl;
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
