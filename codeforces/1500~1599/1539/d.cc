#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  vector<pair<i64,i64>> items;
  for (int i = 0; i < n; ++i) {
    items.emplace_back(a[i], b[i]);
  }
  sort(items.begin(), items.end(), [&](auto& i1, auto& i2) {
    return i1.second < i2.second;
  });

  i64 one = 0;
  i64 ans = 0;
  i64 bought = 0;
  for (int l = 0, r = n-1; l <= r; ++l) {
    if (items[l].first == 0) continue;

    i64 need_to_buy = items[l].second - bought;
    i64 buy_one = min(need_to_buy, one);
    ans += buy_one;
    need_to_buy -= buy_one;
    one -= buy_one;
    bought += buy_one;
    // cout << "buy one=" << buy_one << " one=" << one << endl;
    while (need_to_buy > 0 && r >= l) {
      i64 cost2 = min(items[r].first, need_to_buy);
      ans += cost2 * 2;
      items[r].first -= cost2;
      need_to_buy -= cost2;
      bought += cost2;
      if (items[r].first == 0) {
        r--;
      }
    }
    if (need_to_buy == 0) {
      one += items[l].first;
      items[l].first = 0;
    }
    // cout << "ans=" << ans << endl;
    // for (auto [a, b] : items) {
    //   cout << "(" << a << " " << b << ") ";
    // }
    // cout << endl;
  }
  // cout << "one=" << one << endl;
  ans += one;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
