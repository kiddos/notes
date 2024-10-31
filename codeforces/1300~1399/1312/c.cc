#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  priority_queue<i64, vector<i64>, less<>> pq;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      pq.push(a[i]);
    }
  }

  if (pq.empty()) {
    cout << "YES" << endl;
    return;
  }

  i64 x = k;
  while (x < pq.top()) {
    x *= k;
  }

  while (!pq.empty() && x > 0) {
    while (x > 0 && x > pq.top()) {
      x /= k;
    }
    if (x == 0) {
      break;
    }
    i64 y = pq.top();
    pq.pop();
    if (y - x > 0) {
      pq.push(y - x);
    }
    x /= k;
  }
  if (pq.empty()) {
    cout << "YES" << endl;
  } else{
    cout << "NO" << endl;
  }
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
