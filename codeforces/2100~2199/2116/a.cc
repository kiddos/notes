#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, c = 0, d = 0;
  cin >> a >> b >> c >> d;

  int gellyfish = min(a, c);
  int flower = min(b, d);
  if (gellyfish >= flower) {
    cout << "Gellyfish" << endl;
  } else {
    cout << "Flower" << endl;
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
