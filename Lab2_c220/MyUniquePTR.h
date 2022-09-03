#pragma once
#include"MyString.h"
#include<vector>
template<typename T>
class MyUniquePTR
{
private:
	 T* m_data;
public:
	MyUniquePTR(T* data):m_data(data){}
	/*MyUniquePTR(T* data) 
	{
		m_data = std::move(data);
	}*/
	//MyUniquePTR(std::vector< MyUniquePTR< T >> data) :m_data(data) {}
	
	MyUniquePTR(const MyUniquePTR<T>& other)noexcept = delete;

	MyUniquePTR& operator = (const MyUniquePTR& other) = delete;

	MyUniquePTR(MyUniquePTR<T>&& other)noexcept 
	{
		m_data  = std::move(other.m_data);
		other.m_data = nullptr;
	}
	/*MyUniquePTR(std::vector< MyUniquePTR< T >>&& other)noexcept
	{
		m_data = std::move(other.m_data);
		other.m_data = nullptr;
	}*/

	MyUniquePTR& operator=(MyUniquePTR&& other)
	{
		if (&other == this)
			return *this;

		delete m_data;

		m_data = std::move(other.m_data);
		other.m_data = nullptr; 

		return *this;
	}
	T& operator* ()   ///->  operator bool
	{
		return *m_data;
	}
	T* operator-> ()
	{
		return m_data;
	}

	~MyUniquePTR(){
		delete m_data;
	}

};


