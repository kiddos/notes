#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string t;
  cin >> t;

  string s2;
  for (char ch : t) {
    if (ch != 'a') {
      s2.push_back(ch);
    }
  }

  if (s2.empty()) {
    cout << t << endl;
    return;
  }

  int m = s2.length();
  if (m % 2 == 1) {
    cout << ":(" << endl;
    return;
  }

  string s = s2.substr(0, m/2);
  string s_prime = s2.substr(m/2);
  if (s != s_prime) {
    cout << ":(" << endl;
    return;
  }

  int n = t.length();
  string current;
  for (int i = n-1; i >= 0; --i) {
    if (t[i] == 'a') {
      break;
    }

    current.push_back(t[i]);
    if ((int) current.length() == m/2) {
      cout << t.substr(0, i) << endl;
      return;
    }
  }
  cout << ":(" << endl;;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
