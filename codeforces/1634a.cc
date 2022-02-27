#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(const string& s) {
  int l = 0, r = s.length()-1;
  while (l < r) {
    if (s[l++] != s[r--]) return false;
  }
  return true;
}

int solve(string s, int k) {
  if (k == 0) return 1;
  if (is_palindrome(s)) return 1;
  return 2;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, k = 0;
    string s;
    cin >> n >> k >> s;

    int ans = solve(s, k);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
