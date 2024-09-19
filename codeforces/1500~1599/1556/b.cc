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
  vector<int> counts(2);
  for (int i = 0; i < n; ++i) {
    counts[a[i] % 2]++;
  }
  int diff = abs(counts[0] - counts[1]);
  if (diff > 1) {
    cout << "-1" << endl;
    return;
  }

  if (diff == 0) {
    int ans1 = 0, ans2 = 0;
    int idx1 = n-2, idx2 = n-1;
    for (int i = n-1; i >= 0; --i) {
      if (a[i] % 2 == 0) {
        ans1 += abs(i - idx1);
        ans2 += abs(i - idx2);
        idx1 -= 2;
        idx2 -= 2;
      }
    }
    cout << min(ans1, ans2) << endl;
  } else if (diff == 1) {
    int p = counts[0] < counts[1] ? 0 : 1;
    int idx = n-2;
    int ans = 0;
    for (int i = n-1; i >= 0; --i) {
      if (a[i] % 2 == p) {
        ans += abs(i - idx);
        idx -= 2;
      }
    }
    cout << ans << endl;
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
