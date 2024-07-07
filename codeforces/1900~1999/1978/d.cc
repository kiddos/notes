#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 c = 0;
  cin >> n >> c;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<i64> b = a;
  b[0] += c;
  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + b[i]);
  }

  int max_index = max_element(b.begin(), b.end()) - b.begin();
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (i == max_index) {
      ans[i] = 0;
    } else {
      // have to remove all the candidates before i
      // so that the votes goes here
      i64 votes = p[i] + b[i];
      if (votes >= b[max_index]) {
        ans[i] = i;
      } else {
        // remove the max_element
        ans[i] = i+1;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
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
