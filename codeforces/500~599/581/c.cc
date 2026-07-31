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

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  for (int i = 0; i < n; ++i) {
    int next_10 = (a[i] + 9) / 10 * 10;
    int require = next_10 - a[i];
    if (require == 0) {
      next_10 += 10;
      if (next_10 <= 100) {
        pq.push({10, i});
      } 
    } else {
      pq.push({require, i});
    }
  }

  while (!pq.empty() && k >= pq.top().first) {
    auto [require, idx] = pq.top();
    pq.pop();
    k -= require;
    a[idx] += require;
    if (a[idx] + 10 <= 100) {
      pq.push({10, idx});
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] / 10;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
