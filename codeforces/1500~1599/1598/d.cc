#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  map<int, vector<int>> by_topic;
  for (int i = 0; i < n; ++i) {
    by_topic[a[i]].push_back(b[i]);
  }

  vector<int> difficulty_count(n+1);
  for (int i = 0; i < n; ++i) {
    difficulty_count[b[i]]++;
  }

  i64 remove = 0;
  for (auto& [t, list] : by_topic) {
    i64 total = list.size();
    for (int d : list) {
      remove += ((i64)difficulty_count[d] - 1) * (total - 1);
    }
  }

  i64 ans = n * (n-1) * (n-2) / 6 - remove;
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
