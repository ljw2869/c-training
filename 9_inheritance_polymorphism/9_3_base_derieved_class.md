9.3 상속 관계에서 파생클래스의 생성 및 소멸 과정
==============================================
**상속을 A->B->C로 하고 c클래스를 만들면 생성자 순서는 A->B->C, 소멸자 순서는 반대로 C->B->A임. 스택 구조를 생각하기**

+ 파생 클래스의 생성자에서 기본 클래스의 생성자를 호출할 때 아무 코드가 없으면 그냥 기본 생성자를 호출함
    - 그런데 만약에 기본 클래스에 기본생성자를 선언해두지 않았다면 컴파일 오류가 뜨게 됨

    - 그럴 때는 기본 클래스의 어떤 생성자를 호출할 지 적어주면 오류 없이 원하는 방향으로 코드를 작성할 수 있다.

    예시:

    ```cpp
    #include<iostream>
    using namespace std;

    class A{
            public:
                A(){cout<<"생성자 A"<<endl;}
                A(int a){cout<<"매개 변수 생성자 A"<<endl;}
    };

    class B:public A{
        public:
            B(){//A()를 호출하도록 컴파일 됨
                cout<<"생성자 B"<<endl;
            }
            B(int x):A(x+3){
                cout<<"매개변수 생성자 B"<<endl;
            }
    };
    int main()
    {
        B b(5);

        return 0;
    }
    ```
    위와 같이 원하는 매개변수를 넣고 싶은 상황(매개변수가 있는 생성자 호출)이라면 생성자 옆에 :A(매개변수)로 선언해서 가도록 해주면 됨, 그렇지 않으면 컴파일러가 묵시적으로 삽입한 코드인 :A()가 붙게 됨

+ 상속 지정
    상속 선언 시 public, private, protected의 3가지 중 하나 지정
    - 기본 클래스의 멤버의 접근 속성을 어떻게 계승할지 지정
        * public: 기본 클래스의 접근 지정자(멤버 속성)을 그대로 계승
        * protected: public은 protected로 바뀜
        * private: 모두 private으로 계승
    
    - 그래서 상속 후의 클래스에 위에 덧붙여지는 공간에 접근 지정자가 기본 클래스의 접근 지정자와 다르게 적용될 수 있음

    예시 코드: 
    * public 상속 코드
    ```cpp
    #include<iostream>
    using namespace std;

    class Base{
        int a;
        protected:
            void setA(int a){
                this->a = a;
            }   
        public:
            void showA(){
                cout << "A: " << a << endl;
            }
    };

    class Derived: public Base{
        int b;
        protected:
            void setB(int b){
                this->b = b;
            }
        public:
            void showB(){
                cout << "B: " << b << endl;
            }
    };
    int main()
    {
        Derived x;
        //x.a=5
        //x.setA(10);
        //x.showA();
        //x.b=20;
        //x.setB(10);
        //위의 주석 코드는 에러남 왜냐하면 private이기 때문에
        x.showB();
        return 0;
    }
    ```
    * protected 상속 코드
        위와 코드는 같고 상속 지정만 protected로 바꿔줘도 main에서는 해당 함수들이 protected로 접근이 불가하기에 위에서 주석처리한 부분이 동일하게 에러가 발생한다.

+ 상속이 중첩될 때 접근 지정 사례
    접근 지정으로 어디까지는 되고, 어디는 안 되는지 잘 파악하기!!
    ```cpp
    #include<iostream>
    using namespace std;

    class Base{
        int a;
        protected:
        void setA(int a){
            this->a = a;
        }
        public:
        void showA(){
            cout << "a = " << a << endl;
        }
    };

    class Derived: private Base{
        int b;
        protected:
        void setB(int b){
            this->b = b;
        }
        public:
        void showB(){
            setA(5);
            showA();
            cout << "b = " << b << endl;
        }
    };
    class GrandDerived: private Derived{
        int c;
        protected:
        void setAB(int c){
            //setA(c);
            //showA();
            setB(c);
        }
        
    };
    int main()
    {
        return 0;
    }
    ```
    > 위의 코드에서 주석 처리된 부분이 컴파일 오류가 발생하는 이유는 상속을 모두 private으로 받으면서, grand입장의 부모 클래스 derived 멤버들은 private일 자신의 안에 들어와 있는 private변수라서 사용 가능함<br> 하지만, 한번 더 깊이 들어가야 되는 base는 private에 가로막혀 접근이 불가하기에, setA()와 같은 코드가 불가능

+ 다중 상속
    ```cpp
    #include<iostream>
    using namespace std;

    class Adder{
        protected:
        int add(int a,int b){return a+b;}
    };

    class Subtractor{
        protected:
        int sub(int a,int b){return a-b;}
    };
    //다중 상속 Multiple Inheritance
    class Calculator:public Adder,public Subtractor{
        public:
        int calc(char op, int a,int b){
            int res=0;
            switch(op){
                case '+': res=add(a,b); break;
                case '-': res=sub(a,b); break;
            }
            return res;
        }
    };
    int main()
    {
        Calculator calc;
        cout<<"2 + 4 = "<<calc.calc('+',2,4)<<endl;
        cout<<"100 - 8 = "<<calc.calc('-',100,8)<<endl;
        return 0;
    }
    ```

    * 다중 상속의 문제점: 기본 클래스 멤버의 중복 상속
        > baseIO: { public: int mode; }
        >>+ In: public BaseIO { public: int readPos; }
        >>+ Out:public BaseIO { public: int writePos; }
        >>> class InOut: public In, public Out{
            public: bool safe;
        }
        
        위의 2가지 클래스 In과 Out을 다중 상속

        **이때, InOut객체를 만들고 mode를 접근하려 할 때 서로 다른 mode공간이 생겨버려 어디로 접근해야 할 지 모르는 문제가 생기게 된다.**

        다음의 문제를 해결하기 위한 선언문 virtual

    * 가상 상속
        - 다중 상속으로 인한 기본 클래스 멤버의 중복 상속 해결
        - 파생 클래스의 선언문에서 기본 클래스 앞에 virtual로 선언
        - 파생 클래스의 객체가 선언될 때 기본 클래스의 멤버는 **오직 한 번만 생성**
        - 그래서 기본 클래스의 멤버가 중복으로 생성되는 것을 방지
        ```cpp
        class In virtual public BaseIO{

        };
        class Out virtual public BaseIO{

        };
        ```
        이렇게 코드를 짜 두면 나중에 InOut객체가 만들어질 때 mode공간이 하나만 만들어지게 됨

