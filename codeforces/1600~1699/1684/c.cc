#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  set<pair<int,int>> s;
  for (int i = 0; i < n; ++i) {
    vector<int> row = a[i];
    sort(row.begin(), row.end());
    int diff = 0;
    vector<int> index;
    for (int j = 0; j < m; ++j) {
      if (row[j] != a[i][j]) {
        diff++;
        index.push_back(j);
      }
    }

    if (diff != 2 && diff != 0) {
      cout << "-1" << endl;
      return;
    }

    if (diff == 2) {
      s.insert({index[0]+1, index[1]+1});
    }
  }

  if (s.empty()) {
    cout << "1 1" << endl;
  } else if (s.size() > 1) {
    cout << "-1" << endl;
  } else {
    pair<int,int> index = *s.begin();

    for (int i = 0; i < n; ++i) {
      swap(a[i][index.first-1], a[i][index.second-1]);
      for (int j = 1; j < m; ++j) {
        if (a[i][j-1] > a[i][j]) {
          cout << "-1" << endl;
          return;
        }
      }
    }

    cout << index.first << " " << index.second << endl;
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
