#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, l = 0, r = 0;
  cin >> n >> l >> r;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> dp(n);
  int ans = 0;
  auto find_answer = [&](int left, int right) {
    i64 sum = 0;
    for (int i = left, j = left; i <= right; ++i) {
      sum += a[i];
      while (j <= i && sum > r) {
        sum -= a[j];
        j++;
      }
      if (sum >= l) {
        ans++;
        j = i+1;
        sum = 0;
      }
    }
  };

  int last = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= l && a[i] <= r) {
      ans++;
      find_answer(last, i-1);
      last = i + 1;
    } else if (a[i] > r) {
      find_answer(last, i-1);
      last = i + 1;
    }
  }
  find_answer(last, n-1);

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
