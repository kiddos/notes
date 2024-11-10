use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;

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

fn compute_depth(node: usize, parent: usize,
    adj: &Vec<Vec<usize>>,
    depths: &mut Vec<i32>) {
    for &next_node in adj[node].iter() {
        if next_node == parent {
            continue;
        }

        depths[next_node] = depths[node] + 1;
        compute_depth(next_node, node, adj, depths);
    }
}

fn dfs(node: usize, parent: usize,
    adj: &Vec<Vec<usize>>,
    depths: &Vec<i32>,
    max_moves: &mut Vec<(i32,i32)>) {
    let mut children_depths = Vec::new();
    for &next_node in adj[node].iter() {
        if next_node == parent {
            continue;
        }

        dfs(next_node, node, adj, depths, max_moves);
        children_depths.push(max_moves[next_node].0 + 1);
    }

    children_depths.sort();
    children_depths.reverse();
    if children_depths.len() >= 2 {
        max_moves[node] = (children_depths[0], children_depths[1]);
    } else if children_depths.len() == 1 {
        max_moves[node] = (children_depths[0], 0);
    }
}

fn compute_binary_lift(node: usize, parent: usize,
    adj: &Vec<Vec<usize>>,
    max_moves: &Vec<(i32,i32)>,
    depths: &Vec<i32>,
    binary_lift: &mut Vec<Vec<(i32,usize)>>) {
    binary_lift[0][node].1 = parent;
    if max_moves[node].0 + 1 < max_moves[parent].0 {
        binary_lift[0][node].0 = max_moves[parent].0 - depths[parent];
    } else {
        binary_lift[0][node].0 = max_moves[parent].1 - depths[parent];
    }

    for l in 1..binary_lift.len() {
        let last = binary_lift[l-1][node].1;
        binary_lift[l][node].0 = max(binary_lift[l-1][node].0, binary_lift[l-1][last].0);
        binary_lift[l][node].1 = binary_lift[l-1][last].1;
    }

    for &next_node in adj[node].iter() {
        if next_node == parent {
            continue;
        }

        compute_binary_lift(next_node, node, adj, max_moves, depths, binary_lift);
    }
}

fn compute_query(node: usize, k: usize,
    max_moves: &Vec<(i32,i32)>,
    depths: &Vec<i32>,
    binary_lift: &Vec<Vec<(i32,usize)>>) -> i32 {
    let mut ans = max_moves[node].0 - depths[node];
    let mut current = node;
    for l in 0..binary_lift.len() {
        if k & (1 << l) > 0 {
            ans = ans.max(binary_lift[l][current].0);
            current = binary_lift[l][current].1;
        }
    }
    ans + depths[node]
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let mut edges = Vec::new();
    for _i in 1..n {
        let edge = read_vec::<usize>();
        edges.push(edge);
    }

    let mut adj = vec![Vec::new(); n + 1];
    for e in edges.iter() {
        let (u, v) = (e[0], e[1]);
        adj[u].push(v);
        adj[v].push(u);
    }

    let mut depths = vec![0; n+1];
    compute_depth(1, 1, &adj, &mut depths);
    let mut max_moves = vec![(0, 0); n+1];
    dfs(1, 1, &adj, &depths, &mut max_moves);
    let L = (n as f32).log2().ceil() as usize;
    let mut binary_lift = vec![vec![(0, 1); n+1]; L+1];
    compute_binary_lift(1, 1, &adj, &max_moves, &depths, &mut binary_lift);

    // for l in 0..=L {
    //     for node in 1..=n {
    //         write!(writer, "{} ", binary_lift[l][node].0).ok();
    //     }
    //     writeln!(writer).ok();
    // }

    let q = read_int::<usize>();
    for _i in 0..q {
        let query = read_vec::<usize>();
        let v = query[0];
        let k = query[1];
        let ans = compute_query(v, k, &max_moves, &depths, &binary_lift);
        write!(writer, "{} ", ans).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
