#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void swap1(vector<int>& p, int n) {
  for (int i = 0; i < n*2; i += 2) {
    swap(p[i], p[i+1]);
  }
}

void swap2(vector<int>& p, int n) {
  for (int i = 0; i < n; ++i) {
    swap(p[i], p[i+n]);
  }
}

bool is_valid(vector<int>& p, int n) {
  for (int i = 0; i < n*2; ++i) {
    if (p[i] != i+1) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p0(n * 2);
  for (int i = 0; i < n * 2; ++i) {
    cin >> p0[i];
  }

  int ans = numeric_limits<int>::max();
  vector<int> p = p0;
  int ans1 = 0;
  for (int i = 0; i < n * 2 && p[0] != 1; ++i) {
    if (i % 2 == 0) {
      swap1(p, n);
    } else {
      swap2(p, n);
    }
    ans1++;
  }
  if (is_valid(p, n)) {
    ans = min(ans, ans1);
  }

  int ans2 = 0;
  p = p0;
  for (int i = 0; i < n * 2 && p[0] != 1; ++i) {
    if (i % 2 == 0) {
      swap2(p, n);
    } else {
      swap1(p, n);
    }
    ans2++;
  }
  if (is_valid(p, n)) {
    ans = min(ans, ans2);
  }

  if (ans == numeric_limits<int>::max()) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
