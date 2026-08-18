#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 compute_moves(string a, string b) {
  vector<int> indices1, indices2;
  int len = a.length();
  for (int i = 0; i < len; ++i) {
    if (a[i] == '1') {
      indices1.push_back(i);
    }
    if (b[i] == '1') {
      indices2.push_back(i);
    }
  }
  if (indices1.size() != indices2.size()) {
    return -1;
  }

  int size = indices1.size();
  i64 ans = 0;
  for (int i = 0; i < size; ++i) {
    ans += abs(indices1[i] - indices2[i]);
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<string> c(2), d(2);
  for (int i = 0; i < n; ++i) {
    int p = i%2;
    c[p].push_back(a[i]);
    d[p].push_back(b[i]);
  }
  i64 ans = 0;
  for (int p = 0; p < 2; ++p) {
    i64 result = compute_moves(c[p], d[p]);
    if (result < 0) {
      cout << "-1" << endl;
      return;
    }
    ans += result;
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
