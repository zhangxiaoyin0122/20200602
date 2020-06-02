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
//����ֵ���� ������(�����б�){}
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
	//��ʽʵ����
	add(a, b);
	add(c, d);
	//���Ͳ�ͬ,��Ҫ��ʽʵ����
	//add(a, c);//���벻ͨ��
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
	void Display();//��������
private:
	T1 _year;
	T2 _month;
	T3 _day;
};
//��������ⶨ����ģ��ĳ�Ա��������Ҫ���Ϸ��͵�����
//������Ϊ "����<���Ͳ���>"
template<class T1, class T2, class T3>
void Date<T1, T2, T3>::Display() {
	cout << _year << "-" << _month << "-" << _day << endl;
}
void test3() {
	//��ģ�岻������ʽ����ת��
	//Date d(2020,6,2);

	//��ģ��
	//������������ͬ
	//����: ����<���Ͳ���>
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