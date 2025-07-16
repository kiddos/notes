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
  vector<int> count(n+1);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  int mex = 0;
  for (int i = 0; i <= n; ++i) {
    if (!count[i]) {
      mex = i;
      break;
    }
  }

  vector<int> prefix(n+1);
  for (int i = 0; i < mex; ++i) {
    prefix[i] = count[i] - 1;
  }
  for (int i = 1; i < mex; ++i) {
    prefix[i] += prefix[i-1];
  }
  int extra = 0;
  for (int m = mex+1; m <= n; ++m) {
    extra += count[m];
  }

  vector<int> ans(n+2);
  int suffix_count = 0;
  for (int m = mex; m >= 0; --m) {
    suffix_count += count[m];
    int current = count[m];
    int upto = suffix_count + (m > 0 ? prefix[m-1] : 0) + extra;
    // cout << "mex=" << m << ", " << current << "~" << upto << endl;
    ans[current]++;
    ans[upto+1]--;
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] += ans[i-1];
  }

  for (int i = 0; i <= n; ++i) {
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
