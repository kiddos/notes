#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, X = 0;
  cin >> n >> X;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  i64 S = 0;
  int l = 0, r = n-1;
  vector<int> ans;
  i64 points = 0;
  while (l <= r) {
    if ((S + a[r]) / X > S / X) {
      points += a[r];
      S += a[r];
      ans.push_back(a[r]);
      r--;
    } else {
      S += a[l];
      ans.push_back(a[l]);
      l++;
    }
  }
  cout << points << endl;
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
