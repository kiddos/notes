#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string p = "LIT";
  vector<int> count(3);
  for (int i = 0; i < n; ++i) {
    int idx = p.find(s[i]);
    count[idx]++;
  }
  int min_index = min_element(count.begin(), count.end()) - count.begin();
  vector<int> missing(3);
  int min_add = 0;
  for (int i = 0; i < 3; ++i) {
    if (i != min_index) {
      int other = 3 - i - min_index;
      missing[i] = count[other] - count[min_index];
      min_add += missing[i];
    }
  }
  missing[min_index] = min_add;
  // for (int i = 0; i < 3; ++i) {
  //   cout << missing[i] << " ";
  // }
  // cout << endl;

  set<array<int,4>> to_insert;
  for (int i = 1; i < n; ++i) {
    int c2 = p.find(s[i]);
    int c1 = p.find(s[i-1]);
    if (c1 != c2) {
      int missing = 3 - c2 - c1;
      to_insert.insert({i, missing, c1, c2});
    }
  }

  vector<int> ans;
  while (!to_insert.empty()) {
    auto [idx, add_c, c1, c2] = *to_insert.rbegin();
    to_insert.erase(prev(to_insert.end()));

    if (missing[add_c] == 0) {
      continue;
    }

    ans.push_back(idx);
    missing[add_c]--;
    to_insert.insert({idx, 3 - add_c - c1, c1, add_c});
    to_insert.insert({idx+1, 3 - c2 - add_c, add_c, c2});
  }

  int total_missing = accumulate(missing.begin(), missing.end(), 0);
  if (total_missing != 0) {
    cout << "-1" << endl;
    return;
  }

  cout << ans.size() << endl;
  for (int idx : ans) {
    cout << idx << endl;
  }
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
