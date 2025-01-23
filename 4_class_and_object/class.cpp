#include<iostream>
using namespace std;

class Circle{
    public:
        int radius;
        string color;

        double calcArea();
};
//클래스 선언과 클래스 구현 분리-클래스를 다른 파일에서 활용하기 위해서
//함수의 리턴타입- 클래스 이름::(범위지정 연산자)-멤버함수명과 매개변수
double Circle::calcArea()
{
    return 3.14*radius*radius;
}

class Rectangle{
    public:
        int width,height;
        int calcArea()
        {
            return width*height;
        }
        //선언 안에 정의되어 있는 함수는 인라인 함수!(inline function!)
};

class Car
{
    public:
    //멤버 변수 선언
        int speed;
        int gear;
        string color;

        //멤버 함수 선언
        void speedUp()
        {
            speed+=10;
        }
        void speedDown()
        {
            speed-=10;
        }
};//꼭 세미콜론으로 닫아주어야 한다!

//오버라이딩
class PrintData{//멤버 함수 중복 정의 
    public:
        void print(int i){cout<<i<<endl;}
        void print(double d){cout<<d<<endl;}
        void print(string s="No Data!"){cout<<s<<endl;}
};

//클래스의 인터페이스와 구현의 분리

int main()
{
    Circle obj; //여러 개의 객체를 생성할 수 있으며, 객체마다 메모리를 따로 할당 받는다.
    obj.radius=100;
    obj.color="blue";

    cout<<"원의 면적 ="<<obj.calcArea()<<endl;

    //myCar
    Car myCar;

    myCar.speed=100;
    myCar.gear=3;
    myCar.color="red";

    myCar.speedUp();
    myCar.speedDown();

    //PrintData
    PrintData pd;

    pd.print(1);
    pd.print(3.14);
    pd.print("C++14 is cool.");
    pd.print();//아무것도 안 주면 디폴트 인자가 가능한 no data가 출력 확인

    return 0;
} 