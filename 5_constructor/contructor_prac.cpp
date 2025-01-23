#include<iostream>
using namespace std;

class Time
{
    public:
        int hour;//0~23
        int minute;//0~59

        // Time()
        // {
        //     hour=0;
        //     minute=0;
        // }
        //위의 긴 코드를 디폴트 매개변수를 이용해서 간결화
        // Time(int h = 0, int m = 0) //이게 생성자임
        // {
        //     hour=h;
        //     minute=m;
        // }

        void print()
        {
            cout<<hour<<":"<<minute<<endl;
        }
        
        //{}안에서 삽입하여 초기화하는 것을 ":"로 초기화 리스트를 사용하여 
        Time(int h = 0 ,int m = 0):hour{h},minute{m} //minute(m)으로 작성해도 되지만 옛날 방식
        {

        }
};

// 아래와 같이 밖에서 선언해주어도 되는데, 여기서 생성자는 리턴타입이 없기 때문에 바로 Time::이렇게 적어주면 된다.
// Time::Time(int h,int min){

// }


class Circle{
    public:
        int radius;
        Circle();
        Circle(int r);
        double getArea();
};

// Circle::Circle(){
//     radius=1;
//     cout<<"반지금 "<<radius<<" 원 생성"<<endl;
// }

// Circle::Circle(int r){
//     radius=r;
//     cout<<"반지금 "<<radius<<" 원 생성"<<endl;
// }
//위의 두 생성자는 매개변수 개수말고는 기능이 완전 같다. 그럴 때 위임 생성자를 사용하면 됨 

Circle::Circle():Circle(1){}//위임 생성자 -아래의 생성자를 호출하게 된다
Circle::Circle(int r){//타겟 생성자
    radius=r;
    cout<<"반지금 "<<radius<<" 원 생성"<<endl;
}

double Circle::getArea()
{
    return 3.14*radius*radius;
}

class Point{
    int x,y; //private이라고 안 적어도 public안에 안 들어가면 private으로 간주한다
    public:
    Point();
    Point(int a,int b);
};

// Point::Point(){x=0;y=0;}
// Point::Point(int a,int b){x=a;y=b;}
//위의 코드를 아래와 같이 위임생성자와 타겟생성자를 이용해서 작성할 수 있음

Point::Point():Point(x=0,y=0){}// 위임 생성자
Point::Point(int a,int b):x(a),y(b){} // 타겟 생성자
// 위에서 초기화 리스트:를 사용하여 더 간결해졌다.

class Rectangle{
    public:
        int width,height;

        Rectangle();
        Rectangle(int w,int h);
        Rectangle(int length);
        bool isSquare();
};

Rectangle::Rectangle()
{
    width=height=1;
}
Rectangle::Rectangle(int w,int h):width{w},height{h}{}
Rectangle::Rectangle(int length)
{
    width = height = length;
}
bool Rectangle::isSquare()
{
    if (width==height) return true;
    else return false;
}

int main()
{
    //생성자를 호출하는 방법
    Time a; 
    Time b(10,25);
    Time c{10,25};
    Time d={10,25};

    a.print();
    b.print();

    //class Circle예제
    Circle donut;
    double area=donut.getArea();
    cout<<"donut 면적은 "<<area<<"입니다"<<endl;

    Circle pizza(30);
    double ar=pizza.getArea();
    cout<<"pizza 면적은 "<<ar<<"입니다"<<endl;

    Rectangle r1;
    Rectangle r2(3,5);
    Rectangle r3(3);

    if (r1.isSquare()) cout<<"r1은 정사각형이다"<<endl;
    if (r2.isSquare()) cout<<"r2은 정사각형이다"<<endl;
    if (r3.isSquare()) cout<<"r3은 정사각형이다"<<endl;
    return 0; 
}