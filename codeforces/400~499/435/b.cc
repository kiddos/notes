#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a;
  int k = 0;
  cin >> a >> k;

  int n = a.length();
  for (int i = 0; i < n; ++i) {
    int largest = i;
    for (int j = 1; j <= k && i+j < n; ++j) {
      if (a[i+j] > a[largest]) {
        largest = i+j;
      }
    }
    int swaps = largest - i;
    for (int j = largest; j > i; --j) {
      swap(a[j-1], a[j]);
    }
    k -= swaps;
  }

  cout << a << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
