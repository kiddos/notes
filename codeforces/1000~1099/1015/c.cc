#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    pq.push(a[i] - b[i]);
  }

  i64 not_compressed = accumulate(a.begin(), a.end(), 0LL);
  i64 need_to_remove = not_compressed - m;
  int ans = 0;
  while (need_to_remove > 0 && !pq.empty()) {
    int largest_reduce = pq.top();
    pq.pop();
    ans++;
    need_to_remove -= largest_reduce;
  }

  if (need_to_remove > 0) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
