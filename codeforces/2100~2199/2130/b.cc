#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, s = 0;
  cin >> n >> s; 
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int sum = accumulate(a.begin(), a.end(), 0);
  if (sum > s) {
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;
  } else if (sum == s) {
    cout << "-1" << endl;
  } else {
    // the question guarantee there is at least 1 of 0, 1, 2
    int left = s - sum;
    // if the left over is 1
    // we can do 0,0,0,0,2,2,2,1,1,, ...
    // for 2, one of these have to exists: 0,2 or 0,1, which can create 2
    // for 3, one of these have to exists: 1,0 or 1,2, which can create 3
    // for 4 and above, if we can create 2, and 3, all other numbers can be created
    if (left == 1) {
      vector<int> count(3);
      for (int i = 0; i < n; ++i) {
        count[a[i]]++;
      }
      for (int c = 0; c < count[0]; ++c) {
        cout << "0 ";
      }
      for (int c = 0; c < count[2]; ++c) {
        cout << "2 ";
      }
      for (int c = 0; c < count[1]; ++c) {
        cout << "1 ";
      }
      cout << endl;
    } else {
      cout << "-1" << endl;
    }
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
