#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> o = {0};
  vector<int> x = {0};
  for (int i = 0; i < n; ++i) {
    o.push_back(o.back() + (s[i] == 'o'));
    x.push_back(x.back() + (s[i] == 'x'));
  }

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int o_count = o[i+1];
    if (o_count == 0) {
      ans[i] = i+1;
    } else {
      int l = i+1, r = n-1;
      int index = r;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        int x_count = x[mid+1] - x[i+1];
        if (x_count >= o_count) {
          index = mid;
          r = mid-1;
        } else {
          l = mid+1;
        }
      }
      ans[i] = index+1;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
