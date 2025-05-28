#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> ans;
  if (n % k == 0) {
    ans = vector<int>(k, n/k);
  } else {
    int ones = k-3;
    int m = n-ones;
    ans = vector<int>(ones, 1);
    if (m % 2 == 1) {
      ans.push_back(1);
      ans.push_back((m-1) / 2);
      ans.push_back((m-1) / 2);
    } else {
      if (m % 4 == 0) {
        ans.push_back(m / 4);
        ans.push_back(m / 4);
        ans.push_back(m / 2);
      } else {
        ans.push_back(2);
        ans.push_back((m-2) / 2);
        ans.push_back((m-2) / 2);
      }
    }
  }

  for (int i = 0; i < k; ++i) {
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
