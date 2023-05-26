#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<vector<int>> char_counts(n+1, vector<int>(10));
  for (int i = 1; i <= n; ++i) {
    int d = s[i-1] - '0';
    for (int c = 0; c < 10; ++c) {
      char_counts[i][c] = char_counts[i-1][c] + (d == c);
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int end = min(i+100, n);
    for (int j = i; j < end; ++j) {
      int max_count = 0;
      int occur = 0;
      for (int d = 0; d < 10; ++d) {
        int count = char_counts[j+1][d] - char_counts[i][d];
        max_count = max(max_count, count);
        occur += count > 0;
      }

      ans += (max_count <= occur);
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
