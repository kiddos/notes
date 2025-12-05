#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

enum Result {
  TIE, AJISAI, MAI,
};

Result compute_result(vector<int>& a, vector<int>& b) {
  int n = a.size();
  int last = -1;
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      last = i;
    }
    x ^= a[i];
    y ^= b[i];
  }
  if (last == -1) {
    return TIE;
  }
  if (last % 2 == 0) {
    // Ajisai last move
    if (x == y) {
      return TIE;
    } else {
      return AJISAI;
    }
  } else {
    // Mai last move
    if (x == y) {
      return TIE;
    } else {
      return MAI;
    }
  }
}


void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  for (int bit = 30; bit >= 0; --bit) {
    int mask = 1<<bit;
    vector<int> current_a(n), current_b(n);
    for (int i = 0; i < n; ++i) {
      if (mask & a[i]) {
        current_a[i] = 1;
      }
      if (mask & b[i]) {
        current_b[i] = 1;
      }
    }

    Result result = compute_result(current_a, current_b);
    if (result == AJISAI) {
      cout << "Ajisai" << endl;
      return;
    } else if (result == MAI) {
      cout << "Mai" << endl;
      return;
    } else {
      if (bit == 0) {
        cout << "Tie" << endl;
      }
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
