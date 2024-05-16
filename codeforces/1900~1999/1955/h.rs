use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    if s.is_empty() {
        return Vec::new();
    }
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

const MAX_R: usize = 12;

fn compute_damage(x: i32, y: i32, p: i32, r: i32, grid: &Vec<Vec<char>>) -> i32 {
    let n = grid.len();
    let m = grid[0].len();
    let mut ans = 0;
    for i in 0..n {
        for j in 0..m {
            if grid[i][j] == '#' {
                let dx = i as i32 - x;
                let dy = j as i32 - y;
                let s = dx * dx + dy * dy;
                if s <= r * r {
                    ans += p;
                }
            }
        }
    }
    ans
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let k = inputs[2];

    let mut grid: Vec<Vec<char>> = Vec::new();
    for _i in 0..n {
        grid.push(read_str().chars().collect());
    }

    let mut x: Vec<i32> = vec![0; k+1];
    let mut y: Vec<i32> = vec![0; k+1];
    let mut p: Vec<i32> = vec![0; k+1];
    for i in 1..=k {
        let entry = read_vec::<i32>();
        x[i] = entry[0] - 1;
        y[i] = entry[1] - 1;
        p[i] = entry[2];
    }

    let mut damage = vec![vec![0; MAX_R+1]; k+1];
    for i in 1..=k {
        for r in 0..=MAX_R {
            damage[i][r] = compute_damage(x[i], y[i], p[i], r as i32, &grid);
        }
    }

    let mask_size = 1 << (MAX_R + 1);
    let mut dp = vec![vec![0; mask_size]; k+1];
    for i in 1..=k {
        for mask in 0..mask_size {
            dp[i][mask] = dp[i][mask].max(dp[i-1][mask]);
            for r in 0..=MAX_R {
                if mask & (1 << r) > 0 {
                    let old_mask = mask ^ (1 << r);
                    dp[i][mask] = dp[i][mask].max(dp[i-1][old_mask] + damage[i][r]);
                }
            }
        }
    }

    let mut p3: Vec<i64> = vec![1];
    for i in 1..=MAX_R {
        p3.push(p3[i-1] * 3);
    }

    let mut ans = 0;
    for mask in 0..mask_size {
        let mut p3_sum = 0;
        for r in 0..=MAX_R {
            if mask & (1 << r) > 0 {
                p3_sum += p3[r];
            }
        }
        ans = ans.max(dp[k][mask] as i64 - p3_sum);
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
