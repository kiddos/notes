#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string remove_first(const string& s, char ch) {
  string ans;
  bool found = false;
  for (char c : s) {
    if (found) {
      if (c != ch) {
        ans.push_back(c);
      }
    } else {
      found = c == ch;
    }
  }
  return ans;
}

int distinct_count(const string& s) {
  vector<int> count(26);
  for (char c : s) {
    count[c-'a'] = 1;
  }
  return accumulate(count.begin(), count.end(), 0);
}

void solve() {
  string s;
  cin >> s;
  set<char> chars(s.begin(), s.end());

  int char_count = chars.size();
  string ans;
  for (int k = 0; k < char_count; ++k) {
    for (auto it = chars.rbegin(); it != chars.rend(); ++it) {
      string s1 = remove_first(s, *it);
      if (distinct_count(s1) == char_count-k-1) {
        ans.push_back(*it);
        chars.erase(*it);
        s = s1;
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
