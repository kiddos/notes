#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, n = 0;
  cin >> a >> b >> n;
  if (b * n <= a) {
    cout << "1" << endl;
  } else {
    if (b == a) {
      cout << "1" << endl;
    } else{
      cout << "2" << endl;
    }
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
