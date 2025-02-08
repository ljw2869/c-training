9.5 다형성과 가상함수
======================
+ 객체 포인터
    - 객체의 주소값을 저장할 수 있는 포인터
    - 부모 클래스의 포인터는 부모 객체의 주소 뿐만 아니라 그 클래스를 상속하는 파생 클래스의 객체 주소 값도 저장 가능
    - 클래스의 참조자는 부모 객체 뿐 아니라 그 클래스를 상속하는 파생 클래스의 객체도 참조 가능

    권한
    - 포인터를 통해서 접근할 수 있는 객체 멤버의 영역
    - 부모 클래스의 객체 포인터는 부모 클래스의 멤버와, 상속받은 베이스 클래스(즉 자신의 영역)만 접근 가능
    - 부모 클래스의 참조자는 부모 클래스의 멤버와, 상속받은 베이스 클래스의 멤버만 접근 가능

    예시
    ```cpp
    class Person{
        ...
    };

    class Student: public Person{
        ...
    };
    
    class PartTimeStudent: public Student{
        ...
    };

    int main(){
        Person * ptr=new Student();
        Person * ptr=new ParTimeStudent();

        Student * ptr=new PartTimeStudent();
        //부모 클래스 객체를 가리키는 포인터가 상속받은 파생클래스를 가리키는 포인터가 될 수 있다.
        return 0;
    }
    ```
    정수형 포인터와 같은 경우는 무조건 정수형 변수만 가리킬 수 있었다면, 클래스는 조금 범위가 더 넓다!
    **cpp에서, A형 포인터 변수는 A객체 또는 A를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다.(객체의 주소 값을 저장할 수 있다.)** 
    > 자식 클래스 객체는 부모 클래스 객체를 포함하고 있기 때문에

+ 객체 포인터의 형변환
    - 상향 형변환(upcasting)
        * 자식 클래스 타입을 부모 클래스 타입으로 변환
    - 하향 형변환(dowoncasting)
        * 부모 클래스 타입을 자식 클래스 타입으로 변환

    - 상향 형변환의 예시
    ```cpp
    class Animal{
        public: 
            void speak(){cout<<"Animal speak()"<<endl;}
    };

    class Dog:public Animal{
        public:
            int age;
            void speak(){cout<<"왈왈"<<endl;}
    };
    class Cat:public Animal{
        public: 
            void speak(){cout<<"야옹"<<endl;}
    };
    int main(){
        Animal *a1=new Dog();
        a1->speak();
        Animal *a2=new Cat();
        a2->speak();
        //a1->age=10; //오류!
        return 0;
    }
    ```
    위의 출력 예시는 왈왈과 야옹이 아닌 부모 speak()함수가 실행된다.
    > **파생 클래스를 가리킬 수는 있지만 관장하는 영역은 기본 클래스 영역 밖에 없기 때문이다!!**

- 가상함수(virtual function)
    + 베이스 클래스 내에서 정의된 멤버함수를 파생클래스에서 재 정의하고자 할 때 사용
        * 베이스 클래스의 멤버함수와 같은 이름을 갖는 함수를 파생 클래스에서 재정의함으로써 각 클래스마다 고유의 기능을 갖도록 변경할 때 이용
        * 파생클래스에서 재정의되는 가상함수는 함수중복(overlaoding)과 달리 베이스클래스와 함수의 반환형, 인수의 개수와 형이 같아야 함
    + 가상함수를 정의하기 위해 가장 먼저 기술되는 베이스클래스의 멤버 함수 앞에 virtual 이라는 키워드로 기술
    ```cpp
    class Base{
        public:
            virtual void f();//f()는 가상함수
    };
    ```

    + virtual 의미
        * 동적 바인딩 지시어
        * 컴파일러에게 함수에 대한 호출 바인딩을 실행시간까지 미루도록 지시

    + 함수 오버라이딩(function overriding)
        * 파생 클래스에서 기본 클래스의 가상 함수와 **동일한 이름의 함수 선언** 
        
        * **기본 클래스의 가상함수의 존재감 상실시킴**
        * **파생 클래스에서 오버라이딩한 함수가 호출되도록 동적 바인딩**
        * 함수 재정의라고도 부름
        * 다형성의 한 종류

        * 함수 오버라이딩 되면, 오버라이딩 된 베이스 클래스의 함수는 오버라이딩을 한 파생클래스의 함수에 가려짐

        성공조건
        **가상함수 이름, 매개변수 타입과 개수, 리턴 타입이 모두 일치해야 함**
        ```cpp
        class Base{
            public:
            virtual void fail();
            virtual void success();
            virtual void g(int);
        };

        class Derived:public Base{
            public:
                virtual int fall();//오버라이딩 실패, 리턴타입이 다름
                virtual void success();//오버라이딩 성공
                virtual void g(int ,double);//오버로딩 사례, 정상 컴파일
        };
        ```

        * 오버라이딩 시 virtual 지시어 생략 가능
            + 가상 함수의 virtual 지시어는 상속됨, 파생 클래스에서 virtual 생략 가능
    
