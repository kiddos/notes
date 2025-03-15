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

  int best = 0;
  pair<int,int> ans = {0, 0};
  for (int i = 0; i < n; ++i) {
    int inv_reduce = 0;
    for (int j = i+1; j < n; ++j) {
      if (a[j] < a[i]) {
        inv_reduce++;
      } else if (a[j] > a[i]) {
        inv_reduce--;
      }

      if (inv_reduce > best) {
        ans = {i, j};
        best = inv_reduce;
      }
    }
  }

  cout << ans.first+1 << " " << ans.second+1 << endl;
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
