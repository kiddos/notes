#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string t;
  cin >> t;
  string first, second;
  cin >> first >> second;
  string rank ="6789TJQKA";

  int i1 = rank.find(first[0]);
  int i2 = rank.find(second[0]);
  if (first[1] == second[1]) {
    if (i1 > i2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (first[1] == t[0]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