- 오버로딩, 함수 재정의, 오버라이딩 비교
    **베이스 클래스와 동일한 이름의 함수를 파생클래스에 정의한다고 해서 무조건 함수 오버라이딩이 되는 것은 아님**
    + 가상함수를 재정의하는 것을 오버라이딩 - 함수가 호출되는 실행시간에 동적 바인딩
    + 그렇지 않은 경우 컴파일 시간에 결정된 함수가 단순히 호출 - 정적 바인딩

    + 함수 오버로딩
        * 매개변수의 자료형 및 개수가 다를 경우
        * 전달되는 인자에 따라서 호출되는 함수가 결정
        * 함수 오버로딩은 상속의 관계에서도 구성가능

    |비교 요소|오버로딩|함수재정의(가상함수 아닌 멤버에 대해)|오버라이딩
    |---------|-------|----------------|-------------|
    |정의|매개변수 타입이나 개수가 다르지만, **이름이 같은 함수들이 중복 작성되는 것**| 기본 클래스의 멤버함수를 파생 클래스에서 이름, 매개 변수 타입과 개수, 리턴타입까지 **완벽히 같은 원형으로 재작성**| 기본 클래스의 가상함수를 파생클래스에서 이름, 매개변수타입과 개수, 리턴타입까지 **완벽히 같은 원형으로 재작성**|
    |존재|클래스의 멤버들 사이 외부함수들 사이, 기본 클래스와 파생클래스 사이에 존재 가능|상속관계|상속관계|
    |목적|이름이 같은 여러 개의 함수 중복 작성으로 **사용의 편의성**|기본 클래스의 멤버함수와 별도로 **파생 클래스에서 필요해 재작성**|**기본 클래스의 가상함수를 무시하고, 파생클래스에서 새로운 기능으로 재작성**|
    |바인딩|정적바인딩, 컴파일 시에 중복된 함수들의 호출 구분|정적바인딩, 컴파일 시에 함수의 호출 구분|**동적 바인딩**, 실행 시간에 오버라이딩된 함수를 찾아 실행|
    |객체 지향 특성|컴파일 시간 다형성|컴파일 시간 다형성|실행시간 다형성|

    - 함수 재정의와 오버라이딩 사례 비교
    ```cpp
    //다음은 함수 재정의(redefine)
    class Base{
        public:
        void f(){
            cout<<"base::f() called"<<endl;
        }
    };

    class Derived:public Base{
        public:
            void f(){
                cout<<"Derived::f() called"<<endl;
            }
    };
    ```
    이러면 derived객체에 void f()함수가 두 개 존재

     ```cpp
    //다음은 오버라이딩(overriding)
    class Base{
        public:
            virtual void f(){ //가상 함수
                cout<<"base::f() called"<<endl;
            }
    };

    class Derived:public Base{
        public:
            virtual void f(){ //여기서 virtual 생략 가능
                cout<<"Derived::f() called"<<endl;
            }
    };
    ```
    이렇게 생긴 derived 객체는 두 개의 void f()함수가 존재하지만, **base의 f()는 존재감을 잃고 항상 derived의 f()가 호출됨**

    ```cpp
    #include<iostream>
    using namespace std;

    class Base{
        public:
            virtual void f(){cout <<"Base::f"<<endl;}
    };

    class Derived : public Base{
        public:
            virtual void f() override{cout <<"Derived::f"<<endl;}
    };

    int main()
    {
        Derived d, *pDer;
        pDer=&d;
        pDer->f();//Derived::f호출

        Base *pBase;
        pBase=pDer;//upcasting
        pBase->f();//동적 바인딩 발생! Derived::f호출

        return 0;
    }
    ```

    오버라이딩 된 함수가 virtual이면 오버라이딩 한 함수도 자동 virtual

    ```cpp
    #include<iostream>
    using namespace std;

    class First{
        public:
            virtual void MyFunc(){
                cout<<"First Func"<<endl;
            }
    };

    class Second : public First{
        public:
            void MyFunc(){
                cout<<"Second Func"<<endl;
            }
    };

    class Third : public Second{
        public:
            void MyFunc(){
                cout<<"Third Func"<<endl;
            }
    };

    int main()
    {
        
        Third *tptr = new Third();
        Second *sptr = tptr;
        First *fptr = sptr;

        fptr->MyFunc();
        sptr->MyFunc();
        tptr->MyFunc();
        //fptr->d; //불가능: 겹치는 부분의 영역만 접근이 가능함

        delete tptr;
        return 0;
    }
    ```
    >Third Func<br> Third Func<br>Third Func

    핵심: **포인터 형의 상관 없이 포인터가 가리키는 객체의 마지막 오버라이딩 함수를 호출**

    비슷한 예시 코드
    ```cpp
    GrandDerived g;
    Base *bp;
    Derived *dp;
    GrandDerived *gp;

    bp=dp=gp=&g;
    bp->f();
    dp->f();
    gp->f();
    //위의 3가지 f()함수 호출은 모두 grandDerived의 f()함수를 호출한다.
    ```
