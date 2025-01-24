#include <iostream>
#include <cstring>

using namespace std;

class MyString{
    private:
        char *s;
        int size;
    public:
        MyString(const char *c){
            size=strlen(c)+1;
            s = new char[size];//동적 할당
            strcpy(s,c);
        }
        ~MyString(){ //앞에 틸드를 붙이고 클래스 명과 동일한 함수는 소멸자
            delete[] s;//동적으로 할당한 메모리를 제거
        }
        //소멸자도 자동으로 알아서 호출이 됨
};

class Circle{
    public:
        int radius;
        Circle();
        Circle(int r);
        ~Circle();
        double getArea();
};

Circle::Circle(){
    radius=1;
    cout<<"반지름 :"<<radius<<" 원 생성"<<endl;
}

Circle::Circle(int r){
    radius=r;
    cout<<"반지름 :"<<radius<<" 원 생성"<<endl;
}

Circle::~Circle(){
    cout<<"반지름 "<<radius<<" 원 소멸"<<endl;
}

double Circle::getArea(){
    return 3.14*radius*radius;
}

Circle globalDonut(1000);//전역 객체 생성
Circle globalPizza(2000);

void f(){
    Circle fDonut(100);//지역 객체 생성
    Circle fPizza(200);
}

int main()
{
    MyString str("abcdefghijk");
    
    Circle mainDonut;
    Circle mainPizza(30);//지역 객체 생성
    f();
    // 소멸 출력을 통해 역순으로 소멸이 된 것을 확인할 수 있음
    //adder클래스와 calculator클래스를 따로 만들어서 총 5개의 파일로 덧셈을 수행하는 계산기를 만들 수 있다!!
    //(12:20)
    return 0;
}