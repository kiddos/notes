#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  int total = a + b;

  set<int> ans;
  if (max(a, b) == total) {
    ans.insert((total + 1) / 2);
    ans.insert(total / 2);
  } else {
    if (total % 2 == 0) {
      for (int i = min(a, b), br = abs(a - b) / 2; i >= 0; --i, br += 2) {
        ans.insert(br);
      }
    } else {
      for (int i = min(a, b), br = abs(a - b) / 2; i >= 0; --i, br += 2) {
        ans.insert(br);
      }
      for (int i = min(a, b), br = (abs(a - b)+1) / 2; i >= 0; --i, br += 2) {
        ans.insert(br);
      }
    }
  }

  cout << ans.size() << endl;
  for (int g : ans) {
    cout << g << " ";
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
