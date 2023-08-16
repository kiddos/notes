#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int middle = n / 3;
  int first = middle + 1;
  int last = middle-1;
  if (n % 3 == 1) {
    first++;
  }
  if (n % 3 == 2) {
    first++;
    middle++;
  }

  cout << middle << " " << first << " " << last << endl;
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
