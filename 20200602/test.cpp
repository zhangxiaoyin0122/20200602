#include <iostream>
#include <string>
#include <vector>
using namespace std;
//void Swap(int& left, int& right) {
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//void Swap(double& left, double& right) {
//	double tmp = left;
//	left = right;
//	right = tmp;
//}
//void Swap(char& left, char& right) {
//	char tmp = left;
//	left = right;
//	right = tmp;
//}
//template<typename T1,typename T2,.....typename Tn>
//返回值类型 函数名(参数列表){}
//template <class T>
//void Swap(T& left, T& right) {
//	T tmp = left;
//	left = right;
//	right = left;
//}

template<class T>
T add(const T& left,const T& right) {
	return left + right;
}
void test2() {
	int a = 1, b = 2;
	char c = 'X', d = 'Y';
	//隐式实例化
	add(a, b);
	add(c, d);
	//类型不同,需要显式实例化
	//add(a, c);//编译不通过
	add<int>(a, c);
}
//void test() {
//	string str;
//	string str1("abcde");
//	string str2 = "fghijk";
//	string str3(str2);
//	cout << str << endl;
//	cout << str1 << endl;
//	cout << str2 << endl;
//	cout << str3 << endl;
//	//cout << str << endl;
//}
template<class T1, class T2,class T3>
class Date {
public:
	Date(T1 year,T2 month,T3 day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	void Display();//类内声明
private:
	T1 _year;
	T2 _month;
	T3 _day;
};
//如果在类外定义类模板的成员函数，需要加上泛型的声明
//作用域为 "类名<泛型参数>"
template<class T1, class T2, class T3>
void Date<T1, T2, T3>::Display() {
	cout << _year << "-" << _month << "-" << _day << endl;
}
void test3() {
	//类模板不进行隐式类型转换
	//Date d(2020,6,2);

	//类模板
	//类型与类名不同
	//类型: 类名<泛型参数>
	Date<int, int, int> d(2020, 6, 2);
	d.Display();
}
class Solution {
public:
	int firstUniqChar(string s) {
		int count[26] = { 0 };
		for (const auto& ch : s) {
			count[ch - 'a']++;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (count[s[i] - 'a'] == 1)
				return i;
		}
		return -1;
	}
};

int main() {
	test2();
	system("pause");
	return 0;
}