#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include <map>
#include<time.h>
#include<numeric>
//map<key,value> 键值对
using namespace std;

class replaceIF
{
public:
	bool operator()(int val) {  //谓词
		return val > 2;
	}
};

void PrintV(int val) {
	cout << val <<" ";
}
void test() {
	srand((unsigned int)time(NULL));
	//random_shuffle

	vector<int>v;
	for (int i = 0; i <15; i++)
	{
		v.push_back(i);
	}
	vector<int>v2;

	for (int i = 10; i < 20; i++)
	{
		v2.push_back(i);
	}

	for_each(v.begin(), v.end(), PrintV);
	cout << endl;

	//random_shuffle(v.begin(), v.end());
	////打乱后
	//for_each(v.begin(), v.end(), PrintV);
	//cout << endl;

	for_each(v2.begin(), v2.end(), PrintV);
	cout << endl;
	cout << "合并中..." << endl;
	vector<int>targetV;
	targetV.resize(v.size() + v2.size());
	merge(v.begin(), v.end(), v2.begin(), v2.end(), targetV.begin());
	cout << "成功" << endl;
	for_each(targetV.begin(), targetV.end(), PrintV);
	cout << endl;

	reverse(targetV.begin(), targetV.end());//algorithm
	cout << "反转成功" << endl;
	for_each(targetV.begin(), targetV.end(), PrintV);  //algorithm
	cout << endl;
	vector<int>v3;
	v3.resize(targetV.size());
	copy(targetV.begin(), targetV.end(), v3.begin());
	cout << "拷贝成功" << endl;
	for_each(v3.begin(), v3.end(), PrintV);  //algorithm
	cout << endl;
	vector<int>v4;
	v4 = v3;
	cout << "赋值成功" << endl;
	for_each(v4.begin(), v4.end(), PrintV);  //algorithm
	cout << endl;


	replace(v4.begin(), v4.end(), 14, 20);
	cout << "14修改成功" << endl;
	for_each(v4.begin(), v4.end(), PrintV);  //algorithm
	cout << endl;

	replace_if(v4.begin(), v4.end(), replaceIF(),30); //replaceIF //bool --谓词
	cout << "2修改成功" << endl;
	for_each(v4.begin(), v4.end(), PrintV);  //algorithm
	cout << endl;
	
	//include numeric
	cout << "v4总和" << endl;
	cout<<accumulate(v4.begin(), v4.end(), 0);

	vector<int>v5;
	v5.resize(min(v.size(), v2.size()));
	vector<int>::iterator itEnd = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v5.begin());
	cout << "交集确定成功" << endl;
	for_each(v5.begin(), itEnd, PrintV);  //algorithm
	cout << endl;
	int a = 10;
	int b = 20;
	if (a > b ? false:true) {  //三目运算符回顾
		cout <<" a < b";
	}
}
int main111() {
	test();
	return 0;
}
//void printV(vector<int> & v) {
//	for (vector<int>::iterator it = v.begin(); it !=v.end(); it++)
//	{
//		cout << *it<<" ";
//	}
//	cout << endl;
//}
//void printV2(int val) {
//	cout << val << endl;
//}
//void test() {
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(0);
//	v.push_back(3);
//
//	sort(v.begin(), v.end());
//	for_each(v.begin(), v.end(), printV2);
//	cout << "输出V---------" << endl;
//	printV(v);
//
//	sort(v.begin(), v.end(), greater<int>());
//	for_each(v.begin(), v.end(), printV2);
//
//	cout << "输出V---------" << endl;
//	printV(v);
//}
//int main() {
//	test();
//	return 0;
//}

//
//class Person
//{
//public:
//	Person(string name, int age) {
//		m_name = name;
//		m_age = age;
//	}
//
//	string m_name;
//	int m_age;
//};
//class greaterAge
//{
//public:
//
//	bool operator()(const Person & p ){
//		return p.m_age > 10;
//	}
//
//};
//
//
//void test() {
//	vector<Person>vp;
//
//	Person p1("卖21zdf", 123);
//	Person p2("耳温枪", 213);
//
//	vp.push_back(p1);
//	vp.push_back(p2);
//
//	vector<Person>::iterator it = find_if(vp.begin(), vp.end(), greaterAge() );
//	if (it==vp.end())
//	{
//		cout << "weizhaod" << endl;
//	}
//	else
//	{
//		cout << it->m_name<<it->m_age << endl;
//	}
//}
//int main() {
//	test();
//	return 0;
//}

