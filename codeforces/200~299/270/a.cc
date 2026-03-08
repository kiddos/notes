#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

set<int> s;
void precompute() {
  for (int n = 3; n <= 720; ++n) {
    int angle = (n-2) * 180;
    if (angle % n == 0) {
      s.insert(angle / n);
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  if (s.count(n)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
