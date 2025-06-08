#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }

  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  int h = 0;
  vector<int> st;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (d[i] == -1) {
      st.push_back(i);
    } else if (d[i] == 1) {
      ans[i] = 1;
      h++;
    }

    while (!st.empty() && h < l[i]) {
      int idx = st.back();
      st.pop_back();
      ans[idx] = 1;
      h++;
    }
  }

  h = 0;
  for (int i = 0; i < n; ++i) {
    if (ans[i] == 1) {
      h++;
    }
    if (h < l[i] || h > r[i]) {
      cout << "-1" << endl;
      return;
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
