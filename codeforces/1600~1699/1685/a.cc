#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i= 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (n % 2 == 1) {
    cout << "NO" << endl;
    return;
  }

  int half = n / 2;
  vector<int> ans;
  for (int i = 0, j = half; i < half; ++i, ++j) {
    ans.push_back(a[i]);
    ans.push_back(a[j]);
  }
  for (int i = 0; i < n; ++i) {
    if (!((ans[i] > ans[(i-1+n)%n] && ans[i] > ans[(i+1)%n]) ||
        (ans[i] < ans[(i-1+n)%n] && ans[i] < ans[(i+1)%n]))) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
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
