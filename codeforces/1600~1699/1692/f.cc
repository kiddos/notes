#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> digits(10);
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    digits[a % 10]++;
  }

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < 10; ++k) {
        int d = (i + j + k) % 10;
        if (d == 3) {
          if (i == j && i == k) {
            if (digits[i] >= 3) {
              cout << "YES" << endl;
              return;
            }
          } else if (i == j) {
            if (digits[i] >= 2 && digits[k] > 0) {
              cout << "YES" << endl;
              return;
            }
          } else if (i == k) {
            if (digits[i] >= 2 && digits[j] > 0) {
              cout << "YES" << endl;
              return;
            }
          } else if (j == k) {
            if (digits[j] >= 2 && digits[i] > 0) {
              cout << "YES" << endl;
              return;
            }
          } else {
            if (digits[i] > 0 && digits[j] > 0 && digits[k] > 0) {
              cout << "YES" << endl;
              return;
            }
          }
        }
      }
    }
  }

  cout << "NO" << endl;
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
