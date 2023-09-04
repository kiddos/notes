#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, d = 0;
  cin >> n >> m >> d;

  vector<int> s(m);
  for (int i = 0; i < m; ++i) cin >> s[i];

  s.insert(s.begin(), 1);

  vector<int> p = {1};
  for (int i = 1; i < s.size(); ++i) {
    int diff = s[i] - s[i-1];
    int eat = (diff + d - 1) / d;
    p.push_back(p.back() + eat);
  }

  if (s.back() != n) {
    p.push_back(p.back() + (n - s.back()) / d);
  } else {
    p.push_back(p.back());
  }

  int size = s.size();
  // cout << "p=";
  // for (int i = 0; i < p.size(); ++i) cout << p[i] << " ";
  // cout << endl;

  int min_val = numeric_limits<int>::max();
  int amount = 0;
  // try to remove i seller
  for (int i = 1; i < size; ++i) {
    int result = 0;
    if (i == size-1) {
      int diff = n - s[i-1];
      int eat = diff / d;
      result = p[i-1] + eat;
    } else {
      int end = s[i+1];
      int diff = end - s[i-1];
      int eat = (diff + d - 1) / d;
      result = p[i-1] + p.back() - p[i+1] + eat;
    }

    // cout << "remove=" << i << " , result=" << result << endl;
    if (result < min_val) {
      min_val = result;
      amount = 1;
    } else if (result == min_val) {
      amount++;
    }
  }

  cout << min_val << " " << amount << endl;
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
