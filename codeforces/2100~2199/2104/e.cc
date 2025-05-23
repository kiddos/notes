#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  int q = 0;
  cin >> q;
  vector<string> queries(q);
  for (int i = 0; i < q; ++i) {
    cin >> queries[i];
  }

  vector<vector<int>> next(n+1, vector<int>(k, n));
  for (int i = 0; i < n; ++i) {
    int c = s[i]-'a';
    next[i][c] = i;
  }
  for (int i = n-1; i >= 0; --i) {
    for (int c = 0; c < k; ++c) {
      next[i][c] = min(next[i][c], next[i+1][c]);
    }
  }
  vector<int> completed_set(n+1);
  set<char> found;
  for (int i = n-1; i >= 0; --i) {
    found.insert(s[i]);
    if ((int)found.size() == k) {
      completed_set[i]++;
      found.clear();
    }
  }
  for (int i = n-1; i >= 0; --i) {
    completed_set[i] += completed_set[i+1];
  }

  auto process_query = [&](string& t) -> int {
    int idx = 0;
    for (int i = 0; i < (int)t.length(); ++i) {
      int c = t[i]-'a';
      int j = next[idx][c];
      if (j >= n) {
        // already unpleasant
        return 0;
      }
      idx = j+1;
    }
    return completed_set[idx]+1;
  };

  for (int i = 0; i < q; ++i) {
    int result = process_query(queries[i]);
    cout << result << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
