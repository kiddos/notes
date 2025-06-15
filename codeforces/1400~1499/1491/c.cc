#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> S(n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }

  vector<i64> jumped(n+1);
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (S[i] - jumped[i] > 1) {
      ans += S[i] - jumped[i] - 1;
    }
    if (jumped[i] >= S[i]) {
      i64 next_jump = jumped[i] - S[i] + 1;
      jumped[i+1] += next_jump;
    }

    for (int j = i+2; j <= min(i+S[i], (i64)n-1); ++j) {
      jumped[j]++;
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
