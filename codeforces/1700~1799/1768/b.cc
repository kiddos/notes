#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a, int k) {
  int n = a.size();
  int j = 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == j) {
      j++;
    }
  }
  int len = j-1;
  int ops = (n-len + k -1) / k;
  cout << ops << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    solve(a, k);
  }
  return 0;
}
