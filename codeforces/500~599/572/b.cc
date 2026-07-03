#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Order {
  char type;
  int p, q;
};

void solve() {
  int n = 0, s = 0;
  cin >> n >> s;
  map<int, int> sell, buy;
  for (int i = 0; i < n; ++i) {
    char ch = '\0';
    int p = 0, q = 0;
    cin >> ch >> p >> q;
    if (ch == 'B') {
      buy[p] += q;
    } else if (ch == 'S') {
      sell[p] += q;
    }
  }
  auto it1 = sell.begin();
  vector<Order> ans1;
  for (int k = 0; k < s && it1 != sell.end(); ++k) {
    ans1.push_back({'S', it1->first, it1->second});
    it1 = next(it1);
  }
  reverse(ans1.begin(), ans1.end());

  vector<Order> ans2;
  auto it2 = buy.rbegin();
  for (int k = 0; k < s && it2 != buy.rend(); ++k) {
    ans2.push_back({'B', it2->first, it2->second});
    it2 = next(it2);
  }

  for (auto [type, p, q] : ans1) {
    cout << type << " " << p << " " << q << endl;
  }
  for (auto [type, p, q] : ans2) {
    cout << type << " " << p << " " << q << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
