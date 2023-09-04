use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;
use std::cmp::min;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_str() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn solve() {
    let sizes = read_vec::<usize>();
    let n = sizes[0];
    let m = sizes[1];
    let mut grid: Vec<String> = Vec::new();
    
    for _i in 0..n {
        grid.push(read_str());
    }

    let mut found = false;
    let mut b: (usize, usize, usize, usize) = (n, m, 0, 0);
    for i in 0..n {
        for j in 0..m {
            if grid[i].as_bytes()[j] == b'R' {
                found = true;
                b.0 = min(b.0, i);
                b.1 = min(b.1, j);
                b.2 = max(b.2, i);
                b.3 = max(b.3, j);
            }
        }
    }

    if !found {
        println!("NO");
        return;
    }

    if grid[b.0].as_bytes()[b.1] == b'R' {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
