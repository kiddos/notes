#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;

  vector<int> first_index(26, -1);
  int n = s.length();
  for (int i = 1; i < n; ++i) {
    int c = s[i] -'a';
    if (first_index[c] < 0) {
      first_index[c] = i;
    }
  }

  int m = t.length();
  int best_length = numeric_limits<int>::max();
  pair<int,int> result = {-1, -1};
  for (int i = m-1; i > 0; --i) {
    int prev_c = t[i-1] - 'a';
    if (first_index[prev_c] >= 0) {
      int prefix_length = first_index[prev_c] + 1;
      int suffix_length = m-i;
      int total_length = prefix_length + suffix_length;
      if (total_length < best_length) {
        best_length = total_length;
        result = {prefix_length, i};
      }
    }
  }

  if (result.first < 0) {
    cout << "-1" << endl;
  } else {
    string ans = s.substr(0, result.first) + t.substr(result.second);
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