//class compare
//{
//public:
//	bool operator()(int val) {
//		if (val>105)
//		{
//			return  true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//};
//bool compareV(int val) {
//	return val > 1;
//}
//
//void test() {
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//
//	vector<int>::iterator it = find_if(v.begin(), v.end(), compareV);
//	if (it==v.end())
//	{
//		cout << "未找到" << endl;
//	}
//	else
//	{
//		cout << *it << endl;
//	}
//}


//void test() {
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(2);
//
//	//find 返回一个迭代器
//	vector<int>::iterator it = find(v.begin(), v.end(), 1);
//
//	if (it==v.end())
//	{
//		cout << "未找到" << endl;
//	}
//	else {
//		cout << "找到：" << *it << endl;
//	}
//}
//
//class Person
//{
//public:
//	Person(string name, int age) {
//		m_name = name;
//		m_age = age;
//	}
//	bool operator==(const Person&p) {
//		if ( p.m_name==this->m_name && p.m_age==this->m_age )
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	string m_name;
//	int m_age;
//
//private:
//
//};
//
//void test1() {
//	Person p1("张飞", 18);
//	Person p2("关羽", 20);
//	Person p3("刘备", 21);
//
//	vector<Person>vp;
//	vp.push_back(p1);
//	vp.push_back(p2);
//	vp.push_back(p3);
//
//	Person pp("曹操", 18);
//	vector<Person>::iterator it = find(vp.begin(), vp.end(), pp);
//	if (it == vp.end())
//	{
//		cout << "未找到" << endl;
//	}
//	else
//	{
//		cout << "姓名："<<it->m_name << " 年龄：" << it->m_age << endl;
//	}
//
//
//
//}
//int main() {
//	test1();
//	return 0;
//}



//class compareMap
//{
//public:
//	bool operator()(int v1, int v2)const {
//		return v1 > v2;
//	}
//};
//
//void printMap(map<int,int, compareMap>& m) {
//	for  (map<int,int>::iterator it = m.begin(); it != m.end();it++)  
//	{
//		cout << (*it).first <<" ";
//		cout << (*it).second<<" " ;
//		cout << endl;
//	}
//	cout << endl;
//}
//void testMap() {
//
//	map<int, int, compareMap>M;
//	M.insert(pair<int, int>(2, 10));
//	M.insert(pair<int, int>(1, 20));
//	M.insert(pair<int, int>(4, 130));
//	M.insert(pair<int, int>(3, 210));
//	M.insert(make_pair(5, 1));   
//
//	printMap(M);
//	map<int, int>::iterator pos = M.find(4);
//	if (pos!=M.end())
//	{
//		cout << pos->second;
//	}
//	else
//	{
//		cout << "未找到" << endl;
//	}
//
//}
//
//int main() {
//	testMap();
//	return 0;
//}


////set//底层由二叉树实现 set不允许有重复数值，multiset允许
//using namespace std;
//
//class compareSet
//{
//public:
//	 bool operator()(const int &v1, const int& v2)const 
//	{
//		return v1 > v2;
//	}
//};
//
//
//void printSet(multiset<int>ms) {
//	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
//	{
//		cout << *it << endl;
//	}
//}
//void test() {
//	set<int>s;
//	pair<set<int>::iterator,bool>ret = s.insert(10);
//	if (ret.second)
//	{
//		cout << "1插入成功" << endl;
//	}
//	else
//	{
//		cout << "1插入失败" << endl;
//	}
//
//	ret = s.insert(10);
//	if (ret.second)
//	{
//		cout << "2插入成功" << endl;
//	}
//	{
//		cout << "2插入失败" << endl;
//	}
//	multiset<int>ms;
//	ms.insert(10);
//	ms.insert(10);
//	printSet(ms);
//}
//void learnPair() {
//	pair<string, int>p1("ls", 12);
//	cout << p1.first;
//	cout << p1.second;
//
//	pair<string, int>p2 = make_pair("lsp", 21);
//	cout << p2.first;
//	cout << p2.second;
//}
//
//void testSet() {
//
//	set<int,compareSet>s22;
//
//	s22.insert(11);
//	s22.insert(21);
//	s22.insert(12);
//
//	for (set<int,compareSet>::iterator it = s22.begin(); it != s22.end(); it++)
//	{
//		cout << *it << endl;
//	}
//}
//
//int main() {
//	testSet();
//	return 0;
//}

//set

