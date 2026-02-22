#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  bool black_and_white = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      string pixel;
      cin >> pixel;
      if (pixel == "Y" || pixel == "C" || pixel == "M") {
        black_and_white = false;
      }
    }
  }
  if (black_and_white) {
    cout << "#Black&White" << endl;
  } else {
    cout << "#Color" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
