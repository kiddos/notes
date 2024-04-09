#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_palindrome(const string& s) {
  int n = s.length();
  int l = 0, r = n-1;
  while (l < r) {
    if (s[l++] != s[r--]) {
      return false;
    }
  }
  return true;
}

void solve() {
  string s;
  cin >> s;
  if (!is_palindrome(s)) {
    cout << "YES" << endl;
    cout << "1" << endl;
    cout << s << endl;
    return;
  }

  int n = s.length();
  int i = 0;
  while (i < n && s[i] == s[0]) i++;
  if (i == n) {
    cout << "NO" << endl;
    return;
  }

  if (!is_palindrome(s.substr(i+1))) {
    cout << "YES" << endl;
    cout << "2" << endl;
    cout << s.substr(0, i+1) << " " << s.substr(i+1) << endl;
  } else if (i == 1 || i == n / 2) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << "2" << endl;
    cout << s.substr(0, i+2) << " " << s.substr(i+2) << endl;
  }
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
