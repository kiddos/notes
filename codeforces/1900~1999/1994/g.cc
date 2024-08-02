#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s0;
  cin >> s0;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> s;
  for (int i = 0; i < k; ++i) {
    s.push_back(s0[i] - '0');
  }
  reverse(s.begin(), s.end());

  for (int i = 0; i < n; ++i) {
    reverse(a[i].begin(), a[i].end());
  }

  vector<array<int, 2>> bit_sums(k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      if (a[i][j] == '1') {
        bit_sums[j][0]++;
      }
    }
  }
  for (int j = 0; j < k; ++j) {
    bit_sums[j][1] = n - bit_sums[j][0];
  }

  vector<vector<int>> memo(k, vector<int>(2 * (n + 1), -1));
  vector<int> ans(k);
  function<int(int,int)> sum = [&](int i, int carry) -> int {
    if (i == k) {
      return carry == 0 ? 1 : 0;
    }
    if (memo[i][carry] >= 0) {
      return memo[i][carry];
    }

    for (int b = 0; b < 2; ++b) {
      int bit_sum = bit_sums[i][b] + carry;
      int digit = bit_sum % 2;
      if (digit == s[i] && sum(i+1, bit_sum / 2)) {
        ans[i] = b;
        return memo[i][carry] = 1;
      }
    }
    return memo[i][carry] = 0;
  };

  bool possible = sum(0, 0);
  if (!possible) {
    cout << "-1" << endl;
  } else {
    string x;
    for (int i = 0; i < k; ++i) {
      x.push_back(ans[i] + '0');
    }
    reverse(x.begin(), x.end());
    cout << x << endl;
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
