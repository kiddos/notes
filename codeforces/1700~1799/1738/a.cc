#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<int> arr1, arr2;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) arr1.push_back(b[i]);
    else arr2.push_back(b[i]);
  }

  ll ans = 0;
  if (arr1.size() == arr2.size()) {
    sort(arr1.rbegin(), arr1.rend());
    sort(arr2.rbegin(), arr2.rend());
    if (arr1.back() <= arr2.back()) {
      ans += arr1.back();
      arr1.pop_back();
    } else {
      ans += arr2.back();
      arr2.pop_back();
    }
    for (int c : arr1) ans += c * 2;
    for (int c : arr2) ans += c * 2;
    cout << ans << endl;
    return;
  }

  if (arr2.size() > arr1.size()) swap(arr2, arr1);
  sort(arr1.rbegin(), arr1.rend());

  while (arr1.size() > arr2.size()) {
    ans += arr1.back();
    arr1.pop_back();
  }
  while (!arr1.empty()) {
    ans += arr1.back() * 2;
    arr1.pop_back();
  }
  while (!arr2.empty()) {
    ans += arr2.back() * 2;
    arr2.pop_back();
  }
  cout << ans << endl;
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
