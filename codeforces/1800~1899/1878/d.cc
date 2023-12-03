#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  s = " " + s;

  vector<int> L(k);
  for (int i = 0; i < k; ++i) cin >> L[i];
  vector<int> R(k);
  for (int i = 0; i < k; ++i) cin >> R[i];

  int q = 0;
  cin >> q;
  vector<int> X(q);
  for (int i = 0; i < q; ++i) cin >> X[i];

  sort(X.begin(), X.end());
  vector<int> reverse(n+1);
  for (int i = 0, j = 0; i < q; ++i) {
    while (j < k && R[j] < X[i]) {
      j++;
    }
    int a = X[i];
    int b = R[j] - (X[i]-L[j]);
    int l = min(a, b);
    int r = max(a, b);
    if (l != r) {
      reverse[l]++;
      if (r+1 <= R[j]) reverse[r+1]--;
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << reverse[i] << " ";
  // }
  // cout << endl;

  string ans;
  int r = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j < k && R[j] < i) {
      j++;
      r = 0;
    }
    r += reverse[i];
    if (r % 2 == 1) {
      // cout << R[j] << ", " << L[j] << endl;
      // cout << "i = " << i << ", index = " << R[j] - (i - L[j]) << endl;
      ans.push_back(s[R[j] - (i - L[j])]);
    } else {
      ans.push_back(s[i]);
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
