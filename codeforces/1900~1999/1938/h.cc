#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<string> S(n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }
  int ans = 0;
  vector<int> count(3);
  vector<int> exchange(2, numeric_limits<int>::max());
  vector<int> total(n);
  for (int i = 0; i < n; ++i) {
    int one = 0;
    for (char ch : S[i]) {
      one += ch == '1';
    }
    int zero = S[i].length() - one;
    ans += min(zero, one);
    if (one > zero) {
      count[1]++;
    } else if (zero > one) {
      count[0]++;
    } else {
      count[2]++;
    }
    total[0] += zero;
    total[1] += one;

    exchange[0] = min(exchange[0], one - zero);
    exchange[1] = min(exchange[1], zero - one);
  }

  if (total[0] == 0 || total[1] == 0) {
    cout << "0" << endl;
    return;
  }

  while (count[2]) {
    if (count[0] && count[1]) {
      break;
    }

    if (!count[0]) {
      count[2]--;
      count[0]++;
    }
    if (!count[1]) {
      count[2]--;
      count[1]++;
    }
  }

  if (count[0] && count[1]) {
    cout << ans << endl;
  } else if (!count[0]) {
    cout << ans + exchange[0] << endl;
  } else if (!count[1]) {
    cout << ans + exchange[1] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
