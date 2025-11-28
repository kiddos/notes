#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> intervals;
  for (int i = 0; i < m; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;
    intervals.emplace_back(l, r);
  }

  vector<int> line(n+1);
  for (auto [l, r] : intervals) {
    line[l]++;
    line[r+1]--;
  }
  for (int i = 1; i <= n; ++i) {
    line[i] += line[i-1];
  }

  vector<int> ans(n, -1);
  int idx = max_element(line.begin(), line.end()) - line.begin();
  if (line[idx] == m) {
    // all interval contain this point
    // we can assign this to 0, and mex(M) will be 0
    ans[idx] = 0;
  } else {
    // mex(M) >= 1
    // if we want mex(M) = 1,
    // if an interval has 0, it must also have 1
    // find an index, where it is not the left of one interval, and right of another
    vector<int> left_count(n), right_count(n);
    for (auto [l, r] : intervals) {
      left_count[l]++;
      right_count[r]++;
    }

    bool found = false;
    for (int i = 0; i+1 < n; ++i) {
      if (left_count[i+1] == 0) {
        ans[i+1] = 0;
        ans[i] = 1;
        found = true;
        break;
      }
      if (right_count[i] == 0) {
        ans[i] = 0;
        ans[i+1] = 1;
        found = true;
        break;
      }
    }

    if (!found) {
      ans[0] = 0;
      ans[1] = 2;
      ans[2] = 1;
    }
  }

  // fill the rest
  set<int> s;
  for (int i = 0; i < n; ++i) {
    s.insert(i);
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i] >= 0) {
      s.erase(ans[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i] < 0) {
      ans[i] = *s.begin();
      s.erase(s.begin());
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
