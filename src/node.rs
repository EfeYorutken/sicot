pub mod node{
    use std::fmt::{format, Display};

    pub struct Node<T : Display>{
        pub val : Option<T>,
        left : Option< Box< Node< T > > >,
        right : Option< Box< Node< T > > >
    }

    impl<T : Display> Node<T>{

        pub fn new(val : Option<T>) -> Node<T>{

            Node{ val : val, left : Option::None, right : Option::None }

        }

        pub fn add_right_child(&mut self, n : Node<T>){
            self.right = Option::Some( Box::new( n ) );
        }

        pub fn add_left_child(&mut self, n : Node<T>){
            self.left = Option::Some( Box::new( n ) );
        }


        pub fn apply_pre_order<F>(self, f : &F) where F : Fn(&Node<T>) {

            f(&self);

            match self.left{
                Some(left) => left.apply_pre_order(f),
                None => {},
            }

            match self.right{
                Some(right) => right.apply_pre_order(f),
                None => {},
            }

        }

        pub fn to_string(self)-> String{

            let left_res = match self.left{
                Some(lft) => lft.to_string(),
                None => String::from("None")
            };

            let right_res = match self.right{
                Some(rgt) => rgt.to_string(),
                None => String::from("None")
            };

            let self_val = match self.val{
                Some(val) => format!("{}", val),
                None => String::from("None")
            };

            return format!("({}, {}, {})", self_val, left_res, right_res);
        }

    }

}

