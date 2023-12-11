use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeSet;
use std::cmp::max;
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

    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let q = inputs[1];
    let mut a = read_vec::<i32>();
    let mut one = BTreeSet::new();
    for i in 0..n {
        if a[i] == 1 {
            one.insert(i);
        }
    }

    for _ in 0..q {
        let query = read_vec::<usize>();
        if query[0] == 1 {
            let s = query[1];
            if one.is_empty() {
                let sum = n * 2;
                if s > sum || s % 2 != 0 {
                    writeln!(writer, "NO").ok();
                } else {
                    writeln!(writer, "YES").ok();
                }
            } else {
                let one_count = one.len();
                if one_count % 2 != s % 2 {
                    let s1 = 2 * (*one.last().unwrap()) - one_count + 1;
                    let s2 = 2 * (n - *one.first().unwrap() - 1) - one_count + 1;
                    if s > max(s1, s2) {
                        writeln!(writer, "NO").ok();
                    } else {
                        writeln!(writer, "YES").ok();
                    }
                } else {
                    let sum = n * 2 - one_count;
                    if s > sum {
                        writeln!(writer, "NO").ok();
                    } else {
                        writeln!(writer, "YES").ok();
                    }
                }
            }
        } else if query[0] == 2 {
            let i = query[1]-1;
            one.remove(&i);
            a[i] = query[2] as i32;
            if a[i] == 1 {
                one.insert(i);
            }
        }
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
