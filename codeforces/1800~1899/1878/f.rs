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

fn get_factors(n: i32) -> BTreeMap<i32,i32> {
    let mut factors = BTreeMap::new();
    let mut x = n;
    let mut d = 2;
    while d * d <= x {
        while x % d == 0 {
            factors.entry(d).and_modify(|c| *c += 1).or_insert(1);
            x /= d;
        }
        d += 1;
    }
    if x > 1 {
        factors.entry(x).and_modify(|c| *c += 1) .or_insert(1);
    }
    factors
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<i32>();
    let n = inputs[0];
    let q = inputs[1];

    let mut n_factors = get_factors(n);
    let n0_factors = n_factors.clone();
    for _i in 0..q {
        let query = read_vec::<i32>();
        if query[0] == 1 {
            let x = query[1];
            let x_factors = get_factors(x);
            for (k, v) in x_factors.into_iter() {
                n_factors.entry(k).and_modify(|c| *c += v).or_insert(v);
            }

            let mut d_factors = BTreeMap::new();
            for v in n_factors.values() {
                let f = get_factors(*v + 1);
                for (k2,v2) in f.into_iter() {
                    d_factors.entry(k2).and_modify(|c| *c += v2).or_insert(v2);
                }
            }

            let mut ans = true;
            for (k,v) in d_factors.iter() {
                if !n_factors.contains_key(k) || n_factors.get(k).unwrap() < v {
                    ans = false;
                    break;
                }
            }

            if ans {
                writeln!(writer, "YES").ok();
            } else {
                writeln!(writer, "NO").ok();
            }
        } else if query[0] == 2 {
            n_factors = n0_factors.clone();
        }
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
