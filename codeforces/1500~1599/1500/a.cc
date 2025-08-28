#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int max_val = *max_element(a.begin(), a.end());
  vector<vector<int>> indices(max_val+1);
  for (int i = 1; i <= n; ++i) {
    indices[a[i]].push_back(i);
  }
  pair<int,int> last = {-1, -1};
  for (int x = 1; x <= max_val; ++x) {
    if (indices[x].size() >= 4) {
      cout << "YES" << endl;
      cout << indices[x][0] << " " << indices[x][1] << " " << indices[x][2] << " " << indices[x][3] << endl;
      return;
    } else if (indices[x].size() >= 2) {
      if (last.first < 0) {
        last = {indices[x][0], indices[x][1]};
      } else {
        cout << "YES" << endl;
        cout << last.first << " " << indices[x][0] << " " << last.second << " " << indices[x][1] << endl;
        return;
      }
    }
  }

  vector<pair<int,int>> p(max_val*2+1, {-1, -1});
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      int sum = a[i] + a[j];
      if (p[sum].first < 0) {
        p[sum] = {i, j};
      } else {
        set<int> s = {p[sum].first, p[sum].second, i, j};
        if (s.size() == 4) {
          cout << "YES" << endl;
          cout << p[sum].first << " " << p[sum].second << " " << j << " " << i << endl;
          return;
        }
      }
    }
  }

  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
