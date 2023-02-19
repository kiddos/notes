#include <bits/stdc++.h>

using namespace std;

bool valid(const string& s) {
  int n = s.length();
  for (int i = 1; i < n; ++i) if (s[i] == s[i-1]) return false;
  return true;
}

void solve(string a, string b) {
  if (valid(a) && valid(b)) {
    cout << "YES" << endl;
    return;
  }

  for (int i = 1; i < a.length(); ++i) {
    if (a[i] == a[i-1]) {
      string rest = a.substr(i);
      if (valid(b + string(rest.rbegin(), rest.rend()))) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      return;
    }
  }

  for (int i = 1; i < b.length(); ++i) {
    if (b[i] == b[i-1]) {
      string rest = b.substr(i);
      if (valid(a + string(rest.rbegin(), rest.rend()))) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      return;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, m = 0;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    solve(a, b);
  }
  return 0;
}
