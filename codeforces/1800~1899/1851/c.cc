#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) cin >> c[i];

  int start_count = 0;
  int start_index = 0;
  for (int i = 1; i <= n; ++i) {
    start_count += (c[i] == c[1]);
    if (start_count == k) {
      start_index = i;
      break;
    }
  }

  if (start_index == 0) {
    cout << "NO" << endl;
    return;
  }

  if (c.back() == c[1]) {
    cout << "YES" << endl;
    return;
  }

  int end_count = 0;
  int end_index = n+1;
  for (int i = n; i >= 1; --i) {
    end_count += c[i] == c.back();
    if (end_count == k) {
      end_index = i;
      break;
    }
  }

  if (end_index > n) {
    cout << "NO" << endl;
    return;
  }

  if (end_index > start_index) {
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
