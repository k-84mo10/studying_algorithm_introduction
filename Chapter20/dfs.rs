fn dfs(graph: &Vec<Vec<i32>>, sorted: &mut Vec<i32>) {
    let mut color = vec!["WHITE"; graph.len()];
    let mut finished = vec![-1; graph.len()];

    let mut time = 0;

    for u in 0..graph.len() {
        if color[u] == "WHITE" {
            dfs_visit(graph, sorted, &mut color, &mut finished, &mut time, u);
        }
    }
}

fn dfs_visit(graph: &Vec<Vec<i32>>, sorted: &mut Vec<i32>, color: &mut Vec<&str>, finished: &mut Vec<i32>, time: &mut i32, u: usize) {
    color[u] = "GRAY";
    *time += 1;

    for &v in &graph[u] {
        if color[v as usize] == "WHITE" {
            dfs_visit(graph, sorted, color, finished, time, v as usize);
        }
    }

    color[u] = "BLACK";
    *time += 1;
    finished[u] = *time;
    sorted.insert(0, u as i32);
}   

fn main() {
    let graph = vec![
        vec![4, 5, 11],
        vec![2, 4, 8],
        vec![5, 6, 9],
        vec![2, 6, 13],
        vec![7],
        vec![8, 12],
        vec![5],
        vec![],
        vec![7],
        vec![10, 11],
        vec![13],
        vec![],
        vec![9],
        vec![],
    ];

    let mut sorted = vec![];
    dfs(&graph, &mut sorted);

    for i in sorted {
        let ch = ('m' as u8 + i as u8) as char;
        print!("{} ", ch);
    }
    println!("")
}