#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(array<int, 4>& a) {
  if (a[0] == 0) {
    if (a[1] || a[2] || a[3]) {
      cout << "1" << endl;
    } else {
      cout << "0" << endl;
    }
    return;
  }

  int alice = a[0], bob = a[0];
  ll ans = a[0];
  int one_likes = min(a[1], a[2]);
  ans += one_likes * 2;
  a[1] -= one_likes;
  a[2] -= one_likes;

  if (a[1] && bob > 0) {
    int type2 = min(bob+1, a[1]);
    bob -= type2;
    alice += type2;
    ans += type2;
  }
  if (a[2] && alice > 0) {
    int type3 = min(alice+1, a[2]);
    alice -= type3;
    bob += type3;
    ans += type3;
  }

  if (alice < 0 || bob < 0) {
    cout << ans << endl;
    return;
  }

  int type4 = min({alice+1, bob+1, a[3]});
  ans += type4;
  cout << ans << endl;;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    array<int, 4> a;
    for (int i = 0; i < 4; ++i) cin >> a[i];

    solve(a);
  }
  return 0;
}
