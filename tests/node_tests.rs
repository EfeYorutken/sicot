
fn node_new_test(){
    let none_vers = node::Node<i32>{
        val : Option::None
    };

    let some_vers = node::Node<i32>{
        val : Option::Some(123)
    };
}
