#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];

  i64 total = accumulate(c.begin(), c.end(), 0LL);
  i64 ones = total / n;

  vector<int> ans(n);
  if (ones > 0) {
    priority_queue<int, vector<int>, less<>> pq;
    for (int i = n-1; i >= 0; --i) {
      while (!pq.empty() && pq.top() > i) {
        pq.pop();
      }

      c[i] -= pq.size();

      int from = i - ones+1;
      if (c[i] == i+1) {
        ans[i] = 1;
        ones--;
      }
      if (ones > 0) {
        pq.push(from);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
