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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<i32>();
    let a = read_vec::<i32>();
    let b = read_vec::<i32>();

    let mut pool = BTreeMap::new();
    let mut i = (n-1) as i32;
    let mut j = (n-1) as i32;
    while j >= 0 && i >= 0 {
        while j >= 0 && j+1 < n && b[(j+1) as usize] == b[j as usize] {
            pool.entry(b[j as usize]).and_modify(|count| *count += 1).or_insert(1);
            j -= 1;
        }

        // writeln!(writer, "{} {}", i, j).ok();
        while j >= 0 && i >= 0 && a[i as usize] != b[j as usize] {
            let count = pool.get(&a[i as usize]);
            if count.is_none() || *count.unwrap() == 0 {
                writeln!(writer, "NO").ok();
                return;
            }

            pool.entry(a[i as usize]).and_modify(|count| *count -= 1);
            i -= 1;
        }

        i -= 1;
        j -= 1;
    }

    writeln!(writer, "YES").ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
