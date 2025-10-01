#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  map<int,int> at_most;
  for (auto [e, c] : count) {
    if (c % k != 0) {
      cout << "0" << endl;
      return;
    }
    at_most[e] = c / k;
  }

  i64 ans = 0;
  map<int,int> current;
  for (int r = 0, l = 0; r < n; ++r) {
    current[a[r]]++;
    while (current[a[r]] > at_most[a[r]])  {
      current[a[l]]--;
      l++;
    }
    int len = r-l+1;
    ans += len;
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
