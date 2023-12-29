#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int l = 0, o = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') l++;
    else if (s[i] == 'O') o++;
  }

  int l2 = 0, o2 = 0;
  for (int i = 0; i < n-1; ++i) {
    if (s[i] == 'L') {
      l2++;
      l--;
    } else if (s[i] == 'O') {
      o2++;
      o--;
    }

    if (l2 != l && o2 != o) {
      cout << i+1 << endl;
      return;
    }
  }
  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
