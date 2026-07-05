#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int i = 0;
  i64 ans = 0;
  while (i < n) {
    if (s[i] == '.') {
      int j = i;
      while (j+1 < n && s[j+1] == '.') {
        j++;
      }
      int len = j-i+1;
      i = j+1;

      if (len % 2 == 0) {
        int sit = len / 2;
        int sit_a = min(a, sit);
        int sit_b = min(b, sit);
        ans += sit_a + sit_b;
        a -= sit_a;
        b -= sit_b;
      } else if (len % 2 == 1) {
        if (a >= b) {
          int sit = len / 2;
          int sit_a = min(a, sit+1);
          int sit_b = min(b, sit);
          ans += sit_a + sit_b;
          a -= sit_a;
          b -= sit_b;
        } else {
          int sit = len / 2;
          int sit_a = min(a, sit);
          int sit_b = min(b, sit+1);
          ans += sit_a + sit_b;
          a -= sit_a;
          b -= sit_b;
        }
      }
    } else {
      i++;
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
