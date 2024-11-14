#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> x;
  int sit_left = 0, sit_right = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      x.push_back(a[i]);
    } else if (a[i] == -1) {
      sit_left++;
    } else if (a[i] == -2) {
      sit_right++;
    }
  }

  sort(x.begin(), x.end());
  x.resize(unique(x.begin(), x.end()) - x.begin());
  int size = x.size();
  vector<int> left(size);
  for (int i = 0; i < size; ++i) {
    int left_occupy = i;
    int left_can_sit = x[i]-1-left_occupy;
    left[i] = min(left_can_sit, sit_left);
    // int total_sit = size + min(left_can_sit, sit_left) + min(right_can_sit, sit_right);
    // ans = max(ans, total_sit);
  }
  vector<int> right(size);
  for (int i = size-1; i >= 0; --i) {
    int right_occupy = size-i-1;
    int right_can_sit = m-x[i]-right_occupy;
    right[i] = min(right_can_sit, sit_right);
  }

  int ans = min(m - size, max(sit_left, sit_right)) + size;
  for (int i = 0; i < size; ++i) {
    ans = max(ans, left[i] + right[i] + size);
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
