#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, A = 0, B = 0;
  cin >> n >> A >> B;
  string s;
  cin >> s;
  
  constexpr int INF = numeric_limits<int>::max();
  vector<vector<vector<vector<int>>>> memo(n, vector<vector<vector<int>>>(n+1, vector<vector<int>>(A, vector<int>(B, -1))));
  vector<vector<vector<vector<array<int,4>>>>> next(n, vector<vector<vector<array<int,4>>>>(n+1, vector<vector<array<int,4>>>(A, vector<array<int,4>>(B))));
  function<int(int,int,int,int)> dp = [&](int i, int ca, int a, int b) -> int {
    if (i == n) {
      int cb = n - ca;
      if (a == 0 && b == 0 && cb > 0 && ca > 0) {
        int cb = n - ca;
        return abs(cb - ca);
      } else {
        return INF;
      }
    }

    if (memo[i][ca][a][b] >= 0) {
      return memo[i][ca][a][b];
    }

    int d = s[i] - '0';
    int choose_a = dp(i+1, ca+1, (a * 10 + d) % A, b);
    int choose_b = dp(i+1, ca, a, (b * 10 + d) % B);
    // array<int,4> key = {i, ca, a, b};
    if (choose_a <= choose_b) {
      next[i][ca][a][b] = {i+1, ca+1, (a * 10 + d) % A, b};
    } else {
      next[i][ca][a][b] = {i+1, ca, a, (b * 10 + d) % B};
    }
    int result = min(choose_a, choose_b);
    return memo[i][ca][a][b] = result;
  };

  int value = dp(0, 0, 0, 0);
  if (value == INF) {
    cout << "-1" << endl;
    return;
  }

  array<int,4> p = {0, 0, 0, 0};
  string ans;
  while (p[0] < n) {
    array<int,4> p2 = next[p[0]][p[1]][p[2]][p[3]];
    // cout << p2[0] << " " << p2[1] << " " << p2[2] << " " << p2[3] << endl;
    if (p2[1] > p[1]) {
      ans.push_back('R');
    } else {
      ans.push_back('B');
    }
    p = std::move(p2);
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
