#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int, 4>> laptop;
  for (int i = 0; i < n; ++i) {
    int speed = 0, ram = 0, hdd = 0, cost = 0;
    cin >> speed >> ram >> hdd >> cost;
    laptop.push_back({speed, ram, hdd, cost});
  }

  auto outdated = [&](int i) {
    auto [s0, r0, h0, c0] = laptop[i];
    for (int j = 0; j < n; ++j) {
      auto [s, r, h, c] = laptop[j];
      if (s > s0 && r > r0 && h > h0) {
        return true;
      }
    }
    return false;
  };
  
  vector<pair<int,int>> costs;
  for (int i = 0; i < n; ++i) {
    if (!outdated(i)) {
      costs.push_back({laptop[i][3], i+1});
    }
  }
  sort(costs.begin(), costs.end());
  cout << costs[0].second << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
