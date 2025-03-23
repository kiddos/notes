#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> reminders(m);
  for (int i = 0; i < n; ++i) {
    reminders[a[i]%m]++;
  }
  int ans = 0;
  if (reminders[0]) {
    ans++;
  }
  int l = 1, r = m-1;
  while (l <= r) {
    if (l == r) {
      if (reminders[l]) {
        ans++;
      }
    } else {
      int size1 = reminders[l];
      int size2 = reminders[r];
      if (size1 == size2) {
        if (size1) {
          ans++;
        }
      } else if (size1 > size2) {
        int left = size1-(size2+1);
        ans += left + 1;
      } else {
        int left = size2-(size1+1);
        ans += left + 1;
      }
    }
    l++;
    r--;
  }
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
