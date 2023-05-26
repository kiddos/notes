#include <bits/stdc++.h>

using namespace std;

int count_removes(int count) {
  int ans = 0;
  while (count > 0) {
    count >>= 1;
    ans++;
  }
  return ans;
}

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  auto count_ops = [&](char ch) -> int {
    int ans = 0;
    int i = 0;
    while (i < n) {
      if (s[i] == ch) {
        i++;
      } else {
        int count = 0;
        while (i < n && s[i] != ch) {
          count++;
          i++;
        }
        ans = max(ans, count_removes(count));
      }
    }
    return ans;
  };

  int ans = numeric_limits<int>::max();
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    int ops = count_ops(ch);
    ans = min(ans, ops);
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
