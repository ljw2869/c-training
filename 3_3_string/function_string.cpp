#include<iostream>
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
int main()
{
    int a,b,max;
    cin>>a>>b;
    max=getMax(a,b);//함수 호출 -call by value
    swap(a,b);
    cout<<max<<endl;
    cout<<a<<","<<b<<endl;//여기서도 swap이 된 채로 출력이 된 것을 볼 수 있다.
    return 0;
}

int getMax(int a,int b)//함수 정의부분
{
    if(a>b)
        return a;
    else
        return b;
}