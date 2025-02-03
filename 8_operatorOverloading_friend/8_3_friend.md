8.3 프렌드 함수
=======================

### 프렌드 함수

+ friend 키워드로 클래스 내에 선언된 함수
    - 클래스의 모든 멤버를 접근할 수 있는 권한 부여
+ 필요성
    - 클래스의 멤버로 선언하기는 무리가 있고, 클래스의 모든 멤버를 자유롭게 접근할 수 있는 일부 외부 함수 작성 시 

+ 클래스의 멤버 함수가 아닌 외부 함수
    - 전역 함수, 다른 클래스의 멤버 함수, 클래스 안의 함수 통째로 friend로 지정할 수도 있음
    1. 외부 함수 equals()를 Rect클래스의 friend로 선언
        ```cpp 
        class Rect{
            friend bool equals(Rect r, Rect s);
        };
        ```
        실제 적용 예시

        ```cpp
        #include<iostream>
        using namespace std;

        class Rect;//이게 선언되기 전에 먼저 참조되는 컴파일 오류를 막기 위한 선언문(함수의 프로토 타입을 적어주는 것처럼)
        bool equals(Rect r, Rect s);//함수의 프로토 타입

        class Rect{
            int width, height;
            public:
                Rect(int width, int height){
                    this->width = width;
                    this->height = height;
                }
                friend bool equals(Rect r, Rect s);//friend 선언
                
        };

        bool equals(Rect r, Rect s){
            if(r.width == s.width && r.height == s.height) return true;
            else return false;
        }

        int main()
        {
            Rect a(3, 4), b(4, 5);
            if (equals(a, b)) cout << "equal" << endl;
            else cout << "not equal" << endl;
            return 0;
        }
        ```

    2. RectManager 클래스의 equals()멤버 함수를 Rect클래스에 프렌드로 선언
        ```cpp
        class Rect{
            friend bool RectManager::equals(Rect r, Rect s);
        };
        ```
        실제 적용 예시
        ```cpp
        #include<iostream>
        using namespace std;

        class Rect;//이게 선언되기 전에 먼저 참조되는 컴파일 오류를 막기 위한 선언문(함수의 프로토 타입을 적어주는 것처럼)
        class RectManager{
            public:
                bool equals(Rect c,Rect s);
        };

        class Rect{
            int width, height;
            public:
                Rect(int width, int height){
                    this->width = width;
                    this->height = height;
                }
                friend bool RectManager::equals(Rect c, Rect s);
        };

        bool RectManager::equals(Rect c, Rect s){
            if(c.width == s.width && c.height == s.height) return true;
            else return false;
        }

        int main()
        {
            Rect a(3, 4), b(4, 5);
            RectManager man;
            if (man.equals(a, b)) cout << "equal" << endl;
            else cout << "not equal" << endl;
            return 0;
        }
        ```

    3. RectManger 클래스의 모든 멤버 함수를 Rect 클래스에 프렌드로 선언
        ```cpp
        class Rect{
            friend RectManager;
        };
        ```
        이렇게 해 놓으면 매니저가 rect의 private한 곳까지 접근 가능
        실제 적용 예시
        ```cpp
        #include<iostream>
        using namespace std;

        class Rect;//이게 선언되기 전에 먼저 참조되는 컴파일 오류를 막기 위한 선언문(함수의 프로토 타입을 적어주는 것처럼)
        class RectManager{
            public:
                bool equals(Rect c,Rect s);
                void copy(Rect& dest, Rect& src);
        };

        class Rect{
            int width, height;
            public:
                Rect(int width, int height){
                    this->width = width;
                    this->height = height;
                }
                friend RectManager;
        };

        bool RectManager::equals(Rect c, Rect s){
            if(c.width == s.width && c.height == s.height) return true;
            else return false;
        }

        void RectManager::copy(Rect& dest, Rect& src){
            dest.width = src.width;
            dest.height = src.height;
        }

        int main()
        {
            Rect a(3, 4), b(4, 5);
            RectManager man;
            man.copy(a, b);//a=b;
            if (man.equals(a, b)) cout << "equal" << endl;
            else cout << "not equal" << endl;
            return 0;
        }
        ```
    
    - friend의 용도
        * 두개의 객체를 비교할 때 많이 사용된다.
            ```cpp
            #include<iostream>
            using namespace std;

            class Date{
                int year, month, day;
                public:
                    Date(int y=0, int m=0, int d=0):year(y), month(m), day(d){}
                    bool equals(Date obj){
                        return year==obj.year && month==obj.month && day==obj.day;
                    }
            };


            int main()
            {
                Date date1(2020, 10, 10), date2(2020, 10, 11);  
                if (date1.equals(date2)==true)
                    cout << "Both dates are equal";
                else
                    cout << "Both dates are not equal";
                return 0;
            }
            ```
            위의 코드를 다음과 같이 바꿀 수 있다.
            ```cpp
            #include<iostream>
            using namespace std;

            class Date{
                friend bool equals(Date obj1, Date obj2);
                int year, month, day;
                public:
                    Date(int y=0, int m=0, int d=0):year(y), month(m), day(d){}
            };

            bool equals(Date obj1, Date obj2){
                return obj1.year==obj2.year && obj1.month==obj2.month && obj1.day==obj2.day;
            }

            int main()
            {
                Date date1(2020, 10, 10), date2(2020, 10, 11);  
                if (equals(date1,date2)==true)
                    cout << "Both dates are equal";
                else
                    cout << "Both dates are not equal";
                return 0;
            }
            ```
            이런 식으로 그냥 외부에 함수를 따로 만들어서 궂이 매번 클래스에 함수를 계속 추가해 나가지 않고 필요에 따라 접근 권한을 주어서 함수만 추가해 나가는 방식으로 접근
    - << 연산자를 어떤 객체든지 출력하는 방식으로 구현하고 싶을 때, friend를 사용하는 수 밖에 없음 (컴파일러의 라이브러리에서 지원하는 기능이라 바꿀 수 없음)
        ```cpp
        #include<iostream>
        using namespace std;

        class MyVector
        {
            private:
            double real, imag;
            public:
            MyVector(double x=0.0, int y=0.0):real(x),imag(y){}
            friend ostream&operator <<(ostream&os, const MyVector&v){
                os<<"("<<v.real<<","<<v.imag<<")"<<endl;
                return os;
            }
        };

        int main()
        {
            MyVector v1(1.0, 2.0), v2(3.0, 4.0),v3;
            cout<<v1<<v2<<v3;
            return 0;
        }
        ```
        위와 같이 삽입 연산자를 이용해서 출력하기 위해선 ostream 래퍼런스 operator<<에 대해서 중복 정의를 해주어야 하고 반드시 friend로 재정의 해주어야 한다.
    
    - power 클래스를 통한 외부 함수의 friend예시
    ```cpp
    #include<iostream>
    using namespace std;

    class Power{
        int kick;
        int punch;
    public:
        Power(int kick=0, int punch=0){
            this->kick = kick;
            this->punch = punch;
        }
        void show();
        friend Power operator+(int op1, Power op2);//프렌드 선언
    };

    void Power::show(){
        cout << "kick = " << kick << " , punch = " << punch << endl;
    }

    Power operator+(int op1, Power op2){
        Power tmp;
        tmp.kick = op1 + op2.kick;
        tmp.punch = op1 + op2.punch;
        return tmp;
    }

    int main()
    {
        Power a(3,5), b;
        a.show();
        b.show();
        b = 2 + a;
        a.show();
        b.show();

        return 0;
    }
    ```
    앞에서 전위와 후위 연산자도 friend로 사용할 수 있음(++)
    ```cpp
    #include<iostream>
    using namespace std;

    class Power{
        int kick;
        int punch;
    public:
        Power(int kick=0, int punch=0){
            this->kick = kick;
            this->punch = punch;
        }
        void show();
        friend Power operator+(int op1, Power op2);//프렌드 선언
        friend Power& operator++(Power &op);//전위 ++연산자 함수 프렌드 선언
        friend Power operator++(Power &op, int x);//후위 ++연산자 함수 프렌드 선언
    };

    void Power::show(){
        cout << "kick = " << kick << " , punch = " << punch << endl;
    }

    Power operator+(int op1, Power op2){
        Power tmp;
        tmp.kick = op1 + op2.kick;
        tmp.punch = op1 + op2.punch;
        return tmp;
    }

    Power& operator++(Power &op){ //전위 ++연산자 함수 정의-참조 매개변수 사용에 주목
        op.kick++;
        op.punch++;
        return op;
    }

    Power operator++(Power &op, int x){ //후위 ++연산자 함수 정의
        Power tmp = op;
        op.kick++;
        op.punch++;
        return tmp;
    }

    int main()
    {
        Power a(3,5), b;
        b=++a;
        a.show();
        b.show();
        b=a++;
        a.show();
        b.show();

        return 0;
    }
    ```

- 유의할 점
    + 새로운 연산자를 만드는 것은 허용되지 않음 ex: ^ 불가능
    + 거의 모든 연산자가 중복 가능, except: ::, .*, . , ?:
    + 연산자들의 우선순위나 결합 법칙은 변경되지 않는다
    + +연산자를 중복하였다면 일관성을 위해 -, +=, -=연산자도 중복하는 것이 좋다.








