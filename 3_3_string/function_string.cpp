#include<iostream>
#include<string>
//cstring 에는 getline을 정의하고 있지 않음 그래서 string으로 사용
using namespace std;
//함수의 프로토 타입-함수의 원형 정의
int getMax(int a,int b);
void swap(int &x,int &y) //참조형은 a와 b의 별칭이 되는 것이다.
//즉, 메모리를 따로 할당 받는 것이 아니라 같은 메모리를 쓰는 것이다.
{
    int t;
    t=x;
    x=y;
    y=t;
    cout<<x<<" "<<y<<endl; //여기서부터 교환된 게 보임
}


int funabs(int x)//이 함수만 있으면 b의 값이 -2.5->2로 출력이 되는 것을 확인할 수 있다.
{
    if (x<0)
        return -x;
    else
        return x;
}

float funabs(float x)
{
    if (x<0)
        return -x;
    
    return x;
}

// int sum(int a,int b)
// {
//     return a+b;
// } 
//위와 같이 오버로드로 두가지 기능을 다 수행하게 해도 되지만 그냥 c를 디폴트 인자로 주면 해결될 일이다.
inline int sum(int a,int b,int c=0)//c부분을 디폴트 인자라고 한다 default parameter
{
    return a+b+c;
}
//함수 앞에 inline을 붙여주면 위의 코드가 main에서 대치가 됨

int main()
{
    // int a,b,max;
    // cin>>a>>b;
    // max=getMax(a,b);//함수 호출 -call by value
    // swap(a,b);
    // cout<<max<<endl;
    // cout<<a<<","<<b<<endl;//여기서도 swap이 된 채로 출력이 된 것을 볼 수 있다.
    
    // //함수의 오버로드
    // int a=-1;
    // float b=-2.5;
    // a=funabs(a);
    // b=funabs(b);
    // cout<<a<<", "<<b<<endl;
    // return 0;

    // //디폴트 인자
    // int s=sum(10,20);
    // int s2=sum(10,20,30);
    // cout<<s<<", "<<s2<<endl;
    
    // //문자열 실습
    // string str="I like ";
    // string str2="me";
    // cout<<str+str2<<endl;
    // string s1,s2;
    // cin>>s1; //cin은 공백문자(엔터, 탭, 스페이스)를 만나면 거기까지 입력을 멈춤
    // //getline은 엔터까지 입력을 받는 것임-그래서 cin>>s1, getline(cin,s2)를 하면 엔터가 s2에 들어가게 된다
    // cin.ignore(); //이렇게 하면 입력 버퍼에 있는 내용을 다 읽어서 버려서 새로운 입력을 받을 수 있음
    // getline(cin,s2);
    // cout<<s1+s2<<endl;


    //문자열 찾기 find
    string str="I like love me";
    int index=str.find("l",3);
    cout<<index<<endl;
    //특정 위치 뒤에 있는 l을 찾고 싶을 때 (첫번째 l은 2번 인덱스에 있음)
    str.insert(1,"-");//1번 인덱스에 -기호를 삽입
    cout<<str<<endl;
    //str.remove(1,1);//1번 인덱스부터 1개만 지워라-다른 버전에서는 지원 가능
    cout<<str.length()<<endl;
}

int getMax(int a,int b)//함수 정의부분
{
    if(a>b)
        return a;
    else
        return b;
}