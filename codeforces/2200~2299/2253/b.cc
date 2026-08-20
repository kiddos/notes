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

  vector<int> prefix(n);
  for (int i = 1; i < n; ++i) {
    prefix[i] += prefix[i-1];
    if (a[i] == a[i-1]) {
      prefix[i]++;
    }
  }

  vector<int> suffix(n);
  for (int i = n-2; i >= 0; --i) {
    suffix[i] += suffix[i+1];
    if (a[i] == a[i+1]) {
      suffix[i]++;
    }
  }

  int ans = 1;
  for (int i = 1; i < n; ++i) {
    int left_color = i >= 2 ? a[i-2] : -1;
    int right_color = i+1 < n ? a[i+1] : -1;
    int remove_left = i >= 2 ? prefix[i-2] : 0;
    int remove_right = i+1 < n ? suffix[i+1] : 0;
    int remove1 = remove_left + remove_right
      + (left_color == a[i]) + (right_color == a[i-1]) + (a[i] == a[i-1]);
    int keep1 = n-remove1;
    ans = max(ans, keep1);

    int remove2 = remove_left + remove_right
      + (left_color == a[i-1]) + (right_color == a[i]) + (a[i] == a[i-1]);
    int keep2 = n-remove2;
    ans = max(ans, keep2);
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
