#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    string ops;
    cin >> ops;

    bool pass = false;
    pair<int, int> pos = {0, 0};
    for (char op : ops) {
      if (op == 'U') {
        pos.second++;
      } else if (op == 'D') {
        pos.second--;
      } else if (op == 'L') {
        pos.first--;
      } else if (op == 'R') {
        pos.first++;
      }

      if (pos.first == 1 && pos.second == 1) {
        pass = true;
        break;
      }
    }
    if (pass) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
