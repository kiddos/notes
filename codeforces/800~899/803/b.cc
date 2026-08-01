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

  constexpr int inf = 1e9;
  vector<int> right(n, inf);
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      while (!st.empty()) {
        right[st.back()] = i - st.back();
        st.pop_back();
      }
      right[i] = 0;
    } else {
      st.push_back(i);
    }
  }

  vector<int> left(n, inf);
  st.clear();
  for (int i = n-1; i >= 0; --i) {
    if (a[i] == 0) {
      while (!st.empty()) {
        left[st.back()] = st.back() - i;
        st.pop_back();
      }
      left[i] = 0;
    } else {
      st.push_back(i);
    }
  }

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = min(left[i], right[i]);
  }
  for (int i = 0; i < n; ++i) {
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
