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

  vector<int> right(n, n);
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && h[st.back()] < h[i]) {
      right[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }

  vector<int> left(n, -1);
  st.clear();
  for (int i = n-1; i >= 0; --i) {
    while (!st.empty() && h[st.back()] < h[i]) {
      left[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }

  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({h[i], i});
  }
  sort(p.begin(), p.end());
  vector<int> dp(n, 1);
  for (auto [val, idx] : p) {
    int l = left[idx];
    if (l >= 0) {
      dp[l] = max(dp[l], dp[idx] + 1);
    }
    int r = right[idx];
    if (r < n) {
      dp[r] = max(dp[r], dp[idx] + 1);
    }
  }
  int ans = *max_element(dp.begin(), dp.end());
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
