#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(vector<ll>& a, int m) {
  int n = a.size();
  vector<ll> p = {0};
  for (int i = 0; i < n; ++i) p.push_back(p.back() + a[i]);

  priority_queue<int> largest;
  int ans = 0;
  for (int i = m; i >= 1; --i) {
    while (p[m] > p[i]) {
      p[m] -= largest.top() * 2LL;
      largest.pop();
      ans++;
    }
    largest.push(a[i-1]);
  }

  ll sum = p[m];
  priority_queue<int, vector<int>, greater<>> smallest;
  for (int i = m+1; i <= n; ++i) {
    sum += a[i-1];
    smallest.push(a[i-1]);
    while (p[m] > sum) {
      sum -= smallest.top() * 2;
      smallest.pop();
      ans++;
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
    int n = 0, m = 0;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    solve(a, m);
  }
  return 0;
}
