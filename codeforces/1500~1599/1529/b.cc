#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> neg_or_zero;
  vector<int> pos;

  for (int i = 0; i < n; ++i) {
    if (a[i] <= 0) {
      neg_or_zero.push_back(a[i]);
    } else {
      pos.push_back(a[i]);
    }
  }

  int ans = 0;
  if (!neg_or_zero.empty() && !pos.empty()) {
    ans = neg_or_zero.size();
    sort(neg_or_zero.begin(), neg_or_zero.end());
    int min_diff = numeric_limits<int>::max();
    for (int i = 1; i < (int)neg_or_zero.size(); ++i) {
      min_diff = min(min_diff, neg_or_zero[i] - neg_or_zero[i-1]);
    }

    if (*min_element(pos.begin(), pos.end()) <= min_diff) {
      ans = max(ans, (int)neg_or_zero.size() + 1);
    }
  } else if (!neg_or_zero.empty()) {
    ans = neg_or_zero.size();
  } else if (!pos.empty()) {
    ans = 1;
  } else {
    ans = 0;
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
