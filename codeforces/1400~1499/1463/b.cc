#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool good(vector<int>& a, vector<int>& b) {
  i64 diff_sum = 0;
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    diff_sum += abs(b[i] - a[i]);
  }
  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  return diff_sum * 2 <= sum;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b1 = a, b2 = a;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      b1[i] = 1;
    } else {
      b2[i] = 1;
    }
  }

  vector<int> b(n);
  if (good(a, b2)) {
    b = b2;
  } else {
    b = b1;
  }

  for (int i = 0; i < n; ++i) {
    cout << b[i] << " ";
  }
  cout << endl;

  // assert(diff_sum * 2 <= sum);
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
