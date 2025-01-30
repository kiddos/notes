#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  multiset<int> s1(a.begin(), a.end());
  multiset<int> s2(b.begin(), b.end());

  while (s2.size() < s1.size() && s2.size() > 0) {
    int largest = *s2.rbegin();
    if (largest == *s1.rbegin()) {
      // remove largest
      s2.erase(prev(s2.end()));
      s1.erase(prev(s1.end()));
    } else {
      // largest b must be some a[i] + a[j] and abs(a[i] - a[j]) <= 1
      // so if b is even a[i] == a[j]
      // if b is odd a[i] == a[j]+1
      if (largest % 2 == 0) {
        int half = largest / 2;
        s2.erase(prev(s2.end()));
        s2.insert(half);
        s2.insert(half);
      } else {
        int half = largest / 2;
        s2.erase(prev(s2.end()));
        s2.insert(half);
        s2.insert(half+1);
      }
    }
  }

  if (s1 == s2) {
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
