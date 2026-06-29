#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int max_a = *max_element(a.begin(), a.end());
  vector<int> count(max_a+1);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  for (int i = 1; i <= max_a; ++i) {
    if (count[i] >= 2) {
      cout << "0" << endl;
      return;
    }
  }

  for (int i = 1; i <= max_a; ++i) {
    if (count[i] > 0 && (i & x) != i && count[i & x] > 0) {
      cout << "1" << endl;
      return;
    }
  }

  vector<int> new_val(max_a+1);
  for (int i = 1; i <= max_a; ++i) {
    if (count[i] > 0) {
      if (new_val[i&x]) {
        cout << "2" << endl;
        return;
      }
      new_val[i&x]++;
    }
  }

  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
