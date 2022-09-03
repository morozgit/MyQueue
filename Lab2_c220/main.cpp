#include"MyVector.h"
#include"MyString.h"
#include"MyUniquePTR.h"
#include"MyQueue .h"
#include<list>


int main()
{

	MyVector<int> mv1({ 9, 10, 11, 12, 13, 13, 14, 15, 16, 17, 18, 19 },10,15);

	mv1.MyPushBack({ 29, 210, 211, 212, 213, 213, 214, 215, 216, 217, 218, 219 },211,218);

	mv1.MyPoPBack({ 13,14 });

	struct myclass {
		bool operator() (int i, int j) { return (i > j); }
	} myobject;
	struct myclass1 {
		bool operator() (int i, int j) { return (i < j); }
	} myobject1;
	mv1.MySort(myobject1);
	
	MyQueue<MyString>  q1{ MyString("AAA"), MyString("qwerty")};
	
	for(const auto& el : q1)
	{ 
		std::cout << el << ' '; 
	} // range-based for
	MyString s("abc");
	q1.push(s);
	q1.push(MyString("123")); // rvaluepushMyStrings1
	MyString s1 = q1.pop();
	q1.push("qqq");
	MyQueue < MyString >  q2 = q1;
	MyQueue < MyString >  q22 = std::move(q1);

	MyQueue < MyString >  q3{ 10, MyString("!")}; //очередь должна содержать 10 элементов со строкой «!» 
	q1 = q3;
	q2 = MyQueue < MyString >(5, MyString("?"));
	q1 = { MyString("bbb"), MyString("ssss")};

	

	MyUniquePTR<MyString> p1(new MyString("abc"));
	
	std::cout << p1->GetString();
	p1->SetNewString("qwerty");
	std::cout << p1->GetString();
	MyString  s2 = *p1;
	MyUniquePTR< MyString > p2 = std::move(p1); //здесь компилятор должен выдавать ошибку => 

	if (&p1) { std::cout << "No object!"; } //а это должно работать
	MyUniquePTR< MyString > p3(new MyString("vvv"));
	//p3 = p2; //и здесь компилятор должен выдавать ошибку
	std::vector< MyUniquePTR< MyString >> v;//как проинициализировать???
	v.push_back( std::move(new MyString("abc"))); 
	v.push_back(std::move(new MyString("qwerty")));
	v.push_back(std::move(new MyString("water")));
	
	std::list< MyUniquePTR< MyString >> l;
	//как скопировать из v в l ???
	std::move(v.begin(), v.end(), std::inserter(l,l.begin()));
	
	
	
	
	return 0;
}