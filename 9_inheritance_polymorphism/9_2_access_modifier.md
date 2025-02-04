9.2 접근 지정자의 이해
========================
+ 생성자와 소멸자
    - 자식클래스 객체가 생성될 때 부모 클래스의 생성자도 호출이 된다.
    - 순서: 부모 생성자->자식 생성자->자식 소멸자->부모 소멸자

    ```cpp
    #include<iostream>
    using namespace std;
    class Shape{
        int x,y;
        public: 
            Shape(){
                cout<<"Constructor of Shape"<<endl;
            }
            ~Shape(){
                cout<<"Destructor of Shape"<<endl;
            }
    };

    class Rectangle: public Shape{
        int width, height;
        public:
            Rectangle(){
                cout<<"Constructor of Rectangle"<<endl;
            }
            ~Rectangle(){
                cout<<"Destructor of Rectangle"<<endl;
            }
    };
    int main()
    {
        Rectangle r;
        return 0;
    }
    ```

    실행결과
    > Constructor of Shape <br> Constructor of Rectangle <br> Destructor of Rectangle <br> Destructor of Shape

    - 자식 클래스의 생성자 호출 형식
        > 자식 클래스의 생성자(): 부모 클래스의 생성자(){ }
        ```cpp

        #include<iostream>
        using namespace std;

        class Shape{
            int x,y;
            public: 
                Shape(int x,int y){
                    this->x = x;
                    this->y = y;
                    cout<<"Constructor of Shape"<<endl;
                }
                ~Shape(){
                    cout<<"Destructor of Shape"<<endl;
                }
        };

        class Rectangle: public Shape{
            int width, height;
            public:
                // Rectangle(int x=0,int y=0, int w=0, int h=0):Shape(x,y){
                //     cout<<"Constructor of Rectangle"<<endl;
                //     width = w;
                //     height = h;
                // }
                Rectangle(int x=0,int y=0, int w=0, int h=0):Shape(x,y),width(w),height(h){ }
                ~Rectangle(){
                    cout<<"Destructor of Rectangle"<<endl;
                }
        };

        int main()
        {
            Rectangle r;
            return 0;
        }
        ```
    
#### 접근 지정자
|접근 지정자|자기 클래스|자식 클래스|외부|
|-----------|-----------|---------|-----|
|private|o|x|x|
|protected|o|o|x|
|public|o|o|o|

**위의 접근 지정자 관계를 잘 파악해두기**
##### protected 멤버
+ 선언된 클래스에서 접근 가능
+ 파생 클래스에서만 접근 허용
    - 파생 클래스가 아닌 다른 클래스나 외부 함수에서는 protected 멤버를 접근할 수 없다.

#### 멤버 함수 재정의
자식 클래스가 필요에 따라 상속된 멤버 함수를 재정의하여 사용할 수 있다.
사용 예시
```cpp
#include<iostream>
using namespace std;

class Animal{
    public:
    void speak(){
        cout<<"Grrrr"<<endl;
    }
};

class Dog:public Animal{
    public:
    void speak(){
        cout<<"Woof! Woof!"<<endl;
    }
};

int main()
{
    Dog dog;
    dog.speak();
    return 0;
}
```
**중복정의와 재정의 사이의 차이점을 잘 구별할 것!!**
+ 중복 정의는 같은 이름의 함수가 한 클래스 안에 들어가서 다른 매개변수 입력에 대해 대처하는 것임
+ 재정의는 상속받은 함수의 이름을 가져와서 자신의 클래스에 맞게 바꾸는 것을 의미

#### 부모 클래스를 상속받는 3가지 방법
| | public으로 상속|protected로 상속|private로 상속|
|-|----------------|----------------|-------------|
|부모 클래스의 public멤버|->public|->protected|->private|
|부모 클래스의 protected멤버|->protected|->protected|->private|
|부모 클래스의 private멤버|접근 안됨|접근 안됨|접근 안됨|

