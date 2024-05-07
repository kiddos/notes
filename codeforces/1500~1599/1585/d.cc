#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  // if there is duplicate number, it is possible
  map<int, int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
    if (count[a[i]] > 1) {
      cout << "YES" << endl;
      return;
    }
  }

  set<pair<int,int>> s;
  for (int i = 0; i < n; ++i) {
    s.insert({a[i], i});
  }

  for (int i = n-1; i >= 2; --i) {
    s.erase({a[i], i});

    if (a[i] >= s.rbegin()->first) {
      continue;
    }

    auto [a1, i1] = *s.rbegin();
    s.erase(prev(s.end()));
    auto [a2, i2] = *s.rbegin();
    s.erase(prev(s.end()));

    vector<pair<int,int>> p = {{a1, i1}, {a2, i2}, {a[i], i}};
    sort(p.rbegin(), p.rend());

    if (p[0].second == i) {
      continue;
    } else if (p[0].second == i1) {
      // i1 -> i -> i2 -> i1
      int temp = a[i];
      a[i] = a1;
      a[i2] = temp;
      a[i1] = a2;
      s.insert({temp, i2});
      s.insert({a2, i1});
    } else if (p[0].second == i2) {
      //  i2 -> i -> i1 -> i2
      int temp = a[i];
      a[i] = a2;
      a[i1] = temp;
      a[i2] = a1;
      s.insert({temp, i1});
      s.insert({a1, i2});
    }
  }

  for (int i = 1; i < n; ++i) {
    if (a[i-1] > a[i]) {
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
