#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> ans;
  int m = n/2;
  int a = m, b = n;
  if (n % 2 == 1) a++;
  for (int i = 0; i < m; ++i) {
    ans.push_back(a--);
    ans.push_back(b--);
  }
  if (n % 2 == 1) ans.push_back(1);

  for (int val : ans) cout << val << " ";
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
