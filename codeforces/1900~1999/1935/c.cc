#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, l = 0;
  cin >> n >> l;
  vector<pair<int,int>> messages;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    messages.emplace_back(b, a);
  }

  sort(messages.begin(), messages.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    priority_queue<int, vector<int>, less<>> pq;
    i64 a_sum = 0;
    for (int j = i; j < n; ++j) {
      a_sum += messages[j].second;
      pq.push(messages[j].second);
      i64 b_diff = messages[j].first - messages[i].first;
      while (a_sum + b_diff > l && !pq.empty()) {
        a_sum -= pq.top();
        pq.pop();
      }

      ans = max(ans, (int)pq.size());
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}