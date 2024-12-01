#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int both = n / 3;
  int left = n % 3;
  int c1 = both, c2 = both;
  if (left == 1) {
    c1++;
  } else if (left == 2) {
    c2++;
  }
  cout << c1 << " " << c2 << endl;
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
