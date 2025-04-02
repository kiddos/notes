#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Gate {
  char op1, op2;
  int a1, a2;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<Gate> gates;
  for (int i = 0; i < n; ++i) {
    char op1 = '\0', op2 = '\0';
    int a1 = 0, a2 = 0;
    cin >> op1 >> a1 >> op2 >> a2;
    gates.push_back(Gate{op1, op2, a1, a2});
  }

  auto gain = [&](char op, int a, i64 c) -> i64 {
    if (op == '+') {
      return a;
    } else if (op == 'x') {
      return c * (a-1);
    }
    return 0;
  };

  vector<vector<array<i64,3>>> memo(n+1, vector<array<i64,3>>(2, {-1, -1, -1}));
  function<array<i64,3>(int,int)> dp = [&](int i, int side) -> array<i64,3> {
    if (i == 0) {
      return {2, 1, 1};
    }
    if (memo[i][side][0] >= 0) {
      return memo[i][side];
    }
    array<i64,3> ans = {0, 0, 0};
    auto [op1, op2, a1, a2] = gates[i-1];
    for (int s0 = 0; s0 < 2; ++s0) {
      auto result = dp(i-1, s0);
      array<i64,3> current_choice = {0, result[1], result[2]};
      current_choice[side+1] += gain(op1, a1, result[1]) + gain(op2, a2, result[2]);
      current_choice[0] = current_choice[1] + current_choice[2];
      if (current_choice[0] > ans[0]) {
        ans = current_choice;
      } else if (current_choice[0] == ans[0] && current_choice[side+1] > ans[side+1]) {
        ans = current_choice;
      }
    }
    return memo[i][side] = ans;
  };

  auto result = max(dp(n, 0), dp(n, 1));
  cout << result[0] << endl;
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
