#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// ai'  = ai ^ aj                         all = aj
// aj'  = aj ^ ai' = aj ^ ai ^ aj = ai    all = aj ^ ai ^ aj = ai
// ai'' = ai' ^ aj' = ai ^ aj ^ ai = aj   all = ai ^ ai = 0
//
// 1 2 4 8    i = 0
// 1 3 5 9    i = 3
// 8 10 12 9  i = 0
// 8 2 4 1
// => can swap any index i, j without affecting other number
// => ordering doesn't matter
//
// after 1 operation
// aj' = aj ^ ai
// ai = ai
// ak = ak ^ ai
//
// after 2 operation
// ai' = ai ^ aj' = ai ^ aj ^ ai = aj
// aj = aj ^ ai
// ak = ak ^ ai ^ aj' = ak ^ aj
//
// seems like only the last operation matter


void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (a == b) {
    cout << "YES" << endl;
    return;
  }

  int xa = 0, xb = 0;
  for (int i = 0; i < n; ++i) {
    xa ^= a[i];
    xb ^= b[i];
  }

  int ai = xb ^ xa;
  int found = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == ai) {
      found = i;
      break;
    }
  }

  if (found < 0) {
    cout << "NO" << endl;
    return;
  }

  vector<int> a2 = a;
  for (int i = 0; i < n; ++i) {
    if (i != found) {
      a2[i] ^= a[found];
    }
  }
  sort(a2.begin(), a2.end());

  if (a2 == b) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
