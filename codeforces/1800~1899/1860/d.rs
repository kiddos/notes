use std::io;
use std::cmp::min;

const INF: i32 = 1e9 as i32;

fn read_str() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn solve() {
    let s = read_str();
    let n = s.len();
    let mut dp: Vec<Vec<i32>> = vec![vec![INF; n*n]; n+1];
    dp[0][0] = 0;
    for i in 0..n {
        let mut next_dp: Vec<Vec<i32>> = vec![vec![INF; n*n]; n+1];
        let ch = s.chars().nth(i).unwrap();
        for j in 0..=(i as usize) {
            let mut c01: usize = 0;
            while c01+j < n*n {
                next_dp[j+1][c01] = min(next_dp[j+1][c01], dp[j][c01] + ((ch != '0') as i32));
                next_dp[j][c01+j] = min(next_dp[j][c01+j], dp[j][c01] + ((ch != '1') as i32));
                c01 += 1;
            }
        }

        dp = next_dp;
    }

    let c0 = s.chars().filter(|ch| *ch == '0').count() as usize;
    println!("{}", dp[c0][c0 * (n-c0) / 2] / 2);
}

fn main() {
    solve();
}
