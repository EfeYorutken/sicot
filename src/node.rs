
pub mod node{
    use std::fmt::Display;

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

        pub fn apply_pre_order_mut<F>(mut self, f : &F) where F : FnMut(&Node<T>) + Fn(&Node<T>) {

            f(&mut self);

            match self.left{
                Some(left) => left.apply_pre_order(f),
                None => {},
            }

            match self.right{
                Some(right) => right.apply_pre_order(f),
                None => {},
            }

        }

    }

}

