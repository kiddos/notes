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
  int total_collected = 0;
  vector<bool> collected(n);
  int ans = 0;
  int flag = 1;
  while (true) {
    if (flag) {
      for (int i = 0; i < n; ++i) {
        if (collected[i]) {
          continue;
        }
        if (a[i] <= total_collected) {
          collected[i] = true;
          total_collected++;
        }
      }
    } else {
      for (int i = n-1; i >= 0; --i) {
        if (collected[i]) {
          continue;
        }
        if (a[i] <= total_collected) {
          collected[i] = true;
          total_collected++;
        }
      }
    }
    flag ^= 1;
    if (total_collected >= n) {
      break;
    }
    ans++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
