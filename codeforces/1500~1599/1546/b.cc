#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> original(n);
  for (int i = 0; i < n; ++i) {
    cin >> original[i];
  }
  vector<string> reordered(n-1);
  for (int i = 0; i < n-1; ++i) {
    cin >> reordered[i];
  }

  vector<int> total(26);
  string ans;
  for (int j = 0; j < m; ++j) {
    fill(total.begin(), total.end(), 0);
    for (int i = 0; i < n; ++i) {
      total[original[i][j]-'a']++;
    }
    for (int i = 0; i < n-1; ++i) {
      total[reordered[i][j]-'a']--;
    }
    for (int c = 0; c < 26; ++c) {
      if (total[c]) {
        ans.push_back(c + 'a');
        break;
      }
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
