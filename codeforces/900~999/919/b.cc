#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0;
  cin >> k;

  string current;
  vector<string> possible;
  auto dp = [&](const auto& self, int sum, int has_digit, int d) -> void {
    if (d == 1) {
      if (sum >= 0 && sum <= 9) {
        current.push_back(sum + '0');
        possible.push_back(current);
        current.pop_back();
      }
      return;
    }

    if (!has_digit) {
      for (int i = 1; i <= 9; ++i) {
        current.push_back(i + '0');
        self(self, sum-i, true, d-1);
        current.pop_back();
      }
    } else {
      for (int i = 0; i <= 9; ++i) {
        current.push_back(i + '0');
        self(self, sum-i, true, d-1);
        current.pop_back();
      }
    }
  };

  int d = 2;
  while ((int)possible.size() < k) {
    dp(dp, 10, 0, d);
    d++;
  }
  cout << possible[k-1] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
