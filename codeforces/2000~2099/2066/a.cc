#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(const string& ans) {
  cout << "! " << ans << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }

  vector<int> found(n+1);
  for (int i = 1; i <= n; ++i) {
    found[x[i]] = 1;
  }
  int total_found = accumulate(found.begin(), found.end(), 0);
  if (total_found == n) {
    int start = 0, end = 0;
    for (int i = 1; i <= n; ++i) {
      if (x[i] == 1) {
        start = i;
      }
      if (x[i] == n) {
        end = i;
      }
    }
    int result1 = query(start, end);
    int result2 = query(end, start);
    if (result1 == result2) {
      if (result1 < n-1) {
        answer("A");
      } else {
        answer("B");
      }
    } else {
      answer("A");
    }
  } else {
    int start = 0;
    for (int i = 1; i <= n; ++i) {
      if (!found[i]) {
        start = i;
      }
    }
    int end = 0;
    for (int i = 1; i <= n; ++i) {
      if (i != start) {
        end = i;
      }
    }

    int result = query(start, end);
    if (result == 0) {
      answer("A");
    } else {
      answer("B");
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
