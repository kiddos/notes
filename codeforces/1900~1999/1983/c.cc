#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void find_solution(vector<i64>& a, vector<i64>& b, vector<i64>& c, vector<int>& ans) {
  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  i64 target = (sum + 2) / 3;
  int n = a.size();

  vector<i64> suffix_c = c;
  for (int i = n-2; i >= 0; --i) {
    suffix_c[i] += suffix_c[i+1];
  }
  vector<i64> prefix_a = a;
  for (int i = 1; i < n; ++i) {
    prefix_a[i] += prefix_a[i-1];
  }

  i64 b_sum = 0;
  for (int i = 0, j = 0; i < n-1; ++i) {
    b_sum += b[i];
    while (j <= i && b_sum >= target) {
      i64 a_sum = j > 0 ? prefix_a[j-1] : 0;
      i64 c_sum = suffix_c[i+1];
      if (a_sum >= target && c_sum >= target) {
        ans = {1, j, j+1, i+1, i+2, n};
        return;
      }
      b_sum -= b[j++];
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<i64> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  vector<int> ans;
  find_solution(a, b, c, ans);
  if (!ans.empty()) {
    cout << ans[0] << " " << ans[1] << " "
      << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << endl;
    return;
  }

  find_solution(a, c, b, ans);
  if (!ans.empty()) {
    cout << ans[0] << " " << ans[1] << " "
      << ans[4] << " " << ans[5] << " " << ans[2] << " " << ans[3] << endl;
    return;
  }

  find_solution(b, a, c, ans);
  if (!ans.empty()) {
    cout << ans[2] << " " << ans[3] << " "
      << ans[0] << " " << ans[1] << " " << ans[4] << " " << ans[5] << endl;
    return;
  }

  find_solution(b, c, a, ans);
  if (!ans.empty()) {
    cout << ans[4] << " " << ans[5] << " "
      << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
    return;
  }

  find_solution(c, a, b, ans);
  if (!ans.empty()) {
    cout << ans[2] << " " << ans[3] << " "
      << ans[4] << " " << ans[5] << " " << ans[0] << " " << ans[1] << endl;
    return;
  }

  find_solution(c, b, a, ans);
  if (!ans.empty()) {
    cout << ans[4] << " " << ans[5] << " "
      << ans[2] << " " << ans[3] << " " << ans[0] << " " << ans[1] << endl;
    return;
  }

  cout << "-1" << endl;
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
