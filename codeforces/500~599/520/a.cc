#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> count(26);
  for (int i = 0; i < n; ++i) {
    char ch = tolower(s[i]);
    int c = ch - 'a';
    count[c]++;
  }
  for (int c = 0; c < 26; ++c) {
    if (!count[c]) {
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