--------------------------------------------------

9.6 다형성과 가상함수 2
============================
+ 순수 가상함수(pure virtual function)
    - 베이스 클래스에서는 어떤 동작도 정의되지 않고 함수의 선언만을 하는 가상 함수
    - 순수 가상함수를 선언하고 파생클래스에서 이 가상함수를 중복 정의하지 않으면 **컴파일 시 에러 발생**
    - 하나 이상의 멤버가 순수 가상 함수인 클래스를 **추상클래스(abstract class)**라고 함
        * 완성된 클래스가 아니기 때문에 객체화 되지 않는 클래스
    
    - 기본 클래스의 가상 함수 목적:
        * 파생 클래스에서 재정의할 함수를 알려주는 역할
        * 실행할 코드를 작성할 목적이 아님

        ```cpp 
        class Shape{
            public:
                virtual void draw()=0;// 순수 가상함수 선언 형식
        };
        ```

+ 추상 클래스의 목적
    - 추상클래스는 인스턴스를 생성할 목적으로 만들어진게 아님
    - 상속에서 기본 클래스의 역할 위함
        * 순수 가상 함수를 통해 **파생 클래스에서 구현할 함수의 형태(원형)을 보여주는 인터페이스 역할**
        * 추상 클래스의 모든 멤버함수를 순수 가상함수로 선언할 필요 없음

+ 추상 클래스: 최소한 하나의 순수 가상함수를 가진 클래스
    ```cpp
    class Shape{
        Shape *next;
        public:
            void paint(){
                draw();
            }
            virtual void draw()=0;//순수 가상함수
    };
    void Shape::paint(){
        draw();//순수 가상 함수라도 호출은 할 수 있다.
    }
    ```
    
    - 온전한 클래스가 아니어서 객체 생성 불가능
    - 추상 클래스의 포인터는 선언 가능

    예시 코드
    ```cpp
    #include<iostream>
    using namespace std;

    class Date{
        protected:
            int year, month, day;
        public:
            Date(int y, int m,int d){ year=y; month=m; day=d;}
        virtual void print()=0;//pure virtual function
    };
    class Adate:public Date{
        public:
            Adate(int y, int m, int d):Date(y,m,d){}
            void print(){cout<<year<<"/"<<month<<"/"<<day<<endl;}
    };

    class Bdate:public Date{
        public:
            Bdate(int y, int m, int d):Date(y,m,d){}
            void print();
    };

    void Bdate::print(){
        static const char *mn[]={
            "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
        cout<<mn[month-1]<<" "<<day<<" "<<year<<endl;
    };

    int main()
    {
        Adate ad(2010,3,15);
        Bdate bd(2010,3,15);
        Date &r1=ad, &r2=bd;
        r1.print();
        r2.print();

        return 0;
    }
    ```

