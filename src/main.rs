#![allow(dead_code)]
#![allow(unused_variables)]

mod node;

use node::node::Node;


fn main(){

    let mut v : Vec<Node<i32>> = vec![
        1,
        2,
        3,
        4,
        5,
        6,
    ]
        .iter()
        .map(|e|{
            Node::new(Some(e.clone()))
        })
    .collect();

    v.push(Node::new(None));

    let mut n = v.pop().unwrap();
    let first = v.pop().unwrap();
    let second = v.pop().unwrap();

    n.add_right_child(first);
    n.add_left_child(second);

    v.push(n);

    while v.len() != 1{

        let first = v.pop().unwrap();
        let second = v.pop().unwrap();
        let mut new : Node<i32> = Node::new(None);

        new.add_right_child(first);
        new.add_left_child(second);

        v.push(new);

    }

    let n = v.pop().unwrap();

    let mere_print = |elem : &Node<i32>| {println!("{}", match elem.val {
        Some(val) => format!("{}", val),
        None => String::from("None")
    })};

    n.apply_pre_order(&mere_print);

}
