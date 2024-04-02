#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int h = stoi(s.substr(0, 2));
  int m = stoi(s.substr(3, 2));
  string s2 = "AM";
  if (h >= 12) {
    s2 = "PM";
    h -= 12;
  }
  if (h == 0) h = 12;
  cout << setfill('0') << setw(2) << h
    << ":" << setfill('0') << setw(2) << m << " " << s2 << endl;
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
