#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string best;
  int n = s.length();
  for (int i = n-1; i >= 0; --i) {
    best.push_back(s[i] == '1' ? '0' : '1');
  }
  while (best.length() > 1 && best.back() == '0') {
    best.pop_back();
  }
  reverse(best.begin(), best.end());

  // cout << "best=" << best << endl;

  int len = best.length();
  int prefix_match = -1;
  int start_idx = -1;
  for (int i = 0; i <= n-len; ++i) {
    int current = 0;
    for (int j = 0; j < len; ++j) {
      if (s[i+j] != best[j]) {
        break;
      }
      current++;
    }
    if (current > prefix_match) {
      prefix_match = current;
      start_idx = i;
    }
  }

  cout << "1 " << n << " " << start_idx+1 << " " << start_idx + len << endl;
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
