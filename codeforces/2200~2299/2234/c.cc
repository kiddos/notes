#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  int max_height = *max_element(h.begin(), h.end());
  vector<i64> ans;
  for (int i = 0; i < n; ++i) {
    vector<i64> w(n);
    int idx = i;
    int stop_at = i;
    while (true) {
      int i1 = idx;
      int i2 = (idx+1)%n;
      i64 right_height = h[idx];
      if (right_height == max_height) {
        stop_at = idx;
        break;
      }
      w[i2] = max(w[i1], right_height);
      idx = i2;
    }

    idx = i;
    while (true) {
      int i1 = idx;
      int i2 = (idx-1+n)%n;
      if (i2 == stop_at) {
        break;
      }
      i64 left_height = h[i2];
      w[i2] = max(w[i1], left_height);
      idx = i2;
    }

    // for (int j = 0; j < n; ++j) {
    //   cout << ans[j] << " ";
    // }
    // cout << endl;
    i64 sum = accumulate(w.begin(), w.end(), 0LL);
    ans.push_back(sum);
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
