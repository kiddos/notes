#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  map<int, int> count;
  for (int i = 0; i < n; ++i) {
    int b = 0, min_b = 0;
    for (char ch : s[i]) {
      if (ch == '(') {
        b++;
      } else if (ch == ')') {
        b--;
      }
      min_b = min(min_b, b);
    }

    if (min_b < 0 && b != min_b) {
      // impossible to form
      // )))(((
      continue;
    }

    count[b]++;
  }

  int ans = 0;
  for (auto it = count.lower_bound(0); it != count.end(); ++it) {
    auto [b, c] = *it;
    if (b == 0) {
      ans += c / 2;
    } else {
      if (count.count(-b)) {
        ans += min(c, count[-b]);
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
