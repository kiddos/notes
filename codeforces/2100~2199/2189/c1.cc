#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> ans(n+1);
  ans[n] = 1;

  vector<bool> used(n+1);
  used[1] = true;
  for (int i = 2; i < n; ++i) {
    if (i % 2 == 0) {
      ans[i] = i+1;
    } else {
      ans[i] = i-1;
    }
    used[ans[i]] = true;
  }

  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      ans[1] = i;
      break;
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
