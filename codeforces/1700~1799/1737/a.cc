#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> char_count(26);
  for (char ch : s) {
    char_count[ch-'a']++;
  }
  string ans;
  for (int i = 0; i < k; ++i) {
    int added = 0;
    bool found = false;
    for (int c = 0; c < 26; ++c) {
      if (char_count[c]) {
        added++;
        char_count[c]--;
      } else {
        ans.push_back(c + 'a');
        found = true;
        break;
      }

      if (added == n/ k) break;
    }

    if (!found) {
      ans.push_back(added + 'a');
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
