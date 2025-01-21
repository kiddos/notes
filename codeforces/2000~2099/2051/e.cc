#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  set<int> prices;
  for (int i = 0; i < n; ++i) {
    prices.insert(a[i]);
    prices.insert(b[i]);
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pos;
  for (int i = 0; i < n; ++i) {
    pos.push({a[i], b[i]});
  }
  priority_queue<int, vector<int>, greater<>> neg;
  i64 ans = 0;
  for (int price : prices) {
    while (!pos.empty() && pos.top().first < price) {
      neg.push(pos.top().second);
      pos.pop();
    }
    while (!neg.empty() && neg.top() < price) {
      neg.pop();
    }
    if ((int) neg.size() <= k) {
      i64 total_buy = neg.size() + pos.size();
      ans = max(ans, total_buy * price);
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
