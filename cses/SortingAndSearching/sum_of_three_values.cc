#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 x = 0;
  cin >> n >> x;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<i64,int>> p;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(a[i], i+1);
  }

  sort(p.begin(), p.end());

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      i64 s2 = x - p[i].first - p[j].first;
      int l = j+1, r = n-1;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        if (p[mid].first == s2) {
          cout << p[i].second << " " << p[j].second << " " << p[mid].second << endl;
          return;
        } else if (p[mid].first < s2) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
