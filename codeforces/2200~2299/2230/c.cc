#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  i64 can_pair = 0;
  i64 pair_count = 0;
  i64 single = 0;
  for (int i = 0; i < n; ++i) {
    if (c[i] >= 2) {
      can_pair += c[i];
      pair_count++;
    } else {
      single++;
    }
  }

  if (pair_count == 0) {
    cout << "0" << endl;
  } else if (pair_count == 1) {
    i64 take_single = min(can_pair / 2, single);
    i64 total = can_pair + take_single;
    if (total >= 3) {
      cout << total << endl;
    } else {
      cout << "0" << endl;
    }
  } else {
    i64 take_single = 0;
    for (int i = 0; i < n; ++i) {
      if (c[i] >= 4) {
        take_single += c[i] / 2 - 1;
      }
    }
    take_single = min(take_single, single);
    i64 total = can_pair + take_single;
    if (total >= 3) {
      cout << total << endl;
    } else {
      cout << "0" << endl;
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
