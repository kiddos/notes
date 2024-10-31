#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t, p;
  cin >> s >> t >> p;

  bool is_subseq = false;
  int n = s.length();
  int i = 0;
  for (char ch : t) {
    if (s[i] == ch) {
      i++;
    }
    if (i == n) {
      is_subseq = true;
      break;
    }
  }

  if (!is_subseq) {
    cout << "NO" << endl;
    return;
  }

  vector<int> require(26);
  for (char ch : t) {
    require[ch-'a']++;
  }
  for (char ch : s) {
    require[ch-'a']--;
  }

  vector<int> has(26);
  for (char ch : p) {
    has[ch-'a']++;
  }
  for (int i = 0; i < 26; ++i) {
    if (require[i] > has[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
