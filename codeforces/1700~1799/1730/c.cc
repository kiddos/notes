#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  vector<int> digits(10);
  for (int i = 0; i < n; ++i) {
    digits[s[i]-'0']++;
  }

  auto has_smaller = [&](int d) {
    for (int i = 0; i < d; ++i) if (digits[i] > 0) return true;
    return false;
  };

  vector<int> buffer(10);
  string ans;
  for (int i = 0; i < s.length(); ++i) {
    int d = s[i]-'0';
    digits[d]--;
    if (has_smaller(d)) {
      int d2 = min(d+1, 9);
      buffer[d2]++;
    } else {
      for (int d2 = 0; d2 < d; ++d2) {
        while (buffer[d2] > 0) {
          ans.push_back(d2 + '0');
          buffer[d2]--;
        }
      }
      ans.push_back(d + '0');
    }
  }
  for (int d2 = 0; d2 < 10; ++d2) {
    while (buffer[d2] > 0) {
      ans.push_back(d2 + '0');
      buffer[d2]--;
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
