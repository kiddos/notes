#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);

  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  set<int> indices;
  for (int i = 1; i <= n; ++i) {
    if (indices.empty() || a[i] < a[*indices.rbegin()]) {
      indices.insert(i);
    }
  }

  for (int i = 0; i < m; ++i) {
    int index = 0, d = 0;
    cin >> index >> d;
    a[index] = max(a[index] - d, 0);

    auto it = indices.upper_bound(index);
    if (it != indices.begin() && a[*(--it)] > a[index]) {
      indices.insert(index);
    }
    while (true) {
      it = indices.lower_bound(index+1);
      if (it == indices.end()) {
        break;
      } else {
        if (a[*it] >= a[index]) {
          indices.erase(it);
          it = indices.lower_bound(index+1);
        } else {
          break;
        }
      }
    }

    int ans = indices.size();
    cout << ans << " ";
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
