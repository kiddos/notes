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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<i32>();
    let n = inputs[0] as usize;
    let k = inputs[1];

    let mut b = read_vec::<usize>();
    b.insert(0, 0);

    if k == 1 {
        for i in 1..=n {
            if b[i] != i {
                writeln!(writer, "NO").ok();
                return;
            }
        }
        writeln!(writer, "YES").ok();
        return;
    }

    let mut ids = vec![0; n+1];
    let mut time = vec![0; n+1];
    let mut id = 1;
    for i in 1..=n {
        if ids[i] > 0 {
            continue;
        }

        let mut node = i;
        let mut t = 1;
        let current = id;
        id += 1;
        ids[node] = current;
        time[node] = t;
        t += 1;
        while ids[b[node]] == 0 {
            node = b[node];
            ids[node] = current;
            time[node] = t;
            t += 1;
        }

        if ids[b[node]] != current {
            continue;
        }
        
        // writeln!(writer, "{} ", node).ok();
        let cycle_len = time[node] - time[b[node]] + 1;
        // writeln!(writer, "cycle: {}", cycle_len).ok();
        if cycle_len != k {
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
