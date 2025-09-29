#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int result = 0;
  cin >> result;
  return result;
}

void solve() {
  int n = 0;
  cin >> n;

  int idx = 1;
  vector<int> ans(n+1);
  for (int i = 2; i <= n; ++i) {
    int result1 = query(idx, i);
    int result2 = query(i, idx);
    if (result1 > result2) {
      // p[i] > p[idx]
      ans[idx] = result1;
      idx = i;
    } else {
      // p[idx] > p[i]
      ans[i] = result2;
    }
  }

  ans[idx] = n;

  cout << "! ";
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
