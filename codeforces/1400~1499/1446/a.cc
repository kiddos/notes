#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 W = 0;
  cin >> n >> W;
  vector<i64> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  vector<pair<i64,int>> items;
  for (int i = 0; i < n; ++i) {
    items.emplace_back(w[i], i);
  }
  sort(items.begin(), items.end());
  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + items[i].first);
  }

  vector<i64> ans;
  i64 low = (W+1) / 2;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = i;
    int index = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 sum = p[i+1] - p[mid];
      if (sum >= low) {
        index = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    if (index >= 0) {
      i64 sum = p[i+1] - p[index];
      if (sum >= low && sum <= W) {
        for (int k = index; k <= i; ++k) {
          ans.push_back(items[k].second + 1);
        }
        break;
      }
    }
  }

  if (ans.empty()) {
    cout << "-1" << endl;
  } else {
    cout << ans.size() << endl;
    for (i64 wi : ans) {
      cout << wi << " ";
    }
    cout << endl;
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
