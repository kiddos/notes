#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<pair<int,int>> items;
  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) {
      items.emplace_back(a[i], b[i]);
    }
  }
  sort(items.begin(), items.end());

  priority_queue<int, vector<int>, greater<>> large;
  priority_queue<int, vector<int>, less<>> small;
  i64 a_sum = 0;
  i64 b_sum = 0, remove_b = 0;
  i64 ans = 0;
  int m = items.size();
  for (int i = 0; i < m; ++i) {
    a_sum += items[i].first;
    b_sum += items[i].second;
    remove_b += items[i].second;
    large.push(items[i].second);
    while ((int)large.size() > k) {
      small.push(large.top());
      remove_b -= large.top();
      large.pop();
    }
    while (!large.empty() && !small.empty()) {
      if (large.top() >= small.top()) {
        break;
      }
      int l = large.top();
      large.pop();
      int s = small.top();
      small.pop();
      remove_b -= l;
      remove_b += s;
    }

    i64 sum = b_sum - remove_b - a_sum;
    ans = max(ans, sum);
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
