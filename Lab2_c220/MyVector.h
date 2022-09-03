#pragma once
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

template<typename T>
class MyVector
{
private:
	std::vector<T> mv;
	T first{};
	T last{};

public:
	
	MyVector(std::initializer_list<T> data, int numfirst, int numlast):/*mv(data.size()),*/first(numfirst),last(numlast)
	{
		
		for (auto& x : data)
		{
			if (x > first && x < last && std::find(mv.begin(),mv.end(),x) == mv.end())
			{				 
				mv.push_back(x);
			}
		}
		//auto tmp = std::unique(mv.begin(), mv.end());
		//mv.erase(tmp, mv.end());
	}

	void MyPushBack(std::initializer_list<T> data, int numfirst, int numlast)
	{
		for (auto& x : data)
		{
			if (x > numfirst && x < numlast && std::find(mv.begin(), mv.end(), x) == mv.end())
			{
				mv.push_back(x);
			}
		}
		
	}

	void MyPoPBack(std::initializer_list<T> data)
	{
		for (auto& i : data)
		{
			auto it = find(mv.begin(), mv.end(), i);
			mv.erase(it);
		}
			
	}
	template<typename T>
	void MySort(T& l) 
	{
		std::sort(mv.begin(), mv.end(), l);
	}


	~MyVector() = default;
};

