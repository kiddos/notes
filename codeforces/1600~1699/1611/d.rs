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
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn dfs(node: usize, adj: &Vec<Vec<(usize, i32)>>, dist: &mut Vec<i32>) {
    for (child, weight) in adj[node].iter() {
        dist[*child] = dist[node] + *weight;
        dfs(*child, adj, dist);
    }
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let mut b = read_vec::<usize>();
    let mut p = read_vec::<usize>();

    b.insert(0, 0);
    p.insert(0, 0);

    let mut temp = vec![0; n+1];
    let mut w: Vec<i32> = vec![0; n+1];
    for i in 2..=n {
        temp[p[i]] = temp[p[i-1]] + 1;
        w[p[i]] = temp[p[i]] - temp[b[p[i]]];
    }

    let mut adj = vec![Vec::new(); n+1];
    let mut root = 0;
    for i in 1..=n {
        if b[i] != i {
            adj[b[i]].push((i, w[i]));
        } else {
            root = i;
        }
    }

    let mut dist = vec![0; n+1];
    dfs(root, &adj, &mut dist);

    for i in 2..=n {
        if dist[p[i-1]] >= dist[p[i]] {
            writeln!(writer, "-1").ok();
            return;
        }
    }

    for i in 1..=n {
        write!(writer, "{} ", w[i]).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
