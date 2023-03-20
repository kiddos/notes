#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, w = 0, h = 0;
  cin >> n >> w >> h;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int align_left = numeric_limits<int>::min(), align_right = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    int choco_left = b[i] - h, choco_right = b[i] + h;
    int cake_left = a[i] - w, cake_right = a[i] + w;

    int move_left = cake_left - choco_left;
    // cout << "need to move left: " << move_left << endl;
    align_left = max(align_left, move_left);
    int move_right = cake_right - choco_right;
    // cout << "need to move right: " << move_right << endl;
    align_right = min(align_right, move_right);
  }
  // cout << align_left << " " << align_right << endl;

  bool ok = align_left <= align_right;
  if (ok) {
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
