#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  set<int> s;
  for (int i = 0; i < n; ++i) {
    if (a[i] != -1) {
      s.insert(a[i]);
    }
  }

  if (s.size() == 0) {
    cout << "YES" << endl;
  } else if (s.size() > 1) {
    cout << "NO" << endl;
  } else {
    int val = *s.begin();
    if (val == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
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
