#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  vector<array<int,3>> users;
  map<pair<int,int>, int> count;
  for (int i = 0; i < n; ++i) {
    users.push_back({l[i], r[i], i});
    count[{l[i], r[i]}]++;
  }
  sort(users.begin(), users.end(), [&](auto& u1, auto& u2) {
    if (u1[0] == u2[0]) {
      return u1[1] > u2[1];
    }
    return u1[0] < u2[0];
  });

  vector<int> right_bound(n, -1);
  set<int> right;
  for (int i = 0; i < n; ++i) {
    auto [li, ri, idx] = users[i];
    auto it = right.lower_bound(ri);
    if (it != right.end()) {
      right_bound[idx] = *it;
    }
    right.insert(ri);
  }

  sort(users.begin(), users.end(), [&](auto& u1, auto& u2) {
    if (u1[1] == u2[1]) {
      return u1[0] < u2[0];
    }
    return u1[1] > u2[1];
  });

  vector<int> left_bound(n, -1);
  set<int> left;
  for (int i = 0; i < n; ++i) {
    auto [li, ri, idx] = users[i];
    auto it = left.upper_bound(li);
    if (it != left.begin()) {
      --it;
      left_bound[idx] = *it;
    }
    left.insert(li);
  }

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (left_bound[i] >= 0 && right_bound[i] >= 0 && count[{l[i], r[i]}] == 1) {
      ans[i] = l[i] - left_bound[i] + right_bound[i] - r[i];
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
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
