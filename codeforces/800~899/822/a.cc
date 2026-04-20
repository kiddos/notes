#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int A = 0, B = 0;
  cin >> A >> B;
  int k = min(A, B);
  i64 ans = 1;
  for (int i = 1; i <= k; ++i) {
    ans *= i;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