+ 추상클래스의 상속과 구현
    - 추상 클래스를 단순 상속하면 자동 추상 클래스
    - 추상 클래스를 상속 받아 순수 가상 함수를 오버라이딩
        * 이렇게 되면 파생 클래스는 추상클래스가 아님
    ```cpp
    class Shape{
        public:
            virtual void draw()=0;
    };
    class Circle: public Shape{
        public:
            string toString(){return "Cricle 객체";}
    };
    int main(){
        Shape shape;//객체 생성 오류
        Circle waffle;//객체 생성 오류
        return 0;
    }
    ```
    근데 만약 위의 코드에서 Circle 안에 virtual void draw를 정의해주었다면 그때부터 Circle은 추상클래스가 아니고 순수 가상함수를 오버라이딩 하게 되어서 main함수의 Circle객체를 만드는 것에는 문제가 없어진다.

    추상클래스 구현 예시

    ```cpp
    #include<iostream>
    using namespace std;

    class Calculator{
        public:
            virtual int add(int a, int b)=0;
            virtual int subtract(int a, int b)=0;
            virtual double average(int a[], int size)=0;
    };

    class GoodCalc:public Calculator{
        public:
            int add(int a,int b){return a+b;}
            int subtract(int a,int b){return a-b;}
            double average(int a[],int size){
                double sum=0;
                for(int i=0;i<size;i++){
                    sum+=a[i];
                }
                return sum/size;
            }
    };

    int main()
    {
        
        int a[]={1,2,3,4,5};
        Calculator *p=new GoodCalc();
        cout<<p->add(2,3)<<endl;
        cout<<p->subtract(2,3)<<endl;
        cout<<p->average(a,5)<<endl;
        //calculator는 추상클래스이고 각 순수가상함수들은 virtual을 달았기 때문에 포인터가 가리키는 goodcalc의 함수를 호출한다.
        return 0;
    }
    ```

+ 추상클래스를 상속 받는 파생 클래스 구현 연습 코드
```cpp
#include<iostream>
using namespace std;

class Calculator{
    void input(){
        cout<<"두 정수를 입력하세요>> ";
        cin>>a>>b;
    }
    protected:
        int a,b;
        virtual int calc(int a,int b)=0;
    public:
        void run(){
            input();
            cout<<"계산된 값은 "<<calc(a,b)<<"입니다."<<endl;
        }
};

class Adder: public Calculator{
    protected:
        virtual int calc(int a,int b){ //virtual 키워드 생략 가능
            return a+b;
        }
};

class Subtractor: public Calculator{
    protected:
        virtual int calc(int a,int b){ //여기서 virtual 키워드 생략 가능
            return a-b;
        }
};


int main()
{
    Adder adder;
    Subtractor sub;
    adder.run();
    sub.run();
    
    return 0;
}

```
> 위의 코드를 보면, 처음에 protected로 calc이 쌓여져 있어서 main에서 어떻게 실행이 되었는지 의문이었는데, main에서는 run(public)을 호출하고 있고, 그 안에서 calc를 호출하고 있기 때문에, calculator클래스의 멤버함수인 protected멤버에 접근 가능
> 위의 코드에서 주목해보아야 할 점은 **같은 calc함수를 호출시킴에도 불구하고, 객체에 따라 다른 함수가 호출이 되어 실행**이 된다는 점이 중요!

+ 다형성(polymorphism)
    - 객체들의 타입이 다르면 똑같은 메세지가 전달되더라도 서로 다른 동작을 하는 것 (= 실행시간 다형성)
    - 다형성은 객체 지향 기법에서 하나의 코드로 다양한 타입의 객체를 처리하는 중요한 기술

    ```cpp
    #include<iostream>
    using namespace std;

    class Shape{
        protected:
            int x,y;
        public:
            Shape(int x,int y):x{x},y{y}{}
            virtual void draw(){
                cout<<"Shape Draw"<<endl;
            }
    };

    class Rect:public Shape{
        private:
            int width,height;
        public:
            Rect(int x,int y,int w, int h):Shape(x,y),width{w},height{h}{}
            void draw(){
                cout<<"Rect Draw"<<endl;
            }
        };

    int main()
    {
        Shape*ps=new Rect(0,0,100,100);//OK
        ps->draw();
        delete ps;
        return 0;
    }
    ```
    위의 코드를 보면 shape와 rect 클래스 모두 draw 함수 정의되어 있어도 포인터가 가리키는 객체에 따라 함수 발현(호출)이 달라지는 것을 확인할 수 있다.

    + 참조자도 포인터와 마찬가지로 모든 것이 동일하게 적용. 부모클래스의 참조자로 자식 클래스를 가리킬 수 있고, 가상 함수의 동작도 동일하다.

