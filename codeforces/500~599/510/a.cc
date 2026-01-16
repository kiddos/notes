#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      cout << string(m, '#') << endl;
    } else {
      string line(m, '.');
      if (((i-1) / 2) % 2 == 0) {
        line.back() = '#';
      } else {
        line[0] = '#';
      }
      cout << line << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
