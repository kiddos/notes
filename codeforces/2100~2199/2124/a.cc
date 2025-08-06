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
  vector<int> b = a;
  sort(b.begin(), b.end());
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (b[i] != a[i]) {
      ans.push_back(a[i]);
    }
  }

  if (ans.size() == 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
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
