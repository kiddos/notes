#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> event(n);
  for (int i = 0; i < n; ++i) {
    cin >> event[i];
  }
  int officers = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (event[i] >= 0) {
      officers += event[i];
    } else {
      if (officers == 0) {
        ans++;
      } else {
        officers--;
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
