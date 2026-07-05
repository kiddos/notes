#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a1 = 0, b1 = 0;
  cin >> a1 >> b1;
  int a2 = 0, b2 = 0, a3 = 0, b3 = 0;
  cin >> a2 >> b2 >> a3 >> b3;
  vector<int> sides1 = {a2, b2};
  vector<int> sides2 = {a3, b3};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      int w = max(sides1[i], sides2[j]);
      int h = sides1[1-i] + sides2[1-j];
      if ((a1 >= w && b1 >= h) || (a1 >= h && b1 >= w)) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
