#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  set<int> zeros;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      zeros.insert(i);
    }
  }

  vector<i64> ans(n, -1);
  i64 result = 0;
  for (int i = n-1, j = 0; i >= 0; --i, ++j) {
    if (zeros.empty()) {
      break;
    }
    result += i;
    result -= *zeros.rbegin();
    ans[j] = result;
    zeros.erase(prev(zeros.end()));
  }
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
