#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    if (i > 1) {
      cout << "that ";
    }

    if (i % 2 == 1) {
      cout << "I hate ";
    } else {
      cout << "I love ";
    }
  }
  cout << "it";
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
