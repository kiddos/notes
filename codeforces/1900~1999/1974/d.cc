#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<int> instructions(2);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'N') {
      instructions[0]++;
    } else if (s[i] == 'S') {
      instructions[0]--;
    } else if (s[i] == 'E') {
      instructions[1]++;
    } else if (s[i] == 'W') {
      instructions[1]--;
    }
  }

  if (abs(instructions[0]) % 2 == 1 || abs(instructions[1]) % 2 == 1) {
    cout << "NO" << endl;
    return;
  }

  int total = abs(instructions[0]) + abs(instructions[1]);
  
  vector<int> south, north, east, west;
  string ans(n, ' ');
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'N') {
      if (instructions[0] > 0) {
        if (instructions[0] % 2 == 0) {
          ans[i] = 'R';
        } else {
          ans[i] = 'H';
        }
        instructions[0]--;
      } else {
        north.push_back(i);
      }
    } else if (s[i] == 'S') {
      if (instructions[0] < 0) {
        if (instructions[0] % 2 == 0) {
          ans[i] = 'R';
        } else {
          ans[i] = 'H';
        }
        instructions[0]++;
      } else {
        south.push_back(i);
      }
    } else if (s[i] == 'E') {
      if (instructions[1] > 0) {
        if (instructions[1] % 2 == 0) {
          ans[i] = 'R';
        } else {
          ans[i] = 'H';
        }
        instructions[1]--;
      } else {
        east.push_back(i);
      }
    } else if (s[i] == 'W') {
      if (instructions[1] < 0) {
        if (instructions[1] % 2 == 0) {
          ans[i] = 'R';
        } else {
          ans[i] = 'H';
        }
        instructions[1]++;
      } else {
        west.push_back(i);
      }
    }
  }

  if (south.size() + north.size() + east.size() + west.size() == 2 && total == 0) {
    cout << "NO" << endl;
    return;
  }

  int which = 0;
  auto consume = [&](vector<int>& type1, vector<int>& type2) {
    while (!type1.empty() && !type2.empty()) {
      int ins1 = type1.back();
      type1.pop_back();
      int ins2 = type2.back();
      type2.pop_back();
      if (which) {
        ans[ins1] = ans[ins2] = 'H';
      } else {
        ans[ins1] = ans[ins2] = 'R';
      }
      which ^= 1;
    }
  };

  consume(south, north);
  consume(east, west);


  cout << ans << endl;
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
