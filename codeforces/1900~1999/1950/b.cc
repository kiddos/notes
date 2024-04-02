#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < 2; ++k) {
      for (int j = 0; j < n; ++j) {
        if (j % 2 == i % 2) {
          cout << "##";
        } else {
          cout << "..";
        }
      }
      cout << endl;
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
