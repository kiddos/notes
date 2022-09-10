#include <bits/stdc++.h>

using namespace std;


// closest pair of points
// the naive solution is to do this in O(n^2)
//
// link: https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/
//
// divide and conquer can do this in O(n log n)
// the idea is to separate the coordinates into 2 halfs
// recusively compute the solution

int compute_dist(vector<int>& c1, vector<int>& c2) {
  int dx = c1[0] - c2[0], dy = c1[1] - c2[1];
  return dx * dx + dy * dy;
}

int closest_pair_of_points(vector<vector<int>>& coordinates) {
  sort(coordinates.begin(), coordinates.end(), [&](auto& c1, auto& c2) {
    if (c1[0] == c2[0]) return c1[1] < c2[1];
    return c1[0] < c2[0];
  });

  int n = coordinates.size();
  function<int(int, int)> divide_and_conquer = [&](int l, int r) {
    if (r - l <= 2) {
      int dist = numeric_limits<int>::max();
      for (int i = l; i < r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
          dist = min(dist, compute_dist(coordinates[i], coordinates[j]));
        }
      }
      return dist;
    }

    int m = l + (r - l) / 2;
    int dist = min(divide_and_conquer(l, m), divide_and_conquer(m + 1, r));
    int x = (coordinates[m][0] + coordinates[m + 1][0]) / 2;
    vector<vector<int>> strips;
    for (int i = l; i <= r; ++i) {
      int dx = coordinates[i][0] - x;
      if (dx * dx <= dist) {
        strips.push_back(coordinates[i]);
      }
    }
    sort(strips.begin(), strips.end(), [&](auto& c1, auto& c2) {
      if (c1[1] == c2[1]) return c1[0] < c2[0];
      return c1[1] < c2[1];
    });

    int size = strips.size();
    for (int p = 0; p < size - 1; ++p) {
      for (int q = p + 1; q < size; ++q) {
        if (strips[q][1] - strips[p][1] >= dist) break;
        dist = min(dist, compute_dist(strips[p], strips[q]));
      }
    }
    return dist;
  };

  return divide_and_conquer(0, n - 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> coordinates = {{0, 0}, {1, 1}, {2, 4}};

  int ans = closest_pair_of_points(coordinates);
  assert(ans == 2);
  return 0;
}
