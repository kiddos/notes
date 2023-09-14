use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn dfs(
    node: usize,
    d: i32,
    adj: &Vec<Vec<i32>>,
    has_one: &Vec<bool>,
    has_zero: &Vec<bool>,
    ans: &mut bool,
) -> bool {
    if has_zero[node] && d <= 1 {
        *ans = false;
    }

    let mut o = has_one[node];
    for next_node in &adj[node] {
        let result = dfs(*next_node as usize, d + 1, adj, has_one, has_zero, ans);
        o = o || result;
    }

    if has_zero[node] && o {
        *ans = false;
    }
    o
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let s = read_str();

    let mut adj: Vec<Vec<i32>> = vec![Vec::new()];
    let mut nodes: Vec<i32> = vec![0];
    let mut has_one: Vec<bool> = vec![false];
    let mut has_zero: Vec<bool> = vec![false];
    let mut new_node = 1;

    for ch in s.chars() {
        let current_node = *nodes.last().unwrap() as usize;
        if ch == '+' {
            adj[current_node].push(new_node);
            nodes.push(new_node);
            new_node += 1;
            has_one.push(false);
            has_zero.push(false);
            adj.push(Vec::new());
        } else if ch == '-' {
            nodes.pop();
        } else if ch == '1' {
            has_one[current_node] = true;
        } else if ch == '0' {
            has_zero[current_node] = true;
        }
    }

    let mut ans = true;
    dfs(0, 0, &adj, &has_one, &has_zero, &mut ans);

    if ans {
        writeln!(writer, "YES").ok();
    } else {
        writeln!(writer, "NO").ok();
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
