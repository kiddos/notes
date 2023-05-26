#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> bin(26, -1);
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    int b = i % 2;
    if (bin[c] >= 0 && bin[c] != b) {
      cout << "NO" << endl;
      return;
    }
    bin[c] = b;
  }
  cout << "YES" << endl;
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
