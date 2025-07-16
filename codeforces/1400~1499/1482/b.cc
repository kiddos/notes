#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  // m > a[i] for all i
  //
  // (a[i-1] + c) % m = a[i]
  // => a[i-1] + c = a[i] + k * m
  // if a[i] == a[i-1]
  //  => c = k * m
  // if a[i] > a[i-1]
  //  => c = a[i] - a[i-1]
  // if a[i] < a[i-1]
  //  => a[i-1] - a[i] = k * m - c > 0
  //  => k * m > c
  //  all increase should be the same which is c
  //  all decrease should also be the same
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  set<i64> inc, dec;
  int eq = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i-1]) {
      inc.insert(a[i] - a[i-1]);
    } else if (a[i] == a[i-1]) {
      eq++;
    } else {
      dec.insert(a[i-1] - a[i]);
    }
  }

  if (eq) {
    if (eq == n-1) {
      cout << "0" << endl;
    } else {
      cout << "-1" << endl;
    }
    return;
  }

  if ((inc.size() > 0 && inc.size() != 1) || (dec.size() > 0 && dec.size() != 1)) {
    cout << "-1" << endl;
    return;
  }

  if (inc.empty() || dec.empty()) {
    cout << "0" << endl;
    return;
  }

  i64 c = *inc.begin();
  i64 m = c + *dec.begin();

  // again m should > all a[i]
  for (int i = 0; i < n; ++i) {
    if (m <= a[i]) {
      cout << "-1" << endl;
      return;
    }
  }

  // check the sequence again
  for (int i = 1; i < n; ++i) {
    if ((a[i-1] + c) % m != a[i]) {
      cout << "-1" << endl;
      return;
    }
  }

  cout << m << " " << c << endl;
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
