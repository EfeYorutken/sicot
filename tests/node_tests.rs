#[cfg(test)]
mod tests{
    use sicot::node::Node;

    #[test]
    fn new_test() {
        let n : Node<i32> = Node::new(Some(12));
        assert_eq!(n.val, Some(12));
    }

    #[test]
    fn string_test() {
        let mut n = Node::new(Some(1));
        n.add_left_child(Node::new(Some(2)));
        n.add_right_child(Node::new(Some(3)));

        let correct = String::from("(1, (2, None, None), (3, None, None))");
        let ans = n.to_string();

        assert_eq!(ans, correct);
        println!("{}", ans);
    }


}
