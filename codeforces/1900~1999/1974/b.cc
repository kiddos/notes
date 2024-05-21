#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<bool> found(26);
  string r;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    if (!found[c]) {
      r.push_back(s[i]);
      found[c] = true;
    }
  }

  sort(r.begin(), r.end());
  vector<int> mapping(26, -1);
  for (int i = 0, j = r.length()-1; i < (int)r.length(); ++i, --j) {
    int c1 = r[i] - 'a';
    int c2 = r[j] - 'a';
    mapping[c1] = c2;
  }

  string ans;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    int d = mapping[c];
    if (d >= 0) {
      ans.push_back(d + 'a');
    } else {
      ans.push_back(s[i]);
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
