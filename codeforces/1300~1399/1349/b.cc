#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


bool all_k(vector<int>& a, int n, int k) {
  for (int i = 1; i <= n; ++i) {
    if (a[i] != k) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n = 0, k =0;
  cin >> n >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  bool found_k = false;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == k) {
      found_k = true;
      break;
    }
  }

  if (!found_k) {
    cout << "no" << endl;
    return;
  }

  if (all_k(a, n, k)) {
    cout << "yes" << endl;
    return;
  }

  for (int i = 1; i <= n; ++i) {
    int greater = 0;
    for (int j = i; j <= n && j-i <= 2; ++j) {
      if (a[j] >= k) {
        greater++;
      }
    }
    if (greater >= 2) {
      cout << "yes" << endl;
      return;
    }
  }
  cout << "no" << endl;
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
