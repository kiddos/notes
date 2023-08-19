#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> t(n*2+1);
  for (int i = 0; i < t.size(); ++i) cin >> t[i];

  for (char ch = 'a'; ch <= 'z'; ++ch) {
    int count = 0;
    for (string& x : t) {
      for (char c : x) {
        if (c == ch) {
          count++;
        }
      }
    }

    if (count % 2 == 1) {
      cout << ch << endl;
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
    solve();
  }
  return 0;
}
