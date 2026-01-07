#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void update(string& s) {
  int n = s.length();
  for (int i = n-2; i >= 0; --i) {
    if (s[i] == 'B' && s[i+1] == 'G') {
      swap(s[i], s[i+1]);
      --i;
    }
  }
}

void solve() {
  int n = 0, t = 0;
  cin >> n >> t;
  string s;
  cin >> s;

  for (int x = 0; x < t; ++x) {
    update(s);
  }
  cout << s << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
