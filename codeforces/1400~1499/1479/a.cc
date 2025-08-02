#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 100000;
vector<int> a(MAX_N+1);

int query_single(int i) {
  if (a[i]) {
    return a[i];
  }

  cout << "? " << i << endl;
  cin >> a[i];
  return a[i];
}

array<int,3> query(int i, int n) {
  array<int,3> result;
  result[1] = query_single(i);
  if (i+1 <= n) {
    result[2] = query_single(i+1);
  } else {
    result[2] = numeric_limits<int>::max();
  }
  if (i-1 >= 1) {
    result[0] = query_single(i-1);
  } else {
    result[0] = numeric_limits<int>::max();
  }
  return result;
}

void answer(int idx) {
  cout << "! " << idx << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  int l = 1, r = n;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    auto result = query(mid, n);
    if (result[1] < result[0] && result[1] < result[2]) {
      answer(mid);
      return;
    } else if (result[0] >= result[1] && result[1] >= result[2]) {
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
