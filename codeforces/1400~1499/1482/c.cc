#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> f(m);
  for (int i = 0; i < m; ++i) {
    int k = 0;
    cin >> k;
    f[i] = vector<int>(k);
    for (int j = 0; j < k; ++j) {
      cin >> f[i][j];
    }
  }

  vector<int> played(n+1);
  vector<int> assigned(m);
  mt19937 gen;
  for (int i = 0; i < m; ++i) {
    vector<int>& a = f[i];
    uniform_int_distribution<int> dist(0, a.size()-1);
    int idx = dist(gen);
    int selected = a[idx];
    played[selected]++;
    assigned[i] = selected;
  }

  int can_assign = (m+1) / 2;
  int target_friend = 0;
  for (int fi = 1; fi <= n; ++fi) {
    if (played[fi] > can_assign) {
      target_friend = fi;
      break;
    }
  }

  if (target_friend) {
    int count = played[target_friend];
    for (int i = 0; i < m && count > can_assign; ++i) {
      if (assigned[i] == target_friend) {
        // find other friend to play with
        for (int fi : f[i]) {
          if (fi != target_friend) {
            assigned[i] = fi;
            count--;
            break;
          }
        }
      }
    }

    if (count > can_assign) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < m; ++i) {
    cout << assigned[i] << " ";
  }
  cout << endl;
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
