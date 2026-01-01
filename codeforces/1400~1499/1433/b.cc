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
  int first = -1, last = -1, total = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      if (first < 0) {
        first = i;
      }
      last = i;
      total++;
    }
  }
  int len = last - first + 1;
  int middle_zero = len - total;
  cout << middle_zero << endl;
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
