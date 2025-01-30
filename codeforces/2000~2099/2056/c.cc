#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> ans = {1, 1, 2, 3};
  int left = n-6;
  for (int i = 0, k = 4; i < left; ++i) {
    ans.push_back(k++);
  }
  ans.push_back(1);
  ans.push_back(2);
  for (int x : ans) {
    cout << x << " ";
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
