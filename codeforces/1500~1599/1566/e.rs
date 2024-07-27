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

fn dfs(node: usize, p: usize, adj: &Vec<Vec<usize>>, degree: &mut Vec<i32>, is_bud: &mut Vec<bool>) -> bool {
    let mut all_leaf = true;
    for &next_node in adj[node].iter() {
        if next_node == p {
            continue;
        }

        if dfs(next_node, node, adj, degree, is_bud) {
            degree[node] -= 1;
        }
    }

    for &next_node in adj[node].iter() {
        if next_node == p {
            continue;
        }

        if !is_bud[next_node] && degree[next_node] != 1 {
            all_leaf = false;
        }
    }

    if all_leaf && degree[node] > 1 && node != 1 {
        is_bud[node] = true;
        return true;
    }
    false
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<usize>();
    let mut adj = vec![Vec::new(); n+1];
    let mut degree = vec![0; n+1];
    for _i in 1..n {
        let edge = read_vec::<usize>();
        let u = edge[0];
        let v = edge[1];
        adj[u].push(v);
        adj[v].push(u);
        degree[u] += 1;
        degree[v] += 1;
    }

    let mut is_bud = vec![false; n+1];
    dfs(1, 0, &adj, &mut degree, &mut is_bud);

    let mut bud_count = 0;
    for node in 1..=n {
        if is_bud[node] {
            bud_count += 1;
        }
    }

    let mut root_has_leaf = false;
    for &next_node in adj[1].iter() {
        if degree[next_node] == 1 {
            root_has_leaf = true;
        }
    }

    let mut ans = n - bud_count * 2;
    if root_has_leaf {
        ans -= 1;
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
