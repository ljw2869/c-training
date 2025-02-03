8.2 단항 연산자 중복
============================
+ 단항 연산자
    - 피연산자가 하나 뿐인 연산자
        * 연산자 중복 방식은 이항 연산자의 경우와 거의 유사함
    - 종류:
        * 전위 연산자(prefix operator)
            ex: !op, ++op, --op
        * 후위 연산자(postfix operator)
            ex: op++, op--
    
    - 전위 ++ 연산자 중복
        **반환형은 반드시 참조자 타입이어야 함!!**
        > 만약 단순히 Power 로 선언이 되었다면 객체 c의 복사본이 반환되어 ++연산이 원본 객체에 적용되지 않음 <br> c++: c.operator++(), c--: c.operator--()
        ```cpp
        class Power{
            ....
            public:
                Power& operator++();
        };

        Power& Power::operator++(){
            kick++;
            punch++;
            return *this;// 변경된 객체 자신의 참조 리턴
        }
        ```
        **즉 인수가 없고 리턴 타입이 참조형이어야 하며, 자기 자신을 리턴해주어야 한다**

        
        ```cpp
        #include<iostream>
        using namespace std;

        class Power{
            int kick;
            int punch;

            public:
                Power(int kick=0,int punch=0){
                    this->kick=kick;
                    this->punch=punch;
                }

                void show();
                bool operator!();
        };

        void Power::show(){
            cout<<"kick = "<<kick<<','<<"punch = "<<punch<<endl;
        }

        bool Power::operator!(){
            if (kick==0&&punch==0)return true;
            else return false;
        }

        int main()
        {
            Power a(0,0),b(5,5);
            if(!a) cout<<"a의 파워가 0이다."<<endl;
            else cout<<"a의 파워가 0이 아니다."<<endl;
            if (!b) cout<<"b의 파워가 0이다."<<endl;
            else cout<<"b의 파워가 0이 아니다."<<endl;
            return 0;
        }
        ```
    - 후위 연산자 중복, ++ 연산자
        a++ 와 같은 후위 연산자는 위의 전위 연산자와는 조금 다른 구조를 띤다.
        ```cpp
        Power operator++(int x);

        Power Power::operator++(int x){
            Power tmp=*this;
            kick++;
            punch++;
            return tmp;//증가 이전 객체 상태를 리턴
        }
        ```
        **전위와 후위를 구분하기 위해 임의의 정수를 넣는다는 것이 차이점!, 이전의 객체 상태를 리턴하기 위해 참조연산자는 쓰지 않음!**
        예시로 b=2+a라는 순서로 연산자를 만들면, 이때도 후위연산자와 같이 리턴하는 값을 따로 만들어야해서 Power로 리턴형을 만들고 int와 Power op를 받아서, 정수와 클래스 객체 사이 연산자를 만들게 된다.
    - 참조를 리턴하는 << 연산자
        객체 멤버에 정수를 더하는 <<연산자를 구현
        ```cpp
        #include<iostream>
        using namespace std;

        class Power{
            int kick;
            int punch;
            public:
                Power(int kick=0,int punch=0){
                    this->kick=kick;
                    this->punch=punch;
                }
                void show();
                Power& operator<<(int n);//연산 후 Power객체의 참조 리턴
        };

        void Power::show(){
            cout<<"kick = "<<kick<<", punch = "<<punch<<endl;
        }

        Power& Power::operator<<(int n){
            kick+=n;
            punch+=n;
            return *this;
        }

        int main()
        {
            Power a(1,2);
            a<<3<<5<<6;
            a.show();
            
            return 0;
        }
        ```
        넘어온 순서에 따라 더해지게끔 재정의 됨

    - 디폴트 대입 연산자 =
        + 디폴트 복사 생성자와 유사
        + 기본적으로 얕은 복사를 하게 됨
        + 포인터 멤버변수를 갖는 소멸자 호출 시 문제 발생 가능성
        + 동적 할당시 깊은 복사로 문제 해결

        ex: b2=b1  (b2.(= b1)으로 연산자의 주체는 b2가 된다.)

    - 인덱스 연산자 [] 의 중복
        ```cpp
        #include<iostream>
        using namespace std;

        const int SIZE = 10;

        class MyArray
        {
            int arr[SIZE];
            public:
            MyArray()
            {
                for(int i=0; i<SIZE; i++)
                    arr[i] = 0;
            }

            int &operator[](int i) //리턴 타입이 참조형이어야 하는 이유: a[]=5이런 식으로 왼쪽(주체)의 값에 대입을 해주어야 하기 때문
            {
                if(i<0 || i>=SIZE)
                {
                    cout<<"Index out of bounds"<<endl;
                    return arr[0];
                }//런타임 에러 방지
                return arr[i];
            }
        };

        int main()
        {
            MyArray a;
            a[3] = 9; // a.operator[](3) = 9;
            cout<<a[3]<<endl;
            cout<<a[13]<<endl;
            return 0;
        }
        ```
    - 포인터 연산자의 중복
        ```cpp
        #include<iostream>
        using namespace std;

        class Pointer{
            int *p;
            public:
            Pointer(int*p):p(p){}
            ~Pointer(){
                delete p;
            }
            int*operator->()const{//포인터 리턴
                return p;
            }
            int&operator*()const{//참조형 리턴
                return *p;
            }//정수형이기 때문에 이 부분에 대해서만 테스트 할 수 있다.

        };

        int main()
        {
            Pointer p(new int);
            *p=100;
            cout<<*p<<endl;
            return 0;
        }
        ```






        

