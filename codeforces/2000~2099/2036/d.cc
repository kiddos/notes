#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  int size = min(n, m);
  int ans = 0;
  for (int i = 0; i < size / 2; ++i) {
    int r = i, c = i;
    vector<int> digits;
    while (c < m-i-1) {
      digits.push_back(s[r][c] - '0');
      c++;
    }
    while (r < n-i-1) {
      digits.push_back(s[r][c] - '0');
      r++;
    }
    while (c > i) {
      digits.push_back(s[r][c] - '0');
      c--;
    }
    while (r > i) {
      digits.push_back(s[r][c] - '0');
      r--;
    }
    int k = digits.size();
    for (int i = 0; i < k; ++i) {
      if (digits[i] == 1 && digits[(i+1) % k] == 5 && digits[(i+2) % k] == 4 && digits[(i+3) % k] == 3) {
        ans++;
      }
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
