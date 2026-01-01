#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> ops(n);
  for (int i = 0; i < n; ++i) {
    cin >> ops[i];
  }
  int x = 0;
  for (int i = 0; i < n; ++i) {
    if (ops[i] == "++X" || ops[i] == "X++") {
      x++;
    } else if (ops[i] == "--X" || ops[i] == "X--") {
      x--;
    }
  }
  cout << x << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
