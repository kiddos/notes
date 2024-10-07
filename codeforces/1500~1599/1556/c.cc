#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  if (n % 2 == 1) {
    n--;
  }
  i64 ans = 0;
  for (int i = 0; i < n; i += 2) {
    if (c[i+1] > c[i]) {
      ans += c[i];
    } else {
      i64 left = c[i] - c[i+1];
      i64 right = 0;
      ans += c[i+1];
      for (int j = i+2; j < n; j += 2) {
        right += c[j+1] - c[j];
        if (right >= 0) {
          ans += min(right, left) + 1;
          left -= right;
          if (left < 0) {
            break;
          }
          right = 0;
        }

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
