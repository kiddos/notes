#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int, 6>> r(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> r[i][j];
    }
    r[i][5] = i;
  }

  auto is_gold_medal = [&](int idx) -> bool {
    vector<int> index(n);
    iota(index.begin(), index.end(), 0);
    vector<int> superior(n);
    for (int j = 0; j < 5; ++j) {
      sort(index.begin(), index.end(), [&](int i1, int i2) {
        return r[i1][j] < r[i2][j];
      });
      int start = find(index.begin(), index.end(), idx) - index.begin();
      for (int i = start+1; i < n; ++i) {
        superior[index[i]]++;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (i == idx) continue;
      if (superior[i] < 3) {
        return false;
      }
    }
    return true;
  };

  sort(r.begin(), r.end(), [&](auto& r1, auto& r2) {
    int b = 0;
    for (int j = 0; j < 5; ++j) {
      if (r1[j] < r2[j]) {
        b--;
      } else {
        b++;
      }
    }
    return b < 0;
  });

  if (is_gold_medal(0)) {
    cout << r[0][5]+1 << endl;
    return;
  }

  cout << "-1" << endl;
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