부모 클래스 상속 시 접근 지정자를 사용하여 위의 표와 같이 제한되는 예시 코드
```cpp
#include<iostream>
using namespace std;

class Base{
    public:
    int x;
    protected:
    int y;
    private:
    int z;
};

class Derived: private Base{
    // x 자식 클래스에서 사용가능하지만 private으로 상속받으면 private으로 변경됨
    // y 자식 클래스에서 사용가능하지만 private으로 상속받으면 private으로 변경됨
    // z is not accessible from Derived
};

int main()
{
    Derived d;
    //cout<<d.x; // x is not accessible from Derived
    return 0;
}
```

protected멤버에 대한 접근 예시
```cpp
#include<iostream>
using namespace std;

class Point{
    protected:
        int x, y;
    public:
        void set(int x,int y){
            this->x = x;
            this->y = y;
        }
        void showPoint();
};
void Point::showPoint(){
    cout<<"x = "<<x<<", y = "<<y<<endl;
}

class ColorPoint:public Point{
    string color;
    public:
        void setColor(string color){
            this->color = color;
        }
        void showColorPoint();
        bool equals(ColorPoint cp);
};

void ColorPoint::showColorPoint(){
    cout<<color<<": ";
    showPoint();//point클래스의 showPoint()호출
}
bool ColorPoint::equals(ColorPoint cp){
    if(x == cp.x && y == cp.y && color == cp.color)//protected멤버 x,y에 접근가능
        return true;
    else
        return false;
}

int main()
{
    Point p;
    p.set(2,3);
    // p.x = 5;//error -안 되는 이유는 x는 현재 main에서 접근하려고 하고 있기 때문이다.
    // p.y=5;//error
    p.showPoint();

    ColorPoint cp;
    // cp.x=10;//error-마찬가지로 main에서 접근하려고 하기 때문에 error가 남
    // cp.y=10;//error
    cp.set(3,4);
    cp.setColor("Red");
    cp.showColorPoint();

    ColorPoint cp2;
    cp2.set(3,4);
    cp2.setColor("Red");
    cout<<((cp.equals(cp2))?"true":"false")<<endl;
    return 0;
}
```

#### 다중 상속(multiple inheritance)
+ 하나의 자식 클래스가 두 개 이상의 부모 클래스로부터 멤버를 상속받는 것을 의미
```cpp
#include<iostream>
using namespace std;

class PassangerCar{
    public:
    int seats;
    void set_seats(int n){seats =n; }
};

class Truck{
    public:
    int payload;//적재 하중
    void set_payload(int n){payload = n;}
};

class Pickup:public PassangerCar, public Truck{
    public:
    int towing_capacity;//견인용량
    void set_towing_capacity(int n){towing_capacity = n;}
};

int main()
{
    Pickup my_car;
    my_car.set_seats(4);
    my_car.set_payload(2000);
    my_car.set_towing_capacity(5000);
    return 0;
}
```

#### 업 캐스팅(up-casting)
+ 파생 클래스 포인터가 기본 클래스 포인터에 치환되는 것
```cpp
int main()
{
    ColorPoint cp;
    ColorPoint*pDer=&cp; //객체 cp의 모든 public멤버(파생 클래스 멤버까지) 접근 가능
    Point*pBase=pDer;// 업캐스팅
    //pBase포인터로 기본 클래스의 public멤버만 접근 가능

    pDear->set(3,4);
    pBase->showPoint();
    pDer->setColor("Red");
    pDer->showColorPoint();
    pBase->showColorPoint();//이건 컴파일 오류
    return 0;
}
```
#### 다운 캐스팅(down-casting)
+ 기본 클래스의 포인터가 파생 클래스의 포인터에 치환되는 것
```cpp
int main()
{
    ColorPoint cp;
    ColorPoint*pDer=&cp; //객체 cp의 모든 public멤버(파생 클래스 멤버까지) 접근 가능
    Point*pBase=pDer;// 업캐스팅
    //pBase포인터로 기본 클래스의 public멤버만 접근 가능

    pDear->set(3,4);
    pBase->showPoint();

    pDer=(ColorPoint*)pBase;//다운 캐스팅
    pDer->setColor("Red");// 정상 컴파일
    pDer->showColorPoint();// 정상 컴파일
    return 0;
}
```

