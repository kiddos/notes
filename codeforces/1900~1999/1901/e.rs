use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::*;

const INF: i64 = 1000000000000000000;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn dfs(node: usize, p: usize, adj: &Vec<Vec<usize>>, a: &Vec<i64>, dp: &mut Vec<i64>, ans: &mut i64) {
    let mut dp2 = vec![-INF; 4];
    dp2[0] = 0;
    for next_node in adj[node].iter() {
        if *next_node != p {
            dfs(*next_node, node, adj, a, dp, ans);
        }

        for i in (0..4).rev() {
            dp2[min(i+1, 3)] = max(dp2[min(i+1, 3)], dp2[i] + dp[*next_node]);
        }
    }

    dp[node] = max(dp[node], a[node]);
    dp[node] = max(dp[node], dp2[1]);
    dp[node] = max(dp[node], a[node] + dp2[2]);
    dp[node] = max(dp[node], a[node] + dp2[3]);

    *ans = max(*ans, a[node]);
    *ans = max(*ans, a[node] + dp2[1]);
    *ans = max(*ans, dp2[2]);
    *ans = max(*ans, a[node] + dp2[3]);
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let mut a = read_vec::<i64>();
    a.insert(0, 0);
    let mut adj: Vec<Vec<usize>> = vec![Vec::new(); n+1];
    for _i in 1..n {
        let edge = read_vec::<usize>();
        let u = edge[0];
        let v = edge[1];
        adj[u].push(v);
        adj[v].push(u);
    }

    let mut dp: Vec<i64> = vec![-INF; n+1];
    let mut ans: i64 = 0;
    dfs(1, 0, &adj, &a, &mut dp, &mut ans);

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
