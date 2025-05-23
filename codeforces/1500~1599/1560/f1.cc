#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string find_smallest(char c1, char c2, string& s) {
  char larger = max(c1, c2);
  char smaller = min(c1, c2);
  int d = s.length();
  string ans(d, larger);
  for (int i = 0; i < d; ++i) {
    ans[i] = smaller;
    if (ans < s) {
      ans[i] = larger;
    }
  }
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s = to_string(n);
  int d = s.length();
  string ans;
  if (k == 1) {
    for (char ch = '0'; ch <= '9'; ++ch) {
      string s2(d, ch);
      if (s2 >= s) {
        ans = s2;
        break;
      }
    }
  } else if (k == 2) {
    set<char> digit_set(s.begin(), s.end());
    if (digit_set.size() == 2) {
      ans = s;
    } else {
      for (char c1 = '1'; c1 <= '9'; ++c1) {
        for (char c2 = '0'; c2 <= '9'; ++c2) {
          string s2 = find_smallest(c1, c2, s);
          if (s2 >= s) {
            if (ans.empty()) {
              ans = s2;
            } else {
              ans = min(ans, s2);
            }
          }
        }
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
