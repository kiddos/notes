#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int total = 0;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum >= 2) {
      total++;
    }
  }
  cout << total << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
