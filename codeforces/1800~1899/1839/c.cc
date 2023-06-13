#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (a.back() == 1) {
    cout << "NO" << endl;
    return;
  }

  int i = n-1;
  vector<int> ans;
  while (i >= 0) {
    int j = i;
    while (j >= 0 && a[j] == 0) j--;
    int k = j;
    while (k >= 0 && a[k] == 1) k--;
    int len = i - k;
    int ones = j - k;
    for (int x = 1; x < len; ++x) ans.push_back(0);
    ans.push_back(ones);

    i = k;
  }

  cout << "YES" << endl;
  for (int i = 0; i < ans.size(); ++i) {
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
