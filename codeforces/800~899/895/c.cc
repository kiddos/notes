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

  int max_a = *max_element(a.begin(), a.end());
  vector<int> count(max_a+1);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
  int size = primes.size();
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
