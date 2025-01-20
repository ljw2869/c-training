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
	// string s1, addr;
	// cin >> s1;
	// cin.ignore(); //엔터키를 없애기 위해 필요 -버퍼에 있는 것을 없애기 위함
	// //cin은 버퍼를 통해서 입력이 됨 문자열을 받고 엔터를 치면 다음 문자열에 엔터가 포함되게 된다 그래서 주소 값을 받을 수 없음
	// cout << "주소를 입력하십시오";
	// getline(cin, addr);//한줄 전체를 입력 받아서 addr에 넣으라는 의미
	// cout << addr << "의 " << s1 << "씨 안녕하세요?" << endl;
	// //string 클래스 멤버함수 사용
	// //s[i] i번째 원소, s.empty()s가 비어있으면 true반환, 
	// // s.insert(pos,s2) pos위치에 s2를 삽입, s.remove(pos,len) s의 pos위치에 len만큼을 삭제
	// // s.find(s2) s에서 문자열 s2가 발견되는 첫번째 인덱스를 반환
	// // s.find(pos,s2) s의 pos위치부터 문자열 s2가 발견되는 첫번째 인덱스를 반환
	// string ss = "When in Rome, do as the Romans.";

	// int index = ss.find("Rome");
	// cout << index << endl;

	// //주민등록 번호를 입력해서 -가 제거된 주민등록번호를 출력하는 프로그램
	// string num;
	// cout<<"주민등록번호를 입력하세요.";
	// cin>>num;
	// cout<<"-가 제거된 주민등록번호"<<endl;
	// for (auto&c:num) //auto를 씀으로써 자료형을 알아서 설정해 줄 수 있다. 참조를 쓰면 변수의 값을 변화시킬 수 있음
	// {
	// 	if (c=='-') continue; //한 문자씩 출력하면서 -가 있으면 출력하지 않고 넘어감
	// 	cout<<c; 
	// }
	// cout<<endl;


	// //문자열의 배열
	// string list[]={"철수","영희","길동"};
	// for (auto &x:list)
	// 	cout<<(x+"야 안녕!")<<endl;
	

	//lab 해밍 거리 구하기
	// string s1,s2;
	// int count=0;

	// cout<<"DNA1";
	// cin>>s1;
	// cout<<"DNA2";
	// cin>>s2;

	// if (s1.length()!=s2.length())
	// 	cout<<"오류: 길이가 다름"<<endl;
	// else{
	// 	for (int i=0;i<s1.length();i++)
	// 	{
	// 		if (s1[i]!=s2[i])
	// 			count++;
	// 	}
	// 	cout<<"해밍 거리는 "<<count<<endl;
	// }

	//행맨
	char ch;
	string sol;
	string list[]={"the","c++","programming","language"};
	int n=rand()%4;
	sol=list[n];
	string guess(sol.length(), '_'); //sol의 길이만큼 _로 채워지는 문자열이 생성되어 guess안에 넣어줌
	cout<<"글자를 입력하시오"<<endl;
	cin>>ch;
	while(true){
		for(int i=0;i<sol.length();i++)
		{
			if (ch==sol[i])
				guess[i]=ch;
		}
		if (sol==guess){
			cout<<sol<<endl;
			cout<<"성공하였습니다.";
			break;
		}
	}
	//새롭게 배운 점: 함수의 오버로딩에서 add(int a,int b)와 add(float a,float b)가 있을 때 add(1.2,3)이렇게 넣으면 float으로 호출이 된다!!!

	return 0;

}
