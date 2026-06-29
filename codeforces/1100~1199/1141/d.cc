#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string l, r;
  cin >> l >> r;
  vector<vector<int>> left(26), right(26);
  vector<int> left_all_compatible, right_all_compatible;
  for (int i = 0; i < n; ++i) {
    if (l[i] >= 'a' && l[i] <= 'z') {
      left[l[i]-'a'].push_back(i);
    } else if (l[i] == '?') {
      left_all_compatible.push_back(i);
    }

    if (r[i] >= 'a' && r[i] <= 'z') {
      right[r[i]-'a'].push_back(i);
    } else if (r[i] == '?') {
      right_all_compatible.push_back(i);
    }
  }

  vector<pair<int,int>> ans;
  for (int c = 0; c < 26; ++c) {
    while (!right[c].empty() && !left[c].empty()) {
      int a = left[c].back();
      left[c].pop_back();
      int b = right[c].back();
      right[c].pop_back();
      ans.push_back({a+1, b+1});
    }
  }

  for (int c = 0; c < 26; ++c) {
    while (!right[c].empty() && !left_all_compatible.empty()) {
      int a = left_all_compatible.back();
      left_all_compatible.pop_back();
      int b = right[c].back();
      right[c].pop_back();
      ans.push_back({a+1, b+1});
    }
    while (!right_all_compatible.empty() && !left[c].empty()) {
      int a = left[c].back();
      left[c].pop_back();
      int b = right_all_compatible.back();
      right_all_compatible.pop_back();
      ans.push_back({a+1, b+1});
    }
  }
  while (!right_all_compatible.empty() && !left_all_compatible.empty()) {
    int a = left_all_compatible.back();
    left_all_compatible.pop_back();
    int b = right_all_compatible.back();
    right_all_compatible.pop_back();
    ans.push_back({a+1, b+1});
  }

  cout << ans.size() << endl;
  for (auto [a, b] : ans) {
    cout << a << " " << b << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
