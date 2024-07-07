#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int add_both = 0, add_first = 0, add_second = 0, remove_both = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1 && b[i] == 1) {
      add_both++;
    } else if (a[i] == 1 && b[i] < 1) {
      add_first++;
    } else if (a[i] < 1 && b[i] == 1) {
      add_second++;
    } else if (a[i] == -1 && b[i] == -1) {
      remove_both++;
    }
  }

  while (add_both) {
    if (add_first < add_second) {
      add_first++;
    } else {
      add_second++;
    }
    add_both--;
  }
  while (remove_both) {
    if (add_first > add_second) {
      add_first--;
    } else {
      add_second--;
    }
    remove_both--;
  }

  int ans = min(add_first, add_second);
  cout << ans << endl;
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
