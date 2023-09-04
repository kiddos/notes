use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn dfs(adj: &Vec<Vec<usize>>, node: usize, parent: usize, ans: &mut i64) -> i32 {
    let mut sizes: Vec<i32> = Vec::new();
    for next_node in &adj[node] {
        if *next_node == parent {
            continue;
        }

        sizes.push(dfs(&adj, *next_node, node, ans));
    }

    let total = sizes.iter().sum::<i32>() as usize;
    let mut dp: Vec<bool> = vec![false; total+1];
    dp[0] = true;
    let mut max_mul = 0;
    for i in 0..sizes.len() {
        for a in (0..=total).rev() {
            let a2 = (a as i32) - sizes[i];
            if a2 < 0 {
                continue;
            }

            if dp[a2 as usize] {
                dp[a] = true;

                let x = a as i64;
                let y = (total as i64) - x;
                max_mul = max(max_mul, x * y);
            }
        }
    }

    *ans += max_mul;

    (total as i32) + 1
}

fn solve() {
    let n = read_int::<usize>();
    let parents = read_vec::<usize>();

    let mut adj: Vec<Vec<usize>> = vec![Vec::new(); n+1];
    for (i, p) in parents.iter().enumerate() {
        adj[*p].push(i+2);
    }

    let mut ans: i64 = 0;
    dfs(&adj, 1, 0, &mut ans);

    println!("{}", ans);
}

fn main() {
    solve();
}
