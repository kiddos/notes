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

  constexpr int MAX_A = 110;
  vector<int> counts(MAX_A+1);
  for (int i = 0; i < n; ++i) {
    counts[a[i]]++;
  }

  int ans = 0;
  for (int i = 1; i <= MAX_A; ++i) {
    vector<int> c = counts;
    int len = 0;
    int j = i;
    while (true) {
      if (c[j-1] > 0) {
        c[j-1]--;
      } else if (c[j] > 0) {
        c[j]--;
      } else {
        break;
      }
      j++;
      len++;
    }
    ans = max(ans, len);
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
