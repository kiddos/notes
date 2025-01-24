#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int x) {
  cout << x << endl;
  int result = 0;
  cin >> result;
  return result;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  int p = 0;
  for (int i = 0; i < n; ++i) {
    int current = i ^ p;
    if (query(current)) {
      return;
    }
    p ^= current;
  }
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
