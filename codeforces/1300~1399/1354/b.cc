#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> next1(n+1, -1), next2(n+1, -1), next3(n+1, -1);
  for (int i = n-1; i >= 0; --i) {
    next1[i] = next1[i+1];
    next2[i] = next2[i+1];
    next3[i] = next3[i+1];
    if (s[i] == '1') {
      next1[i] = i;
    } else if (s[i] == '2') {
      next2[i] = i;
    } else if (s[i] == '3') {
      next3[i] = i;
    }
  }
  int ans = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    int p1 = -1, p2 = -1;
    if (s[i] == '1') {
      p1 = next2[i], p2 = next3[i];
    } else if (s[i] == '2') {
      p1 = next1[i], p2 = next3[i];
    } else if (s[i] == '3') {
      p1 = next1[i], p2 = next2[i];
    }

    if (p1 >= 0 && p2 >= 0) {
      int len = max(p1, p2) - i + 1;
      ans = min(ans, len);
    }
  }

  if (ans == numeric_limits<int>::max()) {
    cout << "0" << endl;
  } else {
    cout << ans << endl;
  }
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
