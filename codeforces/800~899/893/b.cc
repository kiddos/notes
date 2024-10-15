#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> p2(30, 1);
  for (int i = 1; i < 30; ++i) {
    p2[i] = p2[i-1] * 2LL;
  }
  vector<i64> b;
  for (int k = 29; k >= 1; --k) {
    b.push_back((p2[k] - 1) * p2[k-1]);
  }
  for (i64 x : b) {
    if (n % x == 0) {
      cout << x << endl;
      return;
    } 
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
