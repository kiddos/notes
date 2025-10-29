#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }

  vector<int> ans(n+1);
  vector<int> st;
  for (int i = n; i >= 1; --i) {
    while (!st.empty() && x[st.back()] > x[i]) {
      ans[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
