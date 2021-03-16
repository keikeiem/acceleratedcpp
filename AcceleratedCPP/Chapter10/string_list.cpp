#include "string_list.h"

StringList::StringList(void)
	: m_size(1)
	, m_used(0)
{
	m_array = new std::string[m_size];
}

StringList::StringList(int size)
	: m_size(size)
	, m_used(0)
{
	m_array = new std::string[m_size];
}

StringList::~StringList() {
	delete[] m_array;
}

void StringList::PopBack() {
	if (m_used == 0) return;

	m_used--;
	std::cout << m_size << std::endl;
	std::string* temp = new std::string[m_used];

	for (int i = 0; i < m_used; ++i)
	{
		temp[i] = m_array[i];
	}

	delete[] m_array;
	m_array = new std::string[m_size];

	for (int i = 0; i < m_used; ++i)
	{
		m_array[i] = temp[i];
	}
	delete[] temp;
	return;
}

void StringList::PushBack(const std::string& set) {
	if (m_size > m_used)
	{
		m_array[m_used] = set;
		m_used++;
		return;
	}

	std::string* temp = new std::string[m_size];

	for (int i = 0; i < m_used; ++i)
	{
		temp[i] = m_array[i];
	}

	delete[] m_array;

	m_size *= 2;
	m_array = new std::string[m_size];

	for (int i = 0; i < m_used; ++i)
	{
		m_array[i] = temp[i];
	}
	m_array[m_used] = set;
	m_used++;

	delete[] temp;
	return;
}

void StringList::Print(void) {
	for (int i = 0; i < m_used; i++)
	{
		std::cout << m_array[i] << std::endl;
	}
}

std::string& StringList::operator[](int index)
{
    return m_array[index];
}

StringList::iterator StringList::begin(void) {
	return (m_array);
}

StringList::iterator StringList::end(void) {
	return (m_array + m_used);
}