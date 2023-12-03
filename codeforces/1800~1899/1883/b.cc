#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> count(26);
  for (char ch : s) count[ch-'a']++;

  int must_remove = 0;
  for (int i = 0; i < 26; ++i) {
    must_remove += count[i] % 2;
  }

  bool ans = false;
  if (must_remove > 0) {
    must_remove--;
    ans = k >= must_remove;
  } else {
    ans = true;
  }

  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
