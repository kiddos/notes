#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  pair<int,int> pos = {0, 0};
  pair<int,int> target = {a, b};
  for (int i = 0; i < 20; ++i) {
    for (char ch : s) {
      if (ch == 'N') {
        pos.second++;
      } else if (ch == 'E') {
        pos.first++;
      } else if (ch == 'S') {
        pos.second--;
      } else if (ch == 'W') {
        pos.first--;
      }

      if (pos == target) {
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

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
