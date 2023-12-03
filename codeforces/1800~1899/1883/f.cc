#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int, int> count;
  vector<int> left(n);
  for (int i = 0; i < n; ++i) {
    if (!count.count(a[i])) {
      left[i] = 1;
    }
    count[a[i]]++;
  }

  i64 l = 0;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    l += left[i];
    count[a[i]]--;
    if (count[a[i]] == 0) {
      ans += l;
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
