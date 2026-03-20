#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int max_val = *max_element(b.begin(), b.end());
  int min_val = *min_element(b.begin(), b.end());
  i64 max_count = 0, min_count = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] == max_val) {
      max_count++;
    }
    if (b[i] == min_val) {
      min_count++;
    }
  }

  i64 ans1 = max_val - min_val, ans2 = 0;
  if (max_val == min_val) {
    ans2 = max_count * (min_count-1) / 2;
  } else {
    ans2 = max_count * min_count;
  }
  cout << ans1 << " " << ans2 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
