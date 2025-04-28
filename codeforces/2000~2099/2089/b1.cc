#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < n; ++i) {
    int remove = min(a[i], b[i]);
    a[i] -= remove;
    b[i] -= remove;
  }

  int start = 0;
  while (start < n && a[start] == 0) {
    start++;
  }

  int ans = 1;
  vector<int> st;
  for (int i = start; i < n * 2; ++i) {
    if (a[i%n] > 0) {
      st.push_back(i);
    } else if (b[i%n] > 0) {
      while (b[i%n] > 0 && !st.empty()) {
        int j = st.back();
        int remove = min(a[j%n], b[i%n]);
        a[j%n] -= remove;
        b[i%n] -= remove;
        if (a[j%n] == 0) {
          st.pop_back();
        }
        int len = (i-j+1);
        // cout << "len=" <<  len << endl;
        ans = max(ans, len);
      }
    }
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
