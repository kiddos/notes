#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  map<int, map<int,int>> s1, s2;
  for (int i = 0; i < n; ++i) {
    char c = '\0';
    int l = 0, r = 0;
    cin >> c >> l >> r;
    if (c == '+') {
      s1[r][l]++;
      s2[l][r]++;
    } else if (c == '-') {
      if (--s1[r][l] == 0) {
        s1[r].erase(l);
      }
      if (s1[r].empty()) {
        s1.erase(r);
      }

      if (--s2[l][r] == 0) {
        s2[l].erase(r);
      }
      if (s2[l].empty()) {
        s2.erase(l);
      }
    }

    if (s1.empty()) {
      cout << "NO" << endl;
    } else {
      int L = s2.rbegin()->first;
      auto result = s1.upper_bound(L-1);
      if (result == s1.begin()) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
