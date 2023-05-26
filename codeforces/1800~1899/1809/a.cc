#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;

  vector<int> color(10);
  for (char ch : s) color[ch-'0']++;

  for (int i = 0; i < 10; ++i) {
    if (color[i] == 4) {
      cout << "-1" << endl;
      return;
    } else if (color[i] == 3) {
      cout << "6" << endl;
      return;
    }
  }
  cout << "4" << endl;
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
