#include <bits/stdc++.h>

using namespace std;

ostream& operator<<(ostream& os, vector<int>& a) {
  for (int val : a) os << val << " ";
  return os;
}

vector<int> solve(int n, int k) {
  if (k == 0) {
    return vector<int>(n, -1);
  } else if (k < n) {
    vector<int> ans(n, -1);
    ans[0] = 30;
    ans[k] = -60;
    return ans;
  } else if (k == n) {
    vector<int> ans(n, -1);
    ans[0] = 30;
    return ans;
  } else {
    vector<int> p = solve(n-1, k-n);
    p.push_back(1000);
    return p;
  }
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> ans = solve(n, k);
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
