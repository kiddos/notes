#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;

  int sum = a * 3;
  int rest = sum - b;
  int first = b;
  while (rest - first < b) {
    first--;
  }
  int last = rest - first;
  cout << "3" << endl;
  cout << first << " " << b << " " << last << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
