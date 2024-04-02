#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n ; ++i) cin >> a[i];

  int min_val = *min_element(a.begin(), a.end());
  if (min_val != 0) {
    cout << n << endl;
    for (int i = 1; i <= n; ++i) {
      cout << i << " " << i << endl;
    }
  } else {
    set<int> s0;
    for (int i = 0; i <= n; ++i) {
      s0.insert(i);
    }
    set<int> s = s0;
    for (int i = 0; i < n; ++i) {
      s.erase(a[i]);
    }
    int mex = *s.begin();

    set<int> s1 = s0;
    set<int> s2 = s0;
    int mid = 0;
    for (int i = 0; i < n; ++i) {
      s1.erase(a[i]);
      if (*s1.begin() == mex) {
        mid = i+1;
        for (int j = i+1; j < n; ++j) {
          s2.erase(a[j]);
        }
        break;
      }
    }

    int mex1 = *s1.begin();
    int mex2 = *s2.begin();
    if (mex1 != mex2) {
      cout << "-1" << endl;
    } else {
      cout << "2" << endl;
      cout << "1 " << mid << endl;
      cout << mid+1 << " " << n << endl;
    }
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
