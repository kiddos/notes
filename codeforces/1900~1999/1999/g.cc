#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int area = 0;
  cin >> area;
  return area;
}

void answer(int x) {
  cout << "! " << x << endl;
}

void solve() {
  int l = 2, r = 999;
  while (l <= r) {
    int dist = r - l;
    if (dist == 0) {
      answer(l);
      return;
    } else if (dist == 1) {
      int area = query(l, r);
      if (area == (l+1) * (r+1)) {
        answer(l);
        return;
      } else {
        answer(r);
        return;
      }
    } else if (dist == 2) {
      int l2 = l + 1;
      int area = query(l2, r);
      if (area == (l2+1) * (r+1)) {
        r = l2;
      } else if (area == l2 * (r+1)) {
        answer(r);
        return;
      } else {
        // this should not happen
      }
    } else {
      int a = l + dist / 3;
      int b = r - dist / 3;
      int area = query(a, b);
      if (area == a * b) {
        // both a and b is correct
        // answer should lie in b+1~r
        l = b+1;
      } else if (area == a * (b+1)) {
        // a is correct b is incorrect
        // answer should lie in a+1~b
        l = a+1;
        r = b;
      } else {
        // both and b are incorrect
        // answer should be in l~a
        r = a;
      }
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
