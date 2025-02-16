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

  int max_count = 0;
  map<int, int> count;
  for (int i = 0; i < n; ++i) {
    max_count = max(max_count, ++count[a[i]]);
  }

  if (max_count > n-max_count) {
    int ans = max_count - (n-max_count);
    cout << ans << endl;
  } else {
    if (n % 2 == 0) {
      cout << "0" << endl;
    } else {
      cout << "1" << endl;
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
