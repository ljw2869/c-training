#include <iostream>
#include<string> //string객체를 쓰기 위해 다음의 헤더를 가져와야 한다
using namespace std;

int main()
{

	//string객체를 이용해 문자를 다룬다
	//내부 구현을 몰라도 find()를 사용할 수 있음
	//클래스: 설계도, 붕어빵 틀, 객체: 제품, 붕어빵
	//string s; //string 객체 생성
	//string s = "Hello World!"; //string객체 생성 및 초기화
	//string s{ "Hello World!" }; //string 객체 생성 및 초기화


	string subject = "Money ";
	string other = "has no value if it is not used";
	string sentence = subject + other; //문자열에서 +는 이어주는 것이다.
	cout << sentence;

	//string s1 = "hello", s2 = "world";
	//if (s1 == s2)
	//	cout << "동일한 문자열입니다." << endl;
	//else
	//	cout << "동일한 문자열이 아닙니다." << endl;
	//if (s1 > s2)
	//	cout << "s1이 앞에 있습니다." << endl;
	//else
	//	cout << "s2가 앞에 있습니다." << endl;
	//// c++에서는 strcmp(s1,s2)==0이런 식으로 사용했으나 string객체를 사용하면 부등호로 아스키코드에 기반해 비교할 수 있다.
	//
	string s1, addr;
	cin >> s1;
	cin.ignore(); //엔터키를 없애기 위해 필요 -버퍼에 있는 것을 없애기 위함
	//cin은 버퍼를 통해서 입력이 됨 문자열을 받고 엔터를 치면 다음 문자열에 엔터가 포함되게 된다 그래서 주소 값을 받을 수 없음
	cout << "주소를 입력하십시오";
	getline(cin, addr);//한줄 전체를 입력 받아서 addr에 넣으라는 의미
	cout << addr << "의 " << s1 << "씨 안녕하세요?" << endl;
	return 0;

}
