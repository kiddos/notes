#include <bits/stdc++.h>

using namespace std;

bool invalid(pair<int,int>& a, pair<int,int>& b, pair<int,int>& c) {
  return (a.first == b.first && c.second == b.second) ||
    (c.first == b.first && a.second == b.second);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string blank;
    getline(cin, blank);
    pair<int,int> a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    if (invalid(a, b, c) || invalid(b, a, c) || invalid(a, c, b)) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
