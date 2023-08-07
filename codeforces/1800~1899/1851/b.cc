#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> even, odd;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      even.push_back(a[i]);
    } else {
      odd.push_back(a[i]);
    }
  }

  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end());

  for (int i = 0, p = 0, q = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      a[i] = even[p++];
    } else {
      a[i] = odd[q++];
    }
  }

  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i-1]) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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
