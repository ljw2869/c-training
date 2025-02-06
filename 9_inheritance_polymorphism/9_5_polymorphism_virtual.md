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
    



