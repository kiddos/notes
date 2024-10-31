#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int subarray = 0;
  int i = 1;
  while (i <= n) {
    if (a[i] == i) {
      i++;
      continue;
    }

    int j = i;
    while (j+1 <= n && a[j+1] != j+1) {
      j++;
    }
    subarray++;
    i = j+1;
  }

  if (subarray == 0) {
    cout << "0" << endl;
  } else if (subarray == 1) {
    cout << "1" << endl;
  } else {
    cout << "2" << endl;
  }
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