+ 가상 소멸자(virtual destructor)
    - 상향 형변환 시, 파생 클래스의 소멸자를 선언해 놓고 보면 기본 클래스의 소멸자만 호출되고 파생 클래스의 소멸자는 호출이 되지 않아 메모리 누수의 문제가 생길 수 있다.

    - 해결책: 부모 클래스의 소멸자 앞에 virtual 키워드를 붙여 놓으면 먼저 파생 클래스의 소멸자를 실행시키고, 그 다음 기본 클래스의 소멸자를 실행시킨다. 
    
    코드 예시
    
    ```cpp
    #include<iostream>
    #include<cstring>
    using namespace std;

    class AAA{
        char *str1;
        public:
            AAA(const char* _str1){
                str1=new char[strlen(_str1)+1];
                strcpy(str1,_str1);
            }
            virtual ~AAA(){
                cout<<"~AAA 소멸자"<<endl;
                delete []str1;
            }
            virtual void ShowString(){
                cout<<str1<<" ";
            }
    };
    class BBB:public AAA{
        char *str2;
        public:
            BBB(const char*_str1,const char* _str2):AAA(_str1){
                str2=new char[strlen(_str2)+1];
                strcpy(str2,_str2);
            }
            ~BBB(){
                cout<<"~BBB 소멸자"<<endl;
                delete []str2;
            }
            virtual void ShowString(){
                AAA::ShowString(); //범위 지정 연산자를 통해 부모 클래스의 함수 호출
                cout<<str2<<endl;
            }
    };

    int main()
    {
        AAA *a=new BBB("Good","Morning");
        BBB *b=new BBB("Hello","evening");
        a->ShowString();
        b->ShowString();
        cout<<"---------객체 소멸 직전----------"<<endl;
        delete a;
        delete b;
        return 0;
    }
    ```

+ 오버라이딩의 목적- 파생 클래스에서 구현할 함수 인터페이스(파생 클래스의 다형성)
    - 다형성의 실현
        * draw() 가상 함수를 가진 기본 클래스 Shape
        * 오버라이딩을 통해 Circle, Rect, Line클래스에서 자신만의 draw()를 구현

        ```cpp
        class Shape{
            protected:
                virtual void draw(){}//가상함수 선언, 파생클래스에서 재정의할 함수에 대한 인터페이스 역할
        };

        class Circle: public Shape{
            protected:
                virtual void draw(){//Circle 그리기
                }
        };
        class Rect: public Shape{
            protected:
                virtual void draw(){
                    //원하는 코드
                }
        };
        void paint(Shape *p){
            p->draw();
        }
        int main(){
            paint(new Circle());
            paint(new Rect());
            return 0;
        }
        ```
        위와 같이 원하는 객체에 따라 자신 각자 구현하고 싶은 함수를 실행할 수 있다.

        **즉, shape는 상속을 위한 기본 클래스로의 역할이고, draw()로 파생 클래스의 인터페이스를 보여주고, 객체를 생성할 목적은 아님, 그래서 파생클래스에서 draw()를 재정의해야 함**
+ 바인딩(binding)
    - 정적 바인딩: 컴파일 시 호출되는 함수를 결정
    - 동적 바인딩: 실행 시 호출되는 함수를 결정
        * 파생 클래스에 대해
        * 객체 내에 오버라이딩한 파생 클래스의 함수를 찾아 실행
        * 실행 중에 이루어짐
        * 실행 시간 바인딩, 런타임 바인딩, 늦은 바인딩이라고도 불림

+ 범위 지정 연산자(::)를 이용한 기본 클래스의 가상 함수 호출
```cpp
#include<iostream>
using namespace std;

class Shape{
    public:
        virtual void draw(){
            cout<<"--shape--"<<endl;
        }
};
class Rect:public Shape{
    public:
        virtual void draw(){
            Shape::draw();
            cout<<"--rect--"<<endl;
        }
};

int main()
{
    Rect r;
    Shape *p=&r;

    p->draw();//동적 바인딩을 포함하는 호출
    p->Shape::draw();//정적 바인딩
    return 0;
}
```
위와 같이 범위지정 연산자 ::를 통해 virtual로 무시되는 것을 강제로 호출시킬 수 있다.
