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

  vector<int> b = a;
  sort(b.begin(), b.end());
  set<int> one, two;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      one.insert(i);
    } else if (a[i] == 2) {
      two.insert(i);
    }
  }

  vector<pair<int,int>> ans;
  for (int i = n-1; i >= 0; --i) {
    if (b[i] - a[i] == 2) {
      int i1 = *one.begin();
      one.erase(one.begin());
      ans.emplace_back(i1, i);
      a[i1]--;
      a[i]++;
      int i2 = *two.begin();
      two.erase(two.begin());
      one.insert(i2);
      ans.emplace_back(i2, i);
      a[i2]--;
      a[i]++;
      two.insert(i);
    } else if (b[i] - a[i] == 1) {
      if (a[i] == 0) {
        int i1 = *one.begin();
        one.erase(one.begin());
        ans.emplace_back(i1, i);
        a[i1]--;
      } else if (a[i] == 1) {
        int i1 = *two.begin();
        two.erase(two.begin());
        one.insert(i1);
        ans.emplace_back(i1, i);
        a[i1]--;
      }
      a[i]++;
    }

    // for (int i =0; i < n; ++i) {
    //   cout << a[i] << " ";
    // }
    // cout << endl;
  }

  cout << ans.size() << endl;
  for (auto [u, v] : ans) {
    cout << u+1 << " " << v+1 << endl;
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
