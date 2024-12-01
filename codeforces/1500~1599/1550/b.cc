#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int ans = numeric_limits<int>::max();
  if (b >= 0) {
    ans = (a+b) * n;
  } else {
    if (s == string(n, '1')) {
      ans = n * a + b;
    } else if (s == string(n, '0')) {
      ans = n * a + b;
    } else {
      auto count_parts = [&](char ch) -> int {
        int count = 0;
        int i = 0;
        while (i < n) {
          if (s[i] != ch) i++;
          else {
            int j = i;
            while (j+1 < n && s[j+1] == s[i]) {
              j++;
            }
            i = j+1;
            count++;
          }
        }
        return count;
      };

      int ones = count_parts('1');
      int zeros = count_parts('0');
      ans = (min(ones, zeros) + 1) * b + n * a;
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
