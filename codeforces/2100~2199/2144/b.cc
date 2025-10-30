#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<bool> found(n+1);
  for (int i = 1; i <= n; ++i) {
    if (a[i] > 0) {
      found[a[i]] = true;
    }
  }
  vector<int> s;
  for (int i = 1; i <= n; ++i) {
    if (!found[i]) {
      s.push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!a[i]) {
      a[i] = s.back();
      s.pop_back();
    }
  }

  int left = -1, right = -1;
  for (int i = 1; i <= n; ++i) {
    if (a[i] != i) {
      if (left < 0) {
        left = i;
      }
      right = i;
    }
  }

  if (left < 0 && right < 0) {
    cout << "0" << endl;
  } else {
    int len = right - left + 1;
    cout << len << endl;
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
