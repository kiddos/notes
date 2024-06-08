#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<vector<int>> transpose(vector<vector<int>>& a) {
  int n = a.size(), m = a[0].size();
  vector<vector<int>> b(m, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      b[j][i] = a[i][j];
    }
  }
  return b;
}

bool check(vector<vector<int>>& a, vector<vector<int>>& b) {
  int n = a.size(), m = a[0].size();
  set<vector<int>> cols;
  for (int j = 0; j < m; ++j) {
    vector<int> c;
    for (int i = 0; i < n; ++i) {
      c.push_back(b[i][j]);
    }
    cols.insert(c);
  }
  for (int j = 0; j < m; ++j) {
    vector<int> c;
    for (int i = 0; i < n; ++i) {
      c.push_back(a[i][j]);
    }
    if (!cols.count(c)) {
      return false;
    }
  }
  return true;
};

int find_index(vector<vector<int>>& a, vector<int> col) {
  int n = a.size(), m = a[0].size();
  for (int j = 0; j < m; ++j) {
    vector<int> c;
    for (int i = 0; i < n; ++i) {
      c.push_back(a[i][j]);
    }
    sort(c.begin(), c.end());

    if (c == col) {
      return j;
    }
  }
  return -1;
}

bool validate(vector<vector<int>>& a, vector<vector<int>>& b) {
  int n = a.size();
  vector<int> col;
  for (int i = 0; i < n; ++i) col.push_back(a[i][0]);
  sort(col.begin(), col.end());
  int idx = find_index(b, col);
  if (idx < 0) {
    return false;
  }
  sort(a.begin(), a.end(), [&](auto r1, auto r2) {
    return r1[0] < r2[0];
  });
  sort(b.begin(), b.end(), [&](auto r1, auto r2) {
    return r1[idx] < r2[idx];
  });

  return check(a, b);
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> b[i][j];
    }
  }

  vector<vector<int>> c = a, d = b;
  if (!validate(c, d)) {
    cout << "NO" << endl;
    return;
  }

  c = transpose(a);
  d = transpose(b);
  if (!validate(c, d)) {
    cout << "NO" << endl;
    return;
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
