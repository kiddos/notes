#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int one = find(a.begin(), a.end(), 1) - a.begin();
  int two = find(a.begin(), a.end(), 2) - a.begin();
  int largest = find(a.begin(), a.end(), n) - a.begin();

  int left = min(one, two);
  int right = max(one, two);
  if (largest > left && largest < right) {
    cout << one << " " << one << endl;
  } else if (largest < left) {
    cout << largest << " " << left << endl;
  } else if (largest > right) {
    cout << largest << " " << right << endl;
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
