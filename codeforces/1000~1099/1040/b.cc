#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 2 * k + 1

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int m = 2 * k + 1;
  if (n <= m) {
    cout << "1" << endl;
    cout << (n+1)/2 << endl;
    return;
  }

  int side = k+1;
  int min_side = side * 2;
  int current = n;
  int middle = 0;
  while (current - m >= min_side) {
    current -= m;
    middle++;
  }
  int total = middle + 2;
  int offset = min(k, current - min_side);
  int p = 1 + offset;
  vector<int> ans;
  for (int i = 0; i < total; ++i) {
    ans.push_back(p);
    p += 2 * k + 1;
  }
  cout << ans.size() << endl;
  for (int pos : ans) {
    cout << pos << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
