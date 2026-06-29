#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 compute_value(const string& s) {
  int n = s.length();
  i64 y = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      y++;
    }
  }
  i64 x = n-y;
  return x * y;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s1, sk;
  cin >> s1 >> sk;

  using Key = tuple<string, string, int>;
  map<Key, i64> memo;
  auto divide = [&](const auto& self, const string& s1, const string& s2, int k) -> i64 {
    i64 val1 = compute_value(s1);
    i64 val2 = compute_value(s2);
    if (k == 0) {
      return val1 + val2;
    }

    Key key = {s1, s2, k};
    if (memo.count(key)) {
      return memo[key];
    }

    string middle;
    for (int i = 0; i < n; ++i) {
      int b1 = s1[i] - '0';
      int b2 = s2[i] - '0';
      int b3 = b1 ^ b2;
      middle.push_back(b3 + '0');
    }
    i64 top_result = self(self, s1, middle, k-1);
    i64 bot_result = self(self, middle, s2, k-1);
    i64 ans = top_result + bot_result - compute_value(middle);
    return memo[key] = ans;
  };

  i64 ans = divide(divide, s1, sk, k);
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
