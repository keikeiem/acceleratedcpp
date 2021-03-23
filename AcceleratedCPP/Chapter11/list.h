#ifndef MY_LIST_H
#define MY_LIST_H

#include <memory>

template <class T>
class List {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

public:
	List() { create(); }
	explicit List(size_type n, const T& val = T()) { create(n, val); }
	List(const List& s) { create(s.begin(), s.end()); }
	List(const_iterator b, const_iterator e) { create(b, e); }
	~List(void) { uncreate(); }

	List<T>& operator=(const List<T>& rhs);
	size_type size() const {
		return (avail - data);
	}
	T& operator[](size_type i) {
		return data[i];
	}
	const T& operator[] (size_type i) const {
		return data[i];
	}

	void push_back(const T& val) {
		// 더이상 넣을 공간이 없는 경우
		if (avail == limit)
		{
			grow();
		}
		unchecked_append(val);
	}

	iterator erase(iterator pos);

	void clear(void);
	bool empty(void) const;

	iterator begin() { return data; }
	iterator end() { return avail; }
	const_iterator begin() const { return data; }
	const_iterator end() const { return avail; }

	iterator end_limit() { return limit; }

private:
	iterator data;
	iterator avail;
	iterator limit;

	std::allocator<T> alloc;

private:
	void create(void);
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	void uncreate(void);

	void grow(void);
	void unchecked_append(const T&);
};

// public
template <class T>
List<T>& List<T>::operator=(const List<T>& rhs)
{
	if (&rhs != this)
	{
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return (*this);
}

template <class T>
typename List<T>::iterator List<T>::erase(List<T>::iterator pos)
{
	if (data && pos != avail)
	{
		alloc.destroy(pos);
		iterator it = (pos + 1);
		while (it != avail)
		{
			alloc.construct(pos++, *(it++));
			alloc.destroy(pos);
		}
		avail = pos;
	}
	return avail;
}

template <class T>
void List<T>::clear(void)
{
	if (data)
	{
		iterator it = avail;
		while (it != data)
		{
			alloc.destroy(--it);
		}
		avail = data;
	}
}

template <class T>
bool List<T>::empty(void) const
{
	if (data)
	{
		return ((avail - data) == 0);
	}
	return (true);
}


// private
template <class T>
void List<T>::create(void)
{
	data = avail = limit = 0;
}

template <class T>
void List<T>::create(List::size_type n, const T& val)
{
	// n개의 요소를 초기값 t로 넣는 것
	data = alloc.allocate(n);
	limit = avail = data + n;
	// 초기화되지 않은 것에다가 val을 채워넣는것
	std::uninitialized_fill(data, limit, val);
}

template <class T>
void List<T>::create(List::const_iterator i, List::const_iterator j)
{
	data = alloc.allocate((j - i));
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void List<T>::uncreate(void)
{
	if (data)
	{
		iterator it = avail;
		while (it != data)
		{
			alloc.destroy(--it);
		}
		alloc.deallocate(data, limit - data);
	}
	data = avail = limit = 0;
}

template <class T>
void List<T>::grow(void)
{
	size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
	// 최소 1개를 늘리거나 현재 크기의 2배로 늘린다

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <class T>
void List<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}

#endif