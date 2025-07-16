#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l1 = 0, b1 = 0, l2 = 0, b2 = 0, l3 = 0, b3 = 0;
  cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
  int area1 = l1 * b1, area2 = l2 * b2, area3 = l3 * b3;
  int sum = area1 + area2 + area3;
  int sides = sqrt(sum);
  if (sides * sides != sum) {
    cout << "NO" << endl;
    return;
  }

  if (l1 == l2 && l2 == l3 && l1 == sides && b1 + b2 + b3 == sides) {
    cout << "YES" << endl;
    return;
  }
  if (l1 == sides && l2 + l3 == sides && b2 == b3 && b2 + b1 == sides) {
    cout << "YES" << endl;
    return;
  }
  if (b1 == b2 && b2 == b3 && b1 == sides && l1 + l2 + l3 == sides) {
    cout << "YES" << endl;
    return;
  }
  if (b1 == sides && b2 + b3 == sides && l2 == l3 && l2 + l1 == sides) {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
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
