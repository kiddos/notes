#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int trailing_zero(int x) {
  int ans = 0;
  while (x > 0) {
    int d = x % 10;
    if (d != 0) {
      break;
    }
    ans++;
    x /= 10;
  }
  return ans;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  priority_queue<pair<int,int>> pq;
  for (int i = 0; i < n; ++i) {
    string s = to_string(a[i]);
    pq.push({trailing_zero(a[i]), (int)s.length()});
  }
  
  while (true) {
    // anna
    auto x1 = pq.top();
    pq.pop();
    pq.push({0, x1.second-x1.first});

    if (pq.size() <= 1) break;
    // sasha
    x1 = pq.top();
    pq.pop();
    auto x2 = pq.top();
    pq.pop();
    int z = x2.first;
    int len = x1.second + x2.second;
    pq.push({z, len});
  }

  if (pq.top().second > m) {
    cout << "Sasha" << endl;
  } else {
    cout << "Anna" << endl;
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
