#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (n % 2 == 0) {
    cout << "YES" << endl;
    return;
  }

  vector<int> lis(n);
  set<int> s;
  for (int i = 0; i < n; ++i) {
    auto it = s.lower_bound(a[i]);
    if (it != s.end()) {
      s.erase(it);
    }
    s.insert(a[i]);
    lis[i] = s.size();
  }
  if (lis.back() % 2 == 0) {
    cout << "YES" << endl;
    return;
  }
  
  for (int i = 1; i < n; ++i) {
    if (a[i-1] >= a[i]) {
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
