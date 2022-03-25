#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool solve(vector<ll>& a) {
  multiset<ll> s(a.begin(), a.end());

  ll total = accumulate(a.begin(), a.end(), 0LL);
  queue<ll> q;
  q.push(total);
  while (!q.empty()) {
    if (q.size() > s.size()) return false;
    for (int size = q.size(); size > 0; --size) {
      ll value = q.front();
      q.pop();
      if (s.count(value)) {
        s.erase(s.find(value));
      } else {
        q.push(value / 2);
        q.push(value / 2 + (value % 2 == 1));
      }
    }
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool ans = solve(a);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout.flush();
  return 0;
}
