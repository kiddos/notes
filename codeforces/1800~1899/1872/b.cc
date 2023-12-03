#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> traps(1001);
  for (int i = 0; i < n; ++i) {
    int d = 0, s = 0;
    cin >> d >> s;
    if (traps[d]) {
      traps[d] = min(traps[d], s);
    } else {
      traps[d] = s;
    }
  }

  auto safe = [&](int x) {
    int t = 0;
    vector<int> activate(1001);
    for (int i = 1; i <= x; ++i, ++t) {
      if (traps[i]) {
        activate[i] = t + traps[i];
        // cout << "t=" << t << " traps =" << traps[i] << endl;
      }
    }
    // for (int i = 1; i <= x; ++i) cout << activate[i] << " ";
    // cout << endl;
    for (int i = x; i >= 1; --i, ++t) {
      if (activate[i] && t > activate[i]) {
        return false;
      }
    }
    return true;
  };

  int l = 1, r = 400;
  int ans = 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (safe(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
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
