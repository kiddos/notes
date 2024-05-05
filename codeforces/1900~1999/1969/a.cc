#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) cin >> p[i];

  for (int i = 1; i <= n; ++i) {
    if (p[p[i]] == i) {
      cout << "2" << endl;
      return;
    }
  }
  cout << "3" << endl;
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
