#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> fib = {0, 1, 1};

  if (n == 0) {
    cout << "0 0 0" << endl;
    return;
  }
  if (n == 1) {
    cout << "0 0 1" << endl;
    return;
  }
  if (n == 2) {
    cout << "0 1 1" << endl;
    return;
  }

  while (fib.back() < n) {
    int size = fib.size();
    fib.push_back(fib[size-1] + fib[size-2]);
  }
  int size = fib.size();
  cout << fib[size-5] << " " << fib[size-4] << " " << fib[size-2] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
