#pragma once
#include"MyString.h"


template<typename T>
class MyQueue
{
private:
	T* m_p{}; //указатель на начало динамического массива
	size_t m_size{}; //актуальное количество элементов в очереди
	size_t m_cap{ 1 }; //емкость (сколько выделено памяти)
	const size_t delta = 1; //на сколько увеличиваем емкость при перераспределении памяти
	size_t m_begin{}; //индекс первого элемента в очереди (это тот элемент, который можно извлечь из очереди с помощью pop())
	size_t m_end{}; // индекс первого свободного элемента в очереди (это тот элемент, в который можно присвоить новое значение с помощью push())
	class iterator
	{
	private:
		
		const MyQueue* m_pq;
		int m_i;
	public:
		iterator()
		{
			m_pq = nullptr;
			m_i = 0;
		}
		iterator(const MyQueue* pq, int l)
		{
			m_pq = pq;
			m_i = l;
		}
		
		
		iterator& operator++ ()
		{
			m_i = (m_i + 1) % m_pq->m_cap;
			return *this;
		}
		T& operator* ()
		{
			return m_pq->m_p[m_i];
		}
		bool operator != (const iterator& other) const
		{
			
			return m_i != other.m_i;
		}
		//!=
		
	};
	
	
public:
	
	//MyQueue<T>() {}

	MyQueue(std::initializer_list<T> data)
	{
		
		m_p = new T[data.size()+1];
		for (auto& i : data)
		{

			m_p[m_end] = i;
			m_end++;
			m_size++;
		}
		m_cap = m_size + 1;
	}
	MyQueue(int dataSize, T data)
	{

		m_p = new T[dataSize + 1];
		for(int i = 0; i < dataSize; i++)
		{

			m_p[m_end] = data;
			m_end++;
			m_size++;
		}
		m_cap = m_size + 1;
	
	}

	MyQueue(const MyQueue& other)
	{

		m_size = other.m_size;
		m_cap = other.m_size + 1;
		m_p = new T[m_size + 1];
		for (int i = 0; i < m_size; i++) 
		{
			m_p[i] = other.m_p[(i + other.m_begin) % other.m_cap];
		}		
		m_end = m_size;
		m_begin = other.m_begin;

	}
	MyQueue& operator=(const MyQueue& other)
	{
		if (this != &other)
		{
			delete[] m_p;
			m_size = other.m_size;
			m_cap = other.m_size + 1;
			m_p = new T[m_size + 1];
			for (int i = 0; i < m_size; i++) {
				m_p[i] = other.m_p[i];
			}
			m_end = m_size;
			m_begin = other.m_begin;
		}
		return *this;
	}
	MyQueue(MyQueue&& other)
	{
		m_p = std::move(other.m_p);
		m_size = other.m_size;
		m_cap = other.m_size + 1;
		m_begin = other.m_begin;
		m_end = m_size;
		other.m_p = nullptr;
		other.m_size = 0;
		other.m_begin = 0;
	}
	
	MyQueue& operator=(MyQueue&& other)
	{
		if (this != &other)
		{
			delete[] m_p;
			m_p = std::move(other.m_p);
			m_size = other.m_size;
			m_cap = other.m_size + 1;
			m_begin = other.m_begin;
			m_end = m_size;
			other.m_p = nullptr;
			other.m_size = 0;
			other.m_begin = 0;
		}
		return *this;
	}

	iterator begin() const //итератор на начало очереди
	{
		
	
		return iterator(this,m_begin);
	}
	iterator end() const // итератор на конец очереди
	{ 
		
		return  iterator(this, m_end);
	}

	void push(const T& data)
	{
		if (m_size == m_cap - 1) {
			for (int i = 0; i < m_size; i++)
			{
				m_p[i] = m_p[(m_begin + i) % m_cap];
			}
		}
		m_p[m_end] = data;
		m_size++;
		m_end = (m_end + 1) % m_cap;
	}

	/*bool isempty() {

		return (q->m_begin < q->m_end) ?  true :  false;
	}*/

	T pop()
	{

		auto x = m_p[m_begin];
		m_begin++; 
		m_size--;
		return x;     
		
	}
};



