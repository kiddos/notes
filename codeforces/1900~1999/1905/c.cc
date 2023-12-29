#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<char, int>> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && st.back().first < s[i]) {
      st.pop_back();
    }
    st.push_back({s[i], i});
  }
  vector<int> indices;
  for (auto& [_, i] : st) indices.push_back(i);
  sort(st.begin(), st.end());
  sort(indices.begin(), indices.end());
  for (int k = 0; k < (int)indices.size(); ++k) {
    int idx = indices[k];
    s[idx] = st[k].first;
  }

  for (int i = 1; i < n; ++i) {
    if (s[i-1] > s[i]) {
      cout << "-1" << endl;
      return;
    }
  }

  int ans = 0;
  char largest_c = st.back().first;
  for (int i = 0; i < (int)st.size(); ++i) {
    if (st[i].first < largest_c) {
      ans++;
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
