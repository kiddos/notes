#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string find_smallest(vector<char>& chars, string& s) {
  char largest = chars.back();
  int d = s.length();
  string ans(d, largest);
  for (int i = 0; i < d; ++i) {
    for (char ch : chars) {
      ans[i] = ch;
      if (ans >= s) {
        break;
      }
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
  } else {
    set<char> digit_set(s.begin(), s.end());
    if ((int)digit_set.size() == k) {
      ans = s;
    } else {
      set<char> added;
      string p;
      int j = 0;
      for (int i = 0; i < d && k-added.size() > 2; ++i) {
        added.insert(s[i]);
        p.push_back(s[i]);
        j = i+1;
      }

      string suffix = s.substr(j);
      vector<char> added_chars(added.begin(), added.end());
      for (char c1 = '0'; c1 <= '9'; ++c1) {
        for (char c2 = '0'; c2 <= '9'; ++c2) {
          vector<char> chars = added_chars;
          chars.push_back(c1);
          chars.push_back(c2);
          sort(chars.begin(), chars.end());
          chars.resize(unique(chars.begin(), chars.end()) - chars.begin());
          string s2 = find_smallest(chars, suffix);
          if (s2 >= suffix) {
            if (ans.empty()) {
              ans = p + s2;
            } else {
              ans = min(ans, p + s2);
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
