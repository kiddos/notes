#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<int> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  vector<pair<int,int>> monster;
  for (int i = 0; i < n; ++i) {
    monster.push_back({p[i], h[i]});
  }

  sort(monster.begin(), monster.end());
  ll hits = 0;
  for (int i = 0; i < n; ++i) {
    while (k > 0 && monster[i].second > k + hits) {
      hits += k;
      k -= monster[i].first;
    }
    if (k <= 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
