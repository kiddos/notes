#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int q = 0;
  cin >> q;
  deque<i64> d;
  i64 p = 0;
  i64 r1 = 0, r2 = 0;
  int back = 0;
  for (int i = 0; i < q; ++i) {
    int s = 0;
    cin >> s;
    if (s == 1) {
      if (back) {
        i64 first = d.front();
        d.push_back(first);
        d.pop_front();
        r2 -= first * d.size();
        r2 += p;
        r1 += first * d.size();
        r1 -= p;
      } else {
        i64 last = d.back();
        d.push_front(last);
        d.pop_back();
        r1 -= last * d.size();
        r1 += p;
        r2 += last * d.size();
        r2 -= p;
      }
    } else if (s == 2) {
      back ^= 1;
    } else if (s == 3) {
      i64 k = 0;
      cin >> k;
      if (back) {
        d.push_front(k);
        r1 += p + k;
        p += k;
        r2 += k * d.size();
      } else {
        d.push_back(k);
        r1 += k * d.size();
        r2 += p + k;
        p += k;
      }
    }

    // for (int x : d) {
    //   cout << x << " ";
    // }
    // cout << endl;
    // cout << "r1=" << r1 << ",r2=" << r2 << endl;
    if (back) {
      cout << r2 << endl;
    } else {
      cout << r1 << endl;
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
