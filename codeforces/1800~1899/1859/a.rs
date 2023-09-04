use std::io;

fn read_int() -> i32 {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    return s.trim().parse::<i32>().expect("invalid input");
}

fn read_vec() -> Vec<i32> {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|s| s.trim().parse::<i32>().expect("invalid input")).collect()
}

fn solve() {
    let n = read_int();
    let a = read_vec();

    let max_val = *a.iter().max().unwrap();
    let mut b: Vec<i32> = Vec::new();
    let mut c: Vec<i32> = Vec::new();

    for i in 0..n {
        let x = a[i as usize];
        if x == max_val {
            c.push(x);
        } else {
            b.push(x);
        }
    }

    if c.len() == (n as usize) {
        println!("-1");
        return;
    }

    println!("{} {}", b.len(), c.len());
    for x in b {
        print!("{} ", x);
    }
    println!();

    for x in c {
        print!("{} ", x);
    }
    println!();
}

fn main() {
    let t = read_int();
    for _t in 0..t {
        solve();
    }
}
