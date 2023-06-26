#include <bits/stdc++.h>

using namespace std;
  
using ll = long long;

bool all_same(vector<ll>& a) {
  int n = a.size();
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[0]) return false;
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);

  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 0; i < n; ++i) {
    int d = a[i] % 10;
    if (d == 5) {
      a[i] += 5;
    } else if (d != 0) {
      while (d != 2) {
        a[i] += d;
        d = a[i] % 10;
      }
      a[i] %= 20;
    }
  }

  if (all_same(a)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}


// 2 -> 4 -> 8 -> 16 -> 22
//
// 1 -> 2 -> 4 -> 8 -> ...
// 3 -> 6 -> 2 -> 4 -> ...
// 7 -> 4 -> 8 -> 6 -> ...
// 9 -> 8 -> 6 -> 2 -> ...
//
// 5 -> 10

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
