#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 1.circle
// 2. isosceles triangle
// 3. square
// 1 -> 1 Infinite
// 1 -> 2 +3
// 1 -> 3 +4
// 2 -> 1 +3
// 2 -> 2 Infinite
// 2 -> 3 Infinite
// 3 -> 1 +4
// 3 -> 2 Infinite
// 3 -> 3 Infinite
// 3 -> 1 -> 2 -1

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<pair<int,int>, int> intersect = {
    {{1, 2}, 3},
    {{1, 3}, 4},
    {{2, 1}, 3},
    {{3, 1}, 4},
  };
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    pair<int,int> p = {a[i-1], a[i]};
    if (intersect.count(p)) {
      ans += intersect[p];
    } else {
      cout << "Infinite" << endl;
      return;
    }
  }

  for (int i = 2; i < n; ++i) {
    if(a[i-2] == 3 && a[i-1] == 1 && a[i] == 2) {
      ans--;
    }
  }

  cout << "Finite" << endl;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
