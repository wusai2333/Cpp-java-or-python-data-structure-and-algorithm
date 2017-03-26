//ArrayList class
class ArrayList {
public:
	int arr[10];    // backing Array
	int size;       //number of elements that have been inserted;

	//Iterator class
	class Iterator : public std::iterator<std::forward_iterator_tag, int> {
public:
		friend class ArrayList; // declare ArrayList class as  a friend class
		int *curr;              // the element that the iterator is pointing to

		// the following typedefs are needed for the iterator to play nicely with C++ STL
		typedef int				value_type;
		typedef int&				reference;
		typedef int *				pointer;
		typedef int				difference_type;
		typedef std::forward_iterator_tag	iterator_category;

		//iterator constructor
		iterator(int *x = 0) : curr(x) {}

		//overload the == operator of the iterator class
		bool operator==(const iterator& x) const
		{
			return (curr == x.curr); // compare pointers for equality
		}


		//overload the != operator of the iterator class
		bool operator!=(const iterator& x) const
		{
			return (curr != x.curr); // compare pointers for inequality
		}


		//overload the * operator of the iterator class
		bool operator*() const
		{
			return (*curr); //return the curr's value;
		}


		//overload the ++(pre-increment) opereator of the iterator class
		bool operator++() const
		{
			curr++;         //move to next slot of memory;
			return (*this); // return after the move
		}


		//overload the (post-increment) ++ operator of the iterator class
		bool operator++(int) const
		{
			iterator tmp(curr);     //create a temporary iterator to current elements

			curr++;                 // move to next slot of memory
			return (tmp);           // return the iteraotr to the previous value;
		}
	};

	//return iterator to the first element
	iterator begin()
	{
		return (iterator(&arr[0]));
	}


	// return iterator to the last element
	iterator end()
	{
		return iterator(&arr[size])
	}
};

for (auto it = l.begin(); it != l.end(); it++)
{
	cout << *it << endl;
}
