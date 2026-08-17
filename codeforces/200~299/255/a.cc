#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> total(3);
  for (int i = 0; i < n; ++i) {
    total[i%3] += a[i];
  }
  int max_index = max_element(total.begin(), total.end()) - total.begin();
  vector<string> exercise = {"chest", "biceps", "back"};
  string ans = exercise[max_index];
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
