use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn find_bit(mask: usize) -> i32 {
    for i in 0..20 {
        if (mask & (1<<i)) > 0 {
            return i;
        }
    }
    return -1;
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let m = inputs[1];
    let a = read_vec::<i64>();
    let b = read_vec::<i64>();

    let mut programmers: Vec<(i64, usize)> = Vec::new();
    for i in 0..n {
        programmers.push((a[i], i+1));
    }

    programmers.sort();
    programmers.reverse();

    let inf = 1000000000;
    let mut require = vec![vec![inf; n]; m];
    for p in 0..m {
        let mut r = 0;
        for l in 0..n {
            r = max(r, l);
            while r < n && (b[p] + (r - l) as i64) / (r - l + 1) as i64 > programmers[r].0 {
                r += 1;
            }

            let len = (r - l + 1) as i64;
            if r < n && programmers[r].0 >= (b[p] + len - 1) / len {
                require[p][l] = len;
            }
        }
    }

    let size = 1 << m;
    let mut dp = vec![inf; size];
    let mut parent = vec![0; size];

    dp[0] = 0;
    for mask in 0..size {
        for p in 0..m {
            if (mask & (1<<p)) == 0 {
                if dp[mask] >= n as i64 {
                    continue;
                }
                let need = require[p][dp[mask] as usize];
                if need == inf {
                    continue;
                }

                let mask2 = mask | (1<<p);
                let result = dp[mask] + need;
                if result < dp[mask2] {
                    dp[mask2] = result;
                    parent[mask2] = mask;
                }
            }
        }
    }

    if dp[size-1] == inf {
        writeln!(writer, "NO").ok();
        return;
    }

    let mut mask = size-1;
    let mut i = dp[size-1] - 1;
    let mut ans = vec![Vec::new(); m];
    while mask != 0 {
        let old_mask = mask;
        mask = parent[mask];
        let which = find_bit(mask ^ old_mask);
        let mut need = dp[old_mask] - dp[mask];

        while need > 0 {
            ans[which as usize].push(programmers[i as usize].1);
            need -= 1;
            i -= 1;
        }
    }

    writeln!(writer, "YES").ok();
    for p in 0..m {
        write!(writer, "{} ", ans[p].len()).ok();
        for i in 0..ans[p].len() {
            write!(writer, "{} ", ans[p][i]).ok();
        }
        writeln!(writer).ok();
    }
}

fn main() {
    solve();
}
