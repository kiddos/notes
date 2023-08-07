#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = 0;
  int i = 0;
  while (i < n) {
    int j = i+1;
    bool can_end_zero = a[i] != 0;
    while (j < n && a[j] != 0) {
      if (a[j] == 2) {
        can_end_zero = true;
      }
      j++;
    }
    if (j < n && a[j] == 0 && can_end_zero) {
      j++;
    }

    ans++;
    i = j;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
