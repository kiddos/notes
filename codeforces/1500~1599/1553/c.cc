#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string s1 = s, s2 = s;
  for (int i = 0; i < 10; ++i) {
    if (s1[i] == '?') {
      if (i % 2 == 0) s1[i] = '1';
      else s1[i] = '0';
    }
    if (s2[i] == '?') {
      if (i % 2 == 1) s2[i] = '1';
      else s2[i] = '0';
    }
  }

  auto min_kicks = [&](const string& k) -> int {
    // cout << k << endl;
    int team1 = 0, team2 = 0;
    for (int i = 0; i < 10; ++i) {
      if (i % 2 == 0) {
        team1 += k[i]-'0';
      } else {
        team2 += k[i]-'0';
      }

      int team1_left = (10 - i - 1) / 2;
      int team2_left = (10 - i) / 2;
      // cout << "i=" << i << "," << team1 << ", " << team2 << ", " << team1_left << ", " << team2_left << endl;
      if (team1 + team1_left < team2 || team2 + team2_left < team1) {
        return i+1;
      }
    }
    return 10;
  };

  int ans = min(min_kicks(s1), min_kicks(s2));
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
