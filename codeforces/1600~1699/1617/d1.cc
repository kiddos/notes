#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(vector<bool>& ans, int n) {
  vector<int> imposter;
  for (int i = 1; i <= n; ++i) {
    if (!ans[i]) {
      imposter.push_back(i);
    }
  }

  cout << "! ";
  cout << imposter.size() << " ";
  for (int idx : imposter) {
    cout << idx << " ";
  }
  cout << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  int imposter = 0, crew = 0;
  vector<bool> ans(n+1);
  int last = query(1, 2, 3);
  for (int i = 1; i+3 <= n; ++i) {
    int result = query(i+1, i+2, i+3);
    if (last == 0 && result == 1) {
      imposter = i;
      crew = i+3;
      break;
    } else if (last == 1 && result == 0) {
      imposter = i+3;
      crew = i;
      break;
    }

    last = result;
  }
  ans[crew] = true;

  for (int i = 1; i <= n; ++i) {
    if (i != imposter && i != crew) {
      int result = query(imposter, crew, i);
      if (result == 1) {
        ans[i] = true;
      }
    }
  }

  answer(ans, n);
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
