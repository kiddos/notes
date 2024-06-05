#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, f = 0, k = 0;
  cin >> n >> f >> k;
  f--;
  k--;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int favorite = a[f];
  sort(a.rbegin(), a.rend());
  int start = -1, end = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == favorite) {
      if (start == -1) {
        start = i;
      }
      end = i;
    }
  }
  
  if (end <= k) {
    cout << "YES" << endl;
  } else if (start > k) {
    cout <<  "NO" << endl;
  } else {
    cout << "MAYBE" << endl;
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
