#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  auto longest_subseq = [&](char c1, char c2) -> int {
    vector<char> c = {c1, c2};
    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == c[j%2]) {
        j++;
      }
    }
    if (c1 == c2) {
      return j;
    } else {
      return j / 2 * 2;
    }
  };

  int ans = n;
  for (char c1 = '0'; c1 <= '9'; ++c1) {
    for (char c2 = '0'; c2 <= '9'; ++c2) {
      int longest = longest_subseq(c1, c2);
      int remove = n - longest;
      ans = min(ans, remove);
      // cout << c1 << "," << c2 << ": " << remove << endl;
    }
  }

  cout << ans << endl;
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
