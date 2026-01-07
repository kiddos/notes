#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 1000;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> lucky;
  auto generate = [&](const auto& self, int x) -> void {
    if (x > MAX_N) {
      return;
    }
    lucky.push_back(x);
    self(self, x * 10 + 4);
    self(self, x * 10 + 7);
  };

  generate(generate, 4);
  generate(generate, 7);

  for (int l : lucky) {
    if (n % l == 0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
