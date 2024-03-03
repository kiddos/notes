use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeMap;

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

fn dfs(node: usize, p: usize, c: &Vec<i32>, adj: &Vec<Vec<usize>>, ans: &mut i64, dp: &mut Vec<BTreeMap<i32, i64>>) {
    let mut largest = 0;
    let mut largest_len = 0;
    for next_node in adj[node].iter() {
        if *next_node == p {
            continue;
        }

        dfs(*next_node, node, c, adj, ans, dp);
        if dp[*next_node].len() > largest_len {
            largest = *next_node;
            largest_len = dp[*next_node].len();
        }
    }

    if largest > 0 {
        dp.swap(node, largest);
    }

    let current_color = c[node];
    for next_node in adj[node].iter() {
        if *next_node == p {
            continue;
        }
        if *next_node == largest {
            continue;
        }

        let c1 = &dp[*next_node];
        let c2 = &mut dp[largest];
        for (color, count) in c1.iter() {
            if *color != current_color {
                if let Some(count2) = c2.get(color) {
                    *ans += count2 * *count;
                }
            }
            c2.entry(*color);
            // dp[largest].entry(color).and_modify(|c| *c += count).or_insert(count);
        }
    }
    if let Some(count) = dp[node].get(&current_color) {
        *ans += count;
    }
    dp[node].entry(current_color).and_modify(|c| *c = 1).or_insert(1);
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let mut c = read_vec::<i32>();
    c.insert(0, 0);

    let mut adj: Vec<Vec<usize>> = vec![Vec::new(); n+1];
    for _i in 1..n {
        let edge = read_vec::<usize>();
        let u = edge[0];
        let v = edge[1];
        adj[u].push(v);
        adj[v].push(u);
    }

    let mut ans: i64 = 0;
    let mut dp: Vec<BTreeMap<i32,i64>> = vec![BTreeMap::new(); n+1];
    dfs(1, 0, &c, &adj, &mut ans, &mut dp);

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
