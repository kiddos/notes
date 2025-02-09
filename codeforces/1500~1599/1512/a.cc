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
  int x = a[0], count = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == x) {
      count++;
    } else {
      count--;
    }
    if (count == 0) {
      x = a[i];
      count = 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] != x) {
      cout << i+1 << endl;
      break;
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
