#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> ans(n);
  int l = 0, r = n-1;
  int k = 1;
  while (l <= r) {
    if (l == r) {
      ans[l] = k++;
      break;
    } else {
      ans[l++] = k++;
      ans[r--] = k++;
    }
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << endl;
}


// 1 4 5 6 3 2

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
