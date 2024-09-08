#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> compute_lps(const string& s) {
  int n = s.length();
  vector<int> lps(n);
  int i = 1, len = 0;
  while (i < n) {
    if (s[i] == s[len]) {
      lps[i++] = ++len;
    } else {
      if (len != 0) {
        len = lps[len-1];
      } else {
        i++;
      }
    }
  }
  return lps;
}

void solve() {
  string s;
  cin >> s;
  vector<int> lps = compute_lps(s);

  int len = lps.back();
  int n = s.length();
  if (len * 2 > n) {
    cout << "YES" << endl;
    cout << s.substr(0, lps.back()) << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
