#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  
  set<int> factors;
  for (int d = 1; d *d <= n; ++d) {
    if (n % d == 0) {
      factors.insert(n/ d);
      factors.insert(d);
    }
  }

  string ans(n, 'a');
  for (int i = 1; i < n; ++i) {
    vector<bool> used(26);
    for (int d : factors) {
      if (i-d >= 0) {
        used[ans[i-d]-'a'] = true;
      }
    }
    for (int c = 0; c < 26; ++c) if (!used[c]) {
      ans[i] = c + 'a';
      break;
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
