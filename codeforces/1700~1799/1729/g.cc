#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> compute_lps(const string& p) {
  int n = p.length();
  vector<int> lps(n);

  int len = 0, i = 1;
  while (i < n) {
    if (p[i] == p[len]) {
      lps[i++] = ++len;
    } else {
      if (len != 0) {
        len = lps[len-1];
      } else {
        i++;
      }
    }
  }

  return lps;
}

void solve() {
  string s, t;
  cin >> s >> t;

  vector<int> lps = compute_lps(t);

  int i = 0, j = 0;
  vector<bool> found(s.length());
  int occur = 0;
  while (i < s.length()) {
    if (s[i] == t[j]) {
      i++;
      j++;
    }

    if (j == t.length()) {
      occur++;
      found[i-j] = true;
      j = lps[j-1];
    } else if (s[i] != t[j]) {
      if (j != 0) {
        j = lps[j-1];
      } else {
        i++;
      }
    }
  }

  if (!occur) {
    cout << "0 1" << endl;
    return;
  }

  constexpr int MOD = 1e9 + 7;
  int n = s.length();
  vector<pair<int,ll>> memo(n, {-1, 0});
  function<pair<int,ll>(int)> dp = [&](int i) -> pair<int,ll> {
    if (i >= n) return {0, 1};
    if (memo[i].first >= 0) return memo[i];

    pair<int, ll> ans = {n+1, 1};
    if (found[i]) {
      for (int j = i; j < i + t.length(); ++j) {
        if (found[j]) {
          auto result = dp(j+t.length());
          if (result.first+1 < ans.first) {
            ans = {result.first+1, result.second};
          } else if (result.first+1 == ans.first) {
            ans.second += result.second;
            ans.second %= MOD;
          }
        }
      }
    } else {
      ans = dp(i+1);
    }
    return memo[i] = ans;
  };

  auto ans = dp(0);
  cout << ans.first << " " << ans.second << endl;
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
