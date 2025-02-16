#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i =0; i <  n; ++i) {
    cin >> a[i];
  }

  vector<int> st;
  vector<bool> ans(n);
  for (int i = 0; i < n; ++i) {
    st.push_back(i);
    while (!st.empty() && i - st.back()+1 <= a[i]) {
      ans[st.back()] = true;
      st.pop_back();
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
