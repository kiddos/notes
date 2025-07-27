#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(int index) {
  cout << "! " << index << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  int index = query(1, n);

  int ans = 0;
  if (index == 1) {
    // second largest is 1
    // so largest is in [2, n]
    int l = 2, r = n;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int result = query(1, mid);
      if (result == 1) {
        ans = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
  } else if (index == n) {
    // second largest is n
    // so largest is in [1, n-1]
    int l = 1, r = n-1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int result = query(mid, n);
      if (result == n) {
        ans = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
  } else {
    int prefix_result = query(1, index);
    if (prefix_result == index) {
      // largest is in [1, index-1]
      int l = 1, r = index-1;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        int result = query(mid, index);
        if (result == index) {
          ans = mid;
          l = mid+1;
        } else {
          r = mid-1;
        }
      }
    } else {
      // largest is in [index+1, n]
      int l = index+1, r = n;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        int result = query(index, mid);
        if (result == index) {
          ans = mid;
          r = mid-1;
        } else {
          l = mid+1;
        }
      }
    }
  }
  answer(ans);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
