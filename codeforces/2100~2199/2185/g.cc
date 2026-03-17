#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a;
  for (int i = 0; i < n; ++i) {
    int l = 0;
    cin >> l;
    vector<int> ai(l);
    for (int j = 0; j < l; ++j) {
      cin >> ai[j];
    }
    a.push_back(ai);
  }

  vector<i64> mexs(n);
  vector<i64> next_mexs(n);
  for (int i = 0; i < n; ++i) {
    int l = a[i].size();
    int max_mex = l+2;
    vector<bool> found(max_mex+1);
    for (int j = 0; j < l; ++j) {
      if (a[i][j] >= 0 && a[i][j] <= max_mex) {
        found[a[i][j]] = true;
      }
    }
    int missing = 0;
    for (int k = 0; k <= max_mex; ++k) {
      if (!found[k]) {
        if (missing == 0) {
          mexs[i] = k;
        } else if (missing == 1) {
          next_mexs[i] = k;
        }
        missing++;
      }
    }
  }

  map<int,i64> changes;
  for (int i = 0; i < n; ++i) {
    changes[mexs[i]] += next_mexs[i] - mexs[i];
  }

  i64 total_mex = accumulate(mexs.begin(), mexs.end(), 0LL);
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = a[i].size();
    set<int> s;
    for (int k = 0; k <= l+1; ++k) {
      s.insert(k);
    }
    map<int,int> count;
    for (int j = 0; j < l; ++j) {
      count[a[i][j]]++;
      s.erase(a[i][j]);
    }

    for (int j = 0; j < l; ++j) {
      // compute current mex
      count[a[i][j]]--;
      if (count[a[i][j]] == 0) {
        s.insert(a[i][j]);
      }

      i64 current_mex = *s.begin();
      count[a[i][j]]++;
      s.erase(a[i][j]);

      // if ak is not changed, its contribution is original mexs[k] * (n-2)
      // if mexs[k] is inserted into ak, its mex will change to next_mexs[k]
      // else it remains the same as mexs[k]
      // so total should be mexs[k] * (n-1) + changes

      i64 excluded = total_mex - mexs[i];
      i64 change = changes.count(a[i][j]) ? changes[a[i][j]] : 0;
      i64 total = excluded * (n-1) + change + current_mex * (n-1);
      ans += total;
    }
  }
  cout << ans << endl;
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
