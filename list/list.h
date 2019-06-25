/*
  list interface description
  https://en.cppreference.com/w/cpp/container/list
*/

template <class T, class Allocator = std::allocator<T>>
class list {
       public:
	// constructor
	list();
	explicit list(const Allocator& alloc);
	explicit list(size_type count,
		      const T& value = T(),
		      const Allocator& alloc = Allocator());
	list(size_type count,
	     const T& value,
	     const Allocator& alloc = Allocator());
	explicit list(size_type count);
	// since c++14
	// explicit list(size_type count, const Allocator& alloc = Allocator());
	template <class InputIt>
	list(InputIt first, InputIt last, const Allocator& alloc = Allocator());
	list(const list& other);
	list(const list& other, const Allocator& alloc);
	list(list&& other, const Allocator& alloc);
	list(std::initializer_list<T> init,
	     const Allocator& alloc = Allocator());

	// destructor
	~list();

	// operator=
	list& operator=(const list& other);
	list& operator=(list&& other);
	// since c++17
	// list& operator=(list&&other) noexcept();
	list& operator=(std::initializer_list<T> ilist);

	// assign
	void assign(size_type count, const T& value);
	template <class InputIt>
	void assign(InputIt first, InputIt last);
	void assign(std::initializer_list<T> ilist);

	// get_allocator
	allocator_type get_allocator() const;

	// Element Access
	// front
	reference front();
	const_reference front() const;

	// back
	reference back();
	const_reference back() const;

	// Iterators
	// begin, cbegin
	iterator begin();
	iterator begin() noexcept;
	const_iterator begin() const;
	const_iterator begin() const noexcept;
	const_iterator cbegin() const noexcept;

	// end, cend
	iterator end();
	iterator end() noexcept;
	const_iterator end() const;
	const_iterator end() const noexcept;
	const_iterator cend() const noexcept;

	// rbegin, crbegin
	reverse_iterator rbegin();
	reverse_iterator rbegin() noexcept;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rbegin() const noexcept;
	const_reverse_iterator crbegin() const noexcept;

	// rend, crend
	reverse_iterator rend();
	reverse_iterator rend() noexcept;
	const_reverse_iterator rend() const;
	const_reverse_iterator rend() const noexcept;
	const_reverse_iterator crend() const noexcept;

	// Capacity
	// empty
	bool empty() const;
	bool empty() const noexcept;

	// size
	size_type size() const;
	size_type size() const noexcept;

	// max_size
	size_type max_size() const;
	size_type max_size() const noexcept;

	// Modifiers
	// clear
	void clear();
	void clear() noexcept;

	// insert
	iterator insert(iterator pos, const T& value);
	iterator insert(const_iterator pos, const T& value);
	iterator insert(const_iterator pos, T&& value);
	void insert(iterator pos, size_type count, const T& value);
	iterator insert(const_iterator pos, size_type count, const T& value);
	template <class InputIt>
	void insert(iterator pos, InputIt first, InputIt last);
	template <class InputIt>
	iterator insert(const_iterator pos, InputIt first, InputIt last);
	iterator insert(const_iterator pos, std::initializer_list<T> ilist);

	// emplace
	template <class... Args>
	iterator emplace(const_iterator pos, Args&&... args);

	// erase
	iterator erase(iterator pos);
	iterator erase(const_iterator pos);
	iterator erase(iterator first, iterator last);
	iterator erase(const_iterator first, const_iterator last);

	// push_back
	void push_back(const T& value);
	void push_back(T&& value);

	// emplace_back
	template <class... Args>
	void emplace_back(Args&&... args);
	// since c++17
	// template <class... Args>
	// reference emplace_back(Args&&... args);

	// pop_back
	void pop_back();

	// push_front
	void push_front(const T& value);
	void push_front(T&& value);

	// emplace_front
	template <class... Args>
	void emplace_front(Args&&... args);
	// since c++17
	// template <class... Args>
	// reference emplace_front(Args&&... args);

	// pop_front
	void pop_front();

	// resize
	void resize(size_type count, T value = T());
	void resize(size_type count);
	void resize(size_type count, const value_type& value);

	// swap
	void swap(list& other);
	// since c++17
	// void swap(list& other) noexcept;

	// Operations
	// merge
	void merge(list& other);
	void merge(list&& other);
	template <class Compare>
	void merge(list& other, Compare comp);
	template <class Compare>
	void merge(list&& other, Compare comp);

	// splice
	void splice(const_iterator pos, list& other);
	void splice(const_iterator pos, list&& other);
	void splice(const_iteraotr pos, list& other, const_iterator it);
	void splice(const_iterator pos, list&& other, const_iterator it);
	void splice(const_iterator pos,
		    list& other,
		    const_iterator first,
		    const_iterator last);
	void splice(const_iterator pos,
		    list&& other,
		    const_iterator first,
		    const_iterator last);

	// remove, remove if
	void remove(const T& value);
	// since c++20
	// size_type remove(const T& value);
	template <class UnaryPredicate>
	void remove_if(UnaryPredicate p);
	// since c++20
	// template <class UnaryPredicate>
	// size_type remove_if(UnaryPredicate p);

	// reverse
	void reverse();
	void reverse() noexcept;

	// unique
	void unique();
	// since c++20
	// size_type unique();
	template <class BinaryPredicate>
	void unique(BinaryPredicate p);
	// since c++20
	// template <class BinaryPredicate>
	// size_type unique(BinaryPredicate p);

	// sort
	void sort();
	template <class Compare>
	void sort(Compare comp);

	// Non-member functions
	// operator==,!=,<,<=,>,>=
	template <class T, class Alloc>
	bool operator==(const std::list<T, Alloc>& lhs,
			const std::list<T, Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!=(const std::list<T, Alloc>& lhs,
			const std::list<T, Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<(const std::list<T, Alloc>& lhs,
		       const std::list<T, Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<=(const std::list<T, Alloc>& lhs,
			const std::list<T, Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>(const std::list<T, Alloc>& lhs,
		       const std::list<T, Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>=(const std::list<T, Alloc>& lhs,
			const std::list<T, Alloc>& rhs);

	// swap
	template <class T, class Alloc>
	void swap(list<T, Alloc>& lhs, list<T, Alloc>& rhs);
	// since c++17
	// template <class T, class Alloc>
	// void swap(list<T, Alloc>& lhs, list<T, Alloc>& rhs) noexcept();

	// erase(list), erase_if(list)
	// since c++20
	// template <class T, class Alloc, class U>
	// void erase(std::list<T, Alloc>& c, const U& value);
	// template <class T, class Alloc, class Pred>
	// void erase_if(std::list<T, Alloc>& c, Pred pred);
};
