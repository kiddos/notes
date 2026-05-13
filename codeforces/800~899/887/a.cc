#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  string s2;
  for (int i = n-1; i >= 0; --i) {
    if (s2.length() < 6) {
      if (s[i] == '0') {
        s2.push_back(s[i]);
      }
    } else {
      s2.push_back(s[i]);
    }
  }
  while (!s2.empty() && s2.back() == '0') {
    s2.pop_back();
  }
  reverse(s2.begin(), s2.end());
  if (s2.length() >= 7) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
