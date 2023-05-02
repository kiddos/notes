#include <bits/stdc++.h>

using namespace std;

bool cut(int a, int b, int c) {
  if (b == c) return a % 2 == 0;
  return a - b == c;
}

bool solve(int l1, int l2, int l3) {
  return cut(l1, l2, l3) || cut(l2, l1, l3) || cut(l3, l1, l2);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int l1 = 0, l2 = 0, l3 = 0;
    cin >> l1 >> l2 >> l3;
    bool ans = solve(l1, l2, l3);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << flush;
  return 0;
}
