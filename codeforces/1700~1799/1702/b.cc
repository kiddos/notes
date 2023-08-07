#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  vector<int> remembered(26);
  int r = 0;
  int day = 1;
  for (char ch : s) {
    int c = ch - 'a';
    if (!remembered[c]) {
      r++;
      if (r > 3) {
        fill(remembered.begin(), remembered.end(), false);
        day++;
        r %= 3;
      }
      remembered[c] = true;
    }
  }

  cout << day << endl;
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
