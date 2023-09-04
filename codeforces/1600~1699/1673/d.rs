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

fn get_factors(r: i64) -> Vec<i64> {
    let s = (r as f64).sqrt() as i64;
    let mut f: Vec<i64> = Vec::new();
    for d in 1..=s {
        if r % d == 0 {
            f.push(r / d);
            f.push(d);
        }
    }
    f.sort();
    f.dedup();
    f
}

fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn lcm(a: i64, b: i64) -> i64 {
    a * b / gcd(a, b)
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs1 = read_vec::<i64>();
    let b = inputs1[0];
    let q = inputs1[1];
    let y = inputs1[2];

    let inputs2 = read_vec::<i64>();
    let c = inputs2[0];
    let r = inputs2[1];
    let z = inputs2[2];

    let b_min = b;
    let b_max = b + q * (y-1);
    let c_min = c;
    let c_max = c + r * (z-1);

    if r % q != 0 {
        writeln!(writer, "0").ok();
        return;
    }

    if (c_min - b_min).abs() % q != 0 {
        writeln!(writer, "0").ok();
        return;
    }

    if c_min < b_min || c_max > b_max {
        writeln!(writer, "0").ok();
        return;
    }

    if b_min > c_min - r || b_max < c_max + r {
        writeln!(writer, "-1").ok();
        return;
    }

    const MOD: i64 = 1000000007;
    let factors = get_factors(r);
    let mut ans = 0;

    for p in factors {
        if lcm(p, q) == r {
            ans += (r / p) * (r / p);
            ans %= MOD;
        }
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
