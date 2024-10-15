#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int largest = max_element(a.begin(), a.end()) - a.begin();
  int l = largest - 1, r = largest + 1;
  int current = a[largest];
  while (l >= 0 || r < n) {
    int left = l >= 0 ? a[l] : 0;
    int right = r < n ? a[r] : 0;
    if (left > right) {
      if (left >= current) {
        cout << "NO" << endl;
        return;
      }
      current = min(current, left);
      l--;
    } else {
      if (right >= current) {
        cout << "NO" << endl;
        return;
      }
      current = min(current, right);
      r++;
    }
  }
  if (l >= 0 || r < n) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
