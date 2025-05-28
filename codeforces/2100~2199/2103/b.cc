#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int ops(string& s) {
  int n = s.length();
  int ans = n;
  for (int i = 0; i < n; ++i) {
    char prev = i == 0 ? '0' : s[i-1];
    if (s[i] != prev) {
      ans++;
    }
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  auto i1 = s.find('0');
  auto i2 = s.find('1');
  if (i1 == string::npos) {
    // all ones
    cout << n + 1 << endl;
  } else if (i2 == string::npos) {
    // all zero
    cout << n << endl;
  } else {
    int ans = ops(s);
    int i = 0;
    int segment = 0;
    while (i < n) {
      int j = i;
      while (j+1 < n && s[j+1] == s[j]) {
        j++;
      }
      i = j+1;
      segment++;
    }
    if (segment == 2) {
      if (s[0] == '1') {
        ans--;
      }
    } else if (segment == 3) {
      if (s[0] == '0') {
        // 010 -> 001
        ans--;
      } else if (s[0] == '1') {
        // 101 -> 011
        ans -= 2;
      }
    } else if (segment >= 4) {
      ans -= 2;
    }

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
