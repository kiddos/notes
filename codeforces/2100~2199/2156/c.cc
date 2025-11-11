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
  vector<int> count(n+1);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<int> suffix = count;
  for (int i = n-1; i >= 0; --i) {
    suffix[i] += suffix[i+1];
  }

  for (int i = n; i >= 2; --i) {
    int to_remove = n - count[i];
    if (i*2 <= n) {
      to_remove -= count[i * 2];
    }
    if (i*3 <= n) {
      to_remove -= count[i * 3];
    }
    if (i*4 <= n) {
      to_remove -= suffix[i*4];
    }
    if (to_remove <= k) {
      cout << i << endl;
      return;
    }
  }
  cout << "1" << endl;
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
