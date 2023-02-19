#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a) {
  int n = a.size();
  int target = n-2;
  function<void(int,int)> quick_select = [&](int l, int r) {
    if (l >= r) return;
    int pivot = a[r];
    int j = l;
    for (int i = l; i < r; ++i) {
      if (a[i] <= pivot) {
        swap(a[i], a[j++]);
      }
    }
    swap(a[r], a[j]);

    if (j == target) return;
    if (j < target) {
      quick_select(j+1, r);
    } else {
      quick_select(l, j-1);
    }
  };

  quick_select(0, n-1);
  return a[n-2] + a[n-1];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = solve(a);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
