#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(2, 10000);
  vector<int> nums;
  const int N = 100000;
  for (int i = 0; i < N; ++i) {
    nums.push_back(dist(gen));
  }

  unordered_map<int, vector<int>> groups;
  for (int i = 0; i < N; ++i) {
    int num = nums[i];
    for (int d = 2; d * d <= num; ++d) {
      if (num % d == 0) {
        while (num % d == 0) {
          num /= d;
        }
        groups[d].push_back(nums[i]);
      }
    }
    if (num > 1) {
      groups[num].push_back(nums[i]);
    }
  }

  for (auto& [factor, group] : groups) {
    cout << "divisable by " << factor << endl;
    for (int num : group) cout << num << " ";
    cout << endl;
  }

  return 0;
}
