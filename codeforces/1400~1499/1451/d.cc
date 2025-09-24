#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 d = 0, k = 0;
  cin >> d >> k;

  i64 l = d / sqrt(2);
  l = l / k * k;
  // cout << "l=" << l << endl;
  i64 l2 = l + k;
  if (l2 * l2 + l * l <= d * d) {
    cout << "Ashish" << endl;
  } else {
    cout << "Utkarsh" << endl;
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
