#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<int> chars;
  for (char ch : s) {
    chars.push_back(ch - 'A');
  }
  int n = s.length();
  for (int i = 2; i < n; ++i) {
    if (chars[i] != ((chars[i-1] + chars[i-2]) % 26)) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
