#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Candidate {
  i64 diff;
  int idx;
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  int size = n + m + 1;
  vector<i64> a(size);
  for (int i = 0; i < size; ++i) cin >> a[i];
  vector<i64> b(size);
  for (int i = 0; i < size; ++i) cin >> b[i];

  int programmers = 0, testers = 0;
  for (int i = 0; i < size; ++i) {
    if (a[i] > b[i]) {
      programmers++;
    } else {
      testers++;
    }
  }

  if (testers > m) {
    swap(programmers, testers);
    swap(n, m);
    swap(a, b);
  }

  vector<i64> ans(size);
  auto assign = [&](vector<bool>& f, int x) -> i64 {
    if (x == 0) {
      return accumulate(b.begin(), b.end(), 0);
    }
    int count = 0;
    for (int i = 0; i < size; ++i) {
      if (a[i] > b[i]) {
        f[i] = true;
        count++;
      }
      if (count == x) {
        break;
      }
    }
    i64 sum = 0;
    for (int i = 0; i < size; ++i) {
      if (f[i]) {
        sum += a[i];
      } else {
        sum += b[i];
      }
    }
    return sum;
  };

  vector<bool> flag1(size), flag0(size);
  i64 sum1 = assign(flag1, n+1);
  i64 sum0 = assign(flag0, n);
  for (int i = 0; i < size; ++i) {
    // try to assign n+1 programmer, and this guy should be programmer
    if (flag1[i]) {
      ans[i] = sum1 - a[i];
    } else {
      // only assign n programmers, and this guy should be tester
      ans[i] = sum0 - b[i];
    }
  }

  for (int i = 0; i < size; ++i) {
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
