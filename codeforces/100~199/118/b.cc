#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  auto print_row = [&](int r) -> void {
    int space = (n - r) * 2;
    cout << string(space, ' ');
    cout << "0";
    for (int j = 1; j <= r; ++j) {
      cout << " " << j;
    }
    for (int j = r-1; j >= 0; --j) {
      cout << " " << j;
    }
  };

  for (int i = 0; i <= n; ++i) {
    print_row(i);
    cout << endl;
  }
  for (int i = n-1; i >= 0; --i) {
    print_row(i);
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
