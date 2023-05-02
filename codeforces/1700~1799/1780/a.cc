#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a) {
  int n = a.size();

  vector<int> even, odd;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 1) odd.push_back(i+1);
    else even.push_back(i+1);
  }

  if (even.size() >= 2 && odd.size() >= 1) {
    cout << "YES" << endl;
    cout << even[0] << " " << even[1] << " " << odd[0] << endl;
  } else if (odd.size() >= 3) {
    cout << "YES" << endl;
    cout << odd[0] << " " << odd[1] << " " << odd[2] << endl;
  } else cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    solve(a);
  }
  return 0;
}
