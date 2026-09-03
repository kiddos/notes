#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }



  int ans = 0;
  for (int i = 0; i < n; ++i) {
    set<pair<int,int>> p;
    int len = n-i;
    for (int j = 0; j < len; ++j) {
      p.insert({b[j], j});
    }

    vector<int> move_to(len);
    for (int j = 0; j < len; ++j) {
      auto it = p.lower_bound({a[j], -1});
      if (it == p.end()) {
        cout << "-1" << endl;
        return;
      }
      move_to[j] = it->second;
      p.erase(it);
    }

    int from = max_element(move_to.begin(), move_to.end()) - move_to.begin();
    for (int j = from+1; j < len; ++j) {
      swap(a[j-1], a[j]);
      ans++;
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;

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
