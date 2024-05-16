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

fn not(x: i32) -> i32 {
    if x % 2 == 1 {
        x + 1
    } else {
        x - 1
    }
}

fn dfs1(node: usize, adj: &Vec<Vec<usize>>, visited: &mut Vec<bool>, ordering: &mut Vec<usize>) {
    if visited[node] {
        return;
    }
    visited[node] = true;
    for &next_node in adj[node].iter() {
        dfs1(next_node, adj, visited, ordering);
    }
    ordering.push(node);
}

fn dfs2(node: usize, rev_adj: &Vec<Vec<usize>>, components: &mut Vec<i32>, c: i32) {
    if components[node] >= 0 {
        return;
    }
    components[node] = c;
    for &next_node in rev_adj[node].iter() {
        dfs2(next_node, rev_adj, components, c);
    }
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let mut g: Vec<Vec<i32>> = Vec::new();
    for _i in 0..3 {
        g.push(read_vec());
    }

    let vars = n;
    let mut adj: Vec<Vec<usize>> = vec![Vec::new(); vars*2+1];
    for i in 0..n {
        let a = g[0][i].abs() * 2 - if g[0][i] < 0 { 1 } else { 0 };
        let b = g[1][i].abs() * 2 - if g[1][i] < 0 { 1 } else { 0 };
        let c = g[2][i].abs() * 2 - if g[2][i] < 0 { 1 } else { 0 };
        let not_a = not(a);
        let not_b = not(b);
        let not_c = not(c);
        adj[not_a as usize].push(b as usize);
        adj[not_a as usize].push(c as usize);
        adj[not_b as usize].push(a as usize);
        adj[not_b as usize].push(c as usize);
        adj[not_c as usize].push(a as usize);
        adj[not_c as usize].push(b as usize);
    }

    let mut visited = vec![false; vars*2 + 1];
    let mut ordering = Vec::new();
    for node in 1..=vars*2 {
        if !visited[node] {
            dfs1(node, &adj, &mut visited, &mut ordering);
        }
    }

    let mut rev_adj: Vec<Vec<usize>> = vec![Vec::new(); vars*2 + 1];
    for node in 1..=vars*2 {
        for &next_node in adj[node].iter() {
            rev_adj[next_node].push(node);
        }
    }

    ordering.reverse();
    let mut components = vec![-1; vars*2 + 1];
    let mut c = 1;
    for &node in ordering.iter() {
        if components[node] == -1 {
            dfs2(node, &rev_adj, &mut components, c);
            c += 1;
        }
    }

    for node in (2..=vars*2).step_by(2) {
        let not_node = node-1;
        if components[node] == components[not_node] {
            writeln!(writer, "NO").ok();
            return;
        }
    }
    writeln!(writer, "YES").ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
