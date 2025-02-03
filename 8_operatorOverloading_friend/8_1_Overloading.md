8-1.Overloading
=================
+ 연산자 오버로딩
    - 기존에 c언어에서 제공하고 있는 연산자에 대하여 그 의미를 다시 부여하는 것
    - 다른 말로 연산자 중복(재정의)
    - 함수의 오버로딩과 같이 연산자도 하나의 함수라는 개념을 사용하여 중복 정의
    - 중복되는 연산자 함수는 클래스의 멤버 함수나 프렌드 함수로 정의

    **함수 이름 대신에 operator 키워드를 사용하고 다음에 연산자를 기술**
    > 반환형 operator 연산자(매개변수 리스트){ ...//연산 수행}

    - 두 가지 형태로 표현
        * 멤버함수에 의한 오버로딩 ex: v1.operator+(v2)
        * 전역함수에 대한 오버로딩, friend 함수 선언 ex: operator+(v1,v2);

    - 주의사항
        1. 본래의 의도를 벗어난 형태의 연산자 오버로딩은 좋지 않다
        2. 연산자의 우선순위와 결합성은 바뀌지 않는다.
        3. 매개변수의 디폴트 값 설정이 불가능하다.
        4. 연산자의 순수 기능까지 빼앗을 수 없다.
    
    - 연산자 중복의 사례: +
        * 정수 더하기
        * 문자열 합치기
    - cpp에 본래 있는 연산자만 중복 가능
        * 중복이 불가능한 연산자: (.(멤버 선택 연산자), .*(멤버 포인터 연산자), ::(범위지정 연산자),?: (3항 연산자=조건 연산자))
    

    - 피연산자 타입이 다른 새로운 연산 정의
    - 연산자는 함수 형태로 구현 - 연산자 함수(operator function)
    - 반드시 클래스와 관계를 가짐
    - 피연산자의 개수를 바꿀 수 없음
    - 연산의 우선순위 변경이 안됨
    

    - +와 ==의 작성 사례
    ```cpp
    Color a(Blue),b(Red),c;

    c=a+b;
    if(a==b){

    }
    ```
    위와 같은 코드를 작성하기 위해
    1. 외부 함수로 구현되고 클래스에 프렌드로 선언되는 경우
    ```cpp
    Color operator+(Color op1,Color op2);
    bool operator==(Color op1,Color op2);//외부 함수

    class Color{
        friend Color operator+(Color op1,Color op2);
        friend bool operator==(Color op1,Color op2);
    };
    ```
    2. 클래스의 멤버함수로 작성되는 경우
    ```cpp
    class Color{
        Color operator+(Color op2);
        bool operator==(Color op2); // 하나만 넘어오는 이유는 주체가 되는 객체가 있기 때문에 
    };
    ```

    - 연산자 중복의 예시
        vector +연산자 사용
        > (v1+v2+v3); 연산자 중복 사용
        > add(v1,add(v2,v3)); 함수 사용

        string 클래스도 +연산자 중복을 이미 하고 있음


    power 클래스를 통한 연산자 오버로딩 예시
    ```cpp
    #include<iostream>
    using namespace std;

    class Power{// 에너지를 표현하는 파워 클래스
        int kick;//발로 차는 힘
        int punch;//주먹으로 치는 힘

    public:
        Power(int kick=0, int punch=0){
            this->kick = kick;
            this->punch = punch;
        }
        void show();
        Power operator+(Power op2);//인터페이스
        bool operator==(Power op2);//인터페이스
        Power& operator+=(Power op2);//인터페이스
        Power operator+(int op2);//인터페이스
    };

    void Power::show(){//구현부
        cout << "kick = " << kick << ',' << "punch = " << punch << endl;
    }

    Power Power::operator+(Power op2){ //구현부
        Power tmp;
        tmp.kick = this->kick + op2.kick;
        tmp.punch = this->punch + op2.punch;
        return tmp;
    }

    bool Power::operator==(Power op2){//구현부
        if(this->kick == op2.kick && this->punch == op2.punch)
            return true;
        else
            return false;
    } // 여기서 op2라고 따로 두었기 때문에 프로그램을 실행할 때 op2라는 공간이 따로 생성된다

    Power& Power::operator+=(Power op2){//구현부
        this->kick += op2.kick; //더한 값을 현재 kick값에 저장
        this->punch += op2.punch;
        return *this; //자신의 참조 리턴->자기 자신을 리턴 *this
    }

    Power Power::operator+(int op2){//구현부
        Power tmp;
        tmp.kick = this->kick + op2;
        tmp.punch = this->punch + op2;
        return tmp;
    }

    int main()
    {
        
        Power a(3,5), b(4,6), c;
        // c = a + b;
        a.show();
        b.show();
        if (a==b)
            cout<<"두 파워가 같다."<<endl;
        else
            cout<<"두 파워가 같지 않다."<<endl;
        // c=a+=b; //a가 +=연산자를 수행한 후에(내부의 값이 바뀌고) c에 대입되어서 c가 a의 별칭이 되게 됨
        // a.show();
        // c.show();
        b=a+2;
        a.show();
        b.show();
        return 0;
    }
    ```
    벡터로 만드는 연산자 중복 예시
    ```cpp
    #include<iostream>
    #include<string>
    using namespace std;

    class MyVector{
        private:
            double x,y;

        public:
            MyVector(double x=0.0, double y=0.0):x{x},y{y}{}
            string  toString(){
                return "("+to_string(x)+","+to_string(y)+")";
            }
            MyVector operator+(const MyVector& v2);//const를 받았기 때문에 v2값을 변경할 수 없다
    };

    MyVector MyVector::operator+(const MyVector& v2){
        return MyVector(x+v2.x,y+v2.y);
    }

    int main()
    {
        MyVector v1(1.0,2.0),v2(3.0,4.0);
        MyVector v3 = v1+v2;
        cout<<v1.toString()<<"+"<<v2.toString()<<"="<<v3.toString()<<endl;
        
        return 0;
    }
    ```

    자기 자신의 참조를 통해 메모리 공간을 줄이는 효율적인 코드 예시
    ```cpp
    #include<iostream>
    using namespace std;


    class Time{
        int hour,min,sec;
        public:
        Time(int h=0,int m=0,int s=0):hour(h),min(m),sec(s){}

        bool operator==(Time &t2){//참조 연산자를 사용하면 객체를 복사하지 않아도 되기 때문에 효율적이다.
            return (hour==t2.hour && min==t2.min && sec==t2.sec);
        }
        //같은 메모리를 공유하게 된다=메모리 절약 면에서 뛰어남
        bool operator!=(Time &t2){ 
            return !(*this==t2);//같다는 관계함수를 부정할 수 있고 이 안에서 호출하기 때문에 *this를 사용할 수 있음
            //t2의 자기 자신의 참조로 인해서 t2를 인수로 넘겨줄 수 있다.
        }
        
    };

    int main()
    {
        Time t1(1,2,3), t2(1,2,3);
        //참과 거짓을 1,0으로 출력하지 않고 true,false로 출력하게 하는 코드
        cout.setf(cout.boolalpha);
        cout<< (t1==t2) <<endl;
        cout<< (t1!=t2) <<endl;
        
        return 0;
    }
    ```


