#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[0] << endl;
    return;
  }

  i64 ans = accumulate(a.begin(), a.end(), 0LL);
  while (a.size() > 1) {
    vector<i64> b;
    int size = a.size();
    for (int i = 1; i < size; ++i) {
      b.push_back(a[i] - a[i-1]);
    }
    a = std::move(b);
    i64 new_sum = accumulate(a.begin(), a.end(), 0LL);
    ans = max(ans, abs(new_sum));
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
