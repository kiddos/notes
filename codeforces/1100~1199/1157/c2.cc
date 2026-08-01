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

  string ans;
  int current = 0;

  auto choose_side = [&](int l, int r) -> void {
    int left = 0;
    int c = current;
    for (int i = l; i <= r; ++i) {
      if (a[i] > c) {
        c = a[i];
        left++;
      } else {
        break;
      }
    }
    c = current;
    int right = 0;
    for (int i = r; i >= l; --i) {
      if (a[i] > c) {
        c = a[i];
        right++;
      } else {
        break;
      }
    }

    if (left >= right) {
      ans += string(left, 'L');
    } else {
      ans += string(right, 'R');
    }
  };

  int l = 0, r = n-1;
  while (l <= r) {
    if (l == r) {
      if (a[l] > current) {
        current = a[l++];
        ans.push_back('L');
      } else {
        break;
      }
    } else {
      if (a[l] > current && a[r] > current) {
        if (a[l] < a[r]) {
          current = a[l++];
          ans.push_back('L');
        } else if (a[r] < a[l]) {
          current = a[r--];
          ans.push_back('R');
        } else {
          choose_side(l, r);
          break;
        }
      } else if (a[l] > current) {
        current = a[l++];
        ans.push_back('L');
      } else if (a[r] > current) {
        current = a[r--];
        ans.push_back('R');
      } else {
        break;
      }
    }
  }

  cout << ans.length() << endl;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
