#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> even, odd;
  if (n == 3) {
    cout << "2 1 3" << endl;
  } else if (n == 4) {
    cout << "2 0 3 1" << endl;
  } else if (n == 5) {
    cout << "2 4 3 5 0" << endl;
  } else {
    if ((n / 2) % 2 == 1) {
      odd = {2, 3, 4};
      even = {1, 8, 12};
      int k = 14;
      for (int i = 6; i+4 <= n; i += 4) {
        odd.push_back(k++);
        odd.push_back(k++);
        even.push_back(k++);
        even.push_back(k++);
      }
    } else {
      int k = 2;
      for (int i = 0; i+4 <= n; i += 4) {
        odd.push_back(k++);
        odd.push_back(k++);
        even.push_back(k++);
        even.push_back(k++);
      }
    }
    
    if (n % 2 == 1) {
      odd.push_back(0);
    }
    for (int i = 0, o = 0, e = 0; i < n; ++i) {
      if (i % 2 == 0) cout << odd[o++];
      else cout << even[e++];
      cout << " ";
    }
    cout << endl;
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
