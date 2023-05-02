#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  map<int,int> a_count;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    a_count[a]++;
  }
  vector<pair<int,int>> a(a_count.begin(), a_count.end());

  if (a.size() == 1) {
    cout << a[0].second / 2 << endl;
    return;
  }

  ll current = 0;
  ll ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    current += a[i].second;
    ll left = n - current;
    ans = max(ans, current * left);
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
