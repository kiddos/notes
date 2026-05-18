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
  sort(a.begin(), a.end());

  if (n == 1) {
    cout << "-1" << endl;
    return;
  }

  map<int,vector<pair<int,int>>> diffs;
  for (int i = 1; i < n; ++i) {
    int d = a[i] - a[i-1];
    diffs[d].push_back({a[i-1], a[i]});
  }

  vector<int> ans;
  if (n == 2) {
    if ((a[1] + a[0]) % 2 == 0) {
      ans.push_back((a[1] + a[0]) / 2);
    }
    int d = a[1] - a[0];
    ans.push_back(a[0] - d);
    ans.push_back(a.back() + d);
  } else {
    if (diffs.size() == 1) {
      int d = a[1] - a[0];
      ans.push_back(a[0] - d);
      ans.push_back(a.back() + d);
    } else if (diffs.size() == 2) {
      for (auto [d, values] : diffs) {
        if (values.size() == 1) {
          int val1 = values[0].first, val2 = values[0].second;
          if ((val1 + val2) % 2 == 0) {
            int middle = (val2 + val1) / 2;
            int d2 = middle - val1;
            if (d2 != d && diffs.count(d2)) {
              ans.push_back(middle);
            }
          }
        }
      }
    }
  }

  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

  cout << ans.size() << endl;
  for (int ai : ans) {
    cout << ai << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
