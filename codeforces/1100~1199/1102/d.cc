#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> count(3);
  for (int i = 0; i < n; ++i) {
    count[s[i]-'0']++;
  }
  int expected_size = n / 3;
  vector<int> d(3);
  for (int i = 0; i < 3; ++i) {
    d[i] = count[i] - expected_size;
  }

  for (int c1 = 0; c1 < 2; ++c1) {
    for (int i = 0; i < n && d[c1] < 0; ++i) {
      int c2 = s[i]-'0';
      if (c2 > c1 && d[c2] > 0) {
        s[i] = c1 + '0';
        d[c1]++;
        d[c2]--;
      }
    }
  }

  for (int c1 = 2; c1 >= 1; --c1) {
    for (int i = n-1; i >= 0 && d[c1] < 0; --i) {
      int c2 = s[i]-'0';
      if (c2 < c1 && d[c2] > 0) {
        s[i] = c1 + '0';
        d[c1]++;
        d[c2]--;
      }
    }
  }

  cout << s << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