//using namespace std;
//
//void printList(const list<int> &l2) {
//	for (list<int>::const_iterator it = l2.begin(); it != l2.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test() {
//	list<int>l1;
//	l1.push_back(1);
//	l1.push_back(2);
//	l1.push_back(3);
//	printList(l1);
//	list<int>l2(l1.begin(), l1.end());
//	printList(l2);
//	list<int>l3(l2);
//	printList(l3);
//	list<int>l4(10, 100);
//	printList(l4);
//	cout << "l4.size = " << l4.size() << endl;
//	
//	l4.swap(l1);
//	printList(l4);
//	cout << "l4.size = " << l4.size() << endl;
//	l4.resize(2);
//	cout << "l4.size = " << l4.size() << endl;
//	printList(l4);
//	l4.resize(10, 100);
//	cout << "l4.size = " << l4.size() << endl;
//	printList(l4);
//}
//
//int main() {
//	test();
//	return 0;
//}

//class person
//{
//public:
//	person(string name, int age) {
//		m_name = name;
//		m_age = age;
//	}
//	int m_age;
//	string m_name;
//};
//
//void test() {
//	queue<person>q;
//
//	person p1("发", 123);
//	person p2("s", 132);
//	q.push(p1);
//	q.push(p2);
//	while (!q.empty())
//	{
//		cout<<q.front().m_name << q.front().m_age << endl;
//		cout << q.back().m_name << q.back().m_age << endl;
//		q.pop();
//	}
//}
//int main() {
//	test();
//	return 0;
//}
////stack
//void test() {
//	
//	stack<int>s;
//	s.push(1);
//	s.push(13);
//	s.push(2);
//	s.push(42);
//	s.push(25);
//	//只要栈不为空查看栈顶，并出栈
//
//	while (!s.empty())
//	{
//		cout << "s.top:" << s.top() << endl;
//		cout << "s.size:" << s.size() << endl;
//		s.pop();
//	}
//}
//
//
//int main() {
//	test();
//	return 0;
//}


////deque 函数
//void printDeque(const deque<int>& d) { 
//	for (deque<int>::const_iterator it = d.begin(); it <d.end() ; it++)
//	{
//	
//		cout << *it<<" ";
//	}
//	cout << endl;
//}
//
//
//void test() {
//	deque<int>d1;
//	for (int i = 0; i < 10; i++)
//	{
//		d1.push_back(i);  
//		d1.push_front(-i);
//	}
//	deque<int>d2;
//	d2 = d1;
//	deque<int>d3;
//	d3.assign(d2.begin(),d2.end());
//	d3.assign(10, 100);
//}
//
//int main() {
//	test();
//	return 0;
//}

//void printVector(vector<int>&v) {
//	//for (vector<int>::iterator it= v.begin();it!=v.end();it++)
//	//{
//	//	cout << *it << " ";
//	//}  
//	//cout << endl;
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v.at(i) << endl;
//		//cout << v[i] << endl;
//		//cout << v.front()<<endl;
//		//cout << v.back()<<endl;
//	}
//
//}
//int main() {
//	
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	printVector(v1);
//	vector<int>v2;
//	v1.swap(v2);
//	printVector(v2);
//	return 0;
//}
//
//
//void test() {
//	string str1 = "俺";
//	str1 += "也一样";
//	cout << "str1:" << str1 << endl;
//
//	string str2 = "I";
//	str2.append(" Love 233333");
//	cout << "str2:" << str2 << endl;
//	string str3;
//	str3.append(str2, 7, 4);
//	cout << "str3:" << str3 << endl;
//	int pos = str3.rfind('3',2);
//	cout << "pos：" << pos << endl;
//
//
//}	
//
//void test02() {
//	string str123 = "NUAA";
//	string strb  = "buaa";
//	for (int i = 0; i < str123.size(); i++)
//	{
//		cout << str123[i] << " " << endl;
//		cout << str123.at(i) << endl;
//		str123[i] = strb[i];
//		cout << str123[i] << " " << endl;
//		str123.erase();
//	}
//}
//int main() {
//	test02();
//	return 0;
//}
//vector
//void test() {
//	vector<vector<int>>v;
//	vector<int>v1;
//	vector<int>v2;
//	vector<int>v3;
//	vector<int>v4;
//	for (int i = 0; i < 5; i++)
//	{
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//	}
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		for (vector<int>::iterator vt = (*it).begin(); vt !=(*it).end(); vt++)
//		{
//			cout << *vt<<" ";
//		}
//		cout << endl;
//	}
//	
//}
//int main() {
//	test();
//	return 0;
//}