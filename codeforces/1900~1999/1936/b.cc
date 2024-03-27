#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// exit right
// find r0, r1, r2, ... for all the < on the right of i
// find l0, l1, l2, ... for all the > on the left of i
// ans[i] = (r0 - i) + (r0 - l0) + (r1 - l0) + (r1 - l1) + (r2 - l1) + (r2 - l2) + (n - l2)
//        = 2 * (r0 + r1 + r2 + ...) - 2 * (l0 + l1 + l2 + ....) + (n - i)

// exit left
// ans[i] = (i - l0) + (r0 - l0) + (r0 - l1) + (r1 - l1) + (r1 - l2) + (r2 - l2) + (r2 - 0)
//        = 2 * (r0 + r1 + r2 + ...) - 2 * (l0 + l1 + l2 + ....) + i

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<int> go_left(n);
  vector<int> go_right(n);
  vector<int> go_left_indices, go_right_indices;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '>') {
      go_right[i]++;
      go_right_indices.push_back(i);
    } else if (s[i] == '<') {
      go_left[i]++;
      go_left_indices.push_back(i);
    }
  }

  vector<i64> left_prefix = {0};
  for (int idx : go_left_indices) left_prefix.push_back(idx + left_prefix.back());

  vector<i64> right_prefix = {0};
  for (int idx : go_right_indices) right_prefix.push_back(idx + right_prefix.back());

  for (int i = n-2; i >= 0; --i) {
    go_left[i] += go_left[i+1];
  }
  for (int i = 1; i < n; ++i) {
    go_right[i] += go_right[i-1];
  }

  auto sum_left = [&](int i, int k) -> i64 {
    int start = lower_bound(go_left_indices.begin(), go_left_indices.end(), i) - go_left_indices.begin();
    return left_prefix[start+k] - left_prefix[start];
  };

  auto sum_right = [&](int i, int k) -> i64 {
    int end = upper_bound(go_right_indices.begin(), go_right_indices.end(), i) - go_right_indices.begin();
    return right_prefix[end] - right_prefix[end-k];
  };

  for (int i = 0; i < n; ++i) {
    if (go_right[i] > go_left[i] || (go_right[i] == go_left[i] && s[i] == '<')) {
      // go right
      int k = go_left[i];
      // find the closest k go right and go left indices
      // and sum them
      i64 l = sum_left(i, k);
      i64 r = sum_right(i-1, k);
      i64 ans = 2 * (l - r) + n - i;
      // cout << "l=" << l << ",r=" << r << endl;
      cout << ans << " ";
    } else {
      // go left
      int k = go_right[i];
      i64 l = sum_left(i+1, k);
      i64 r = sum_right(i, k);
      // cout << "l=" << l << ",r=" << r << endl;
      i64 ans = 2 * (l - r) + i + 1;
      cout << ans << " ";
    }
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}