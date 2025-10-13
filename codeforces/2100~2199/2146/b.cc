#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> S;
  for (int i = 0; i < n; ++i) {
    int size = 0;
    cin >> size;
    vector<int> s(size);
    for (int j = 0; j < size; ++j) {
      cin >> s[j];
    }
    S.push_back(s);
  }

  map<int,int> count;
  for (vector<int>& s : S) {
    for (int e : s) {
      count[e]++;
    }
  }

  int possible = 0;
  for (vector<int>& s : S) {
    for (int e : s) {
      if (--count[e] == 0) {
        count.erase(e);
      }
    }
    if ((int)count.size() == m) {
      possible++;
    }
    for (int e : s) {
      count[e]++;
    }
  }

  if (possible >= 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
