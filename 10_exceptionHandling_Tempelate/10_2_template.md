10.2 템플릿
===================
c++에서도 하나의 형 틀을 만들어서 다양한 코드를 생산해 내도록 할 수 있는데 이것을 템플릿이라고 한다. 함수 템플릿(function template)은 함수를 찍어내기 위한 형틀이다.

예를 들어 두 함수의 매개변수만 다르고 나머지 코드는 동일하여 하는 역할이 동일할 때, 즉 중복 함수의 코드 중복을 간결화해주기 위해 사용한다.

* 일반화 프로그래밍(genetic programming)
    핵심적인 내용은 같고, 매개변수의 타입만 달라진다
    ```cpp
    template <typename T>
    T get_max(T x, T y){ //매개변수 타입, 리턴타입도 모두 템플릿으로 사용할 수 있다.
        if (x>y) return x;
        else return y;
    }
    int main(){
        cout<<get_max(1,3)<<endl;
        cout<<get_max(1.2,3.9)<<endl;
        return 0;
    }
    ```
* 함수 템플릿과 오버로딩
    만약 정수 혹은 실수형으로 받을 수 있지만, 문자열이 들어올 때는 함수에서 정의한 사칙연산을 사용하기 힘들 때, 문자열을 위한 함수를 같을 이름으로 만들어준다면 오버로딩이 되어서 문자열을 넣었을 때, 따로 정의한 함수로 넘어가 정의된다.
    ```cpp
    #include<iostream>
    using namespace std;

    template <typename T>
    void swap_values(T &x, T &y){
        T temp;
        temp=x;
        x=y;
        y=temp;
    }
    void swap_values(char *s1,char *s2){
        int len;

        len=(strlen(s1)>=strlen(s2))?strlen(s1):strlen(s2);
        char *tmp=new char[len+1];

        strcpy(tmp,s1);
        strcpy(s1,s2);
        strcpy(s2,tmp);
        delete []tmp;
    }

    int main(){
        int x=100, y=200;
        swap_values(x,y);// x와 y가 모두 int 타입
        cout<<x<<" "<< y<<endl;

        char s1[100]="This is a first string";
        char s2[100]="This is a second string";
        swap_values(s1,s2);//s1,s2가 모두 배열-오버로딩 함수 호출
        cout<<s1<<" "<<s2<<endl;
        return 0;
    }
    ```
* 클래스 탬플릿
    >template <typename T>
    >class 클래스 이름
    >{
    >    ...//T를 어디서든지 사용할 수 있다.
    >}

    ```cpp
    #include<iostream>
    using namespace std;

    template <typename T>
    class Box{
        T data; //T는 타입을 나타낸다.
        public:
            Box(){ }
            void set(T value){
                data=value;
            }
            T get(){
                return data;
            }
    };
    int main(){
        Box<int> box; //클래스에서는 명시적으로 타입을 적어주어야 한다
        box.set(100);
        cout<<box.get()<<endl;
        
        Box<double> box1;
        box1.set(3.141592);
        cout<<box1.get()<<endl;
        return 0;
    }
    ```
* 두 개 이상의 매개변수를 가지는 경우
    ```cpp
    #include <iostream>
    using namespace std;
    template <typename T1,typename T2> //타입 이름은 마음대로 정해도 됨
    class Box2{
        T1 first_data;
        T2 second_data;
    
    public:
        Box2(){}
        T1 get_first();
        T2 get_second();
        void set_first(T1 value){
            first_data=value;
        }
        void set_second(T2 value){
            second_data=value;
        }
    };
    template <typename T1, typename T2>
    T1 Box2<T1,T2>::get_first(){
        return first_data;
    }
    T2 Box2<T1,T2>::get_second(){
        return second_data;
    }
    int main(){
        Box2<int, double> b;
        b.set_first(10);
        b.set_second(3.14);
        cout<<"("<<b.get_first()<<", "<<b.get_second()<<")"<<endl;
        return 0;
    }
    ```
* 일반화와 템플릿
    * 제네릭(generic) 또는 일반화
        - 함수나 클래스를 일반화시키고, 매개변수 타입을 지정하여 틀에서 찍어내듯이 함수나 클래스 코드를 생산하는 기법
    * 탬플릿
        - 함수나 클래스를 일반화하는 c++도구
        - template 키워드로 함수나 클래스 선언
        - 변수나 매개변수 타입만 다르고, 코드 부분이 동일한 함수를 일반화시킴
        - 제네릭 타입- 일반화를 위한 데이터 타입
    * 템플릿 선언
        template <class T> 또는 template <typename T>
        template <class T1, class T2, class T3> //3개의 제네릭 타입을 가진 템플릿 선언

* 템플릿으로부터의 구체화
    * 구체화(specialization)
        - 템플릿의 제네릭 타입에 구체적인 타입 지정
            + 템플릿 함수로부터 구체화된 함수의 소스 코드 생성

        ```cpp
        #include<iostream>
        #include<cstring>
        using namespace std;

        class Circle{
            int radius;
            public:
            Circle(int radius=1){
                this->radius = radius;
            }
            int getRadius(){
                return radius;
            }
        };

        template <class T>
        void myswap(T &a, T &b){
            T temp;
            temp = a;
            a = b;
            b = temp;
        }


        int main()
        {
            int a = 4, b = 5;
            myswap(a, b);
            cout << a << " " << b << endl;

            double c = 0.3, d = 12.5;
            myswap(c, d);
            cout << c << " " << d << endl;

            Circle donut(5), pizza(20);
            myswap(donut, pizza);
            cout << donut.getRadius() << " " << pizza.getRadius() << endl;

            return 0;
        }
        ```
    * 구체화 오류
        제네릭 타입에 구체적인 타입 지정 시 주의할 점: 두 매개변수의 제네릭 타입이 동일해야 한다.

        두 개의 매개 변수의 타입이 서로 다르면 컴파일 오류 발생

* 템플릿의 장점과 제네릭 프로그래밍
    * 장점: 함수 코드의 재사용
        높은 소프트웨어의 생산성과 유용성
    * 단점: 
        - 포팅에 취약_컴파일러에 따라 지원하지 않을 수 있음
        - 컴파일 오류 메세지 빈약, 디버깅에 많은 어려움
    * 제네틱 프로그래밍
        - 일반화 프로그래밍이라고도 부름
        - 제네틱 함수나 클래스를 활용하는 프로그래밍 기법
        - c++ 에서 STL(Standard Template Library)제공, 활용

```cpp
#include<iostream>
#include<cstring>
using namespace std;

//배열을 복사하는 제네릭 함수 mcopy 함수 만들기
template <typename T1, typename T2>
void mcopy(T1 src[], T2 dest[], int n)//src배열의 n개의 원소를 dest배열로 복사한다.
{
    for(int i=0; i<n; i++)
    {
        dest[i] = (T2)src[i];//T1타입의 값을 T2타입으로 변환한다.
    }
}

int main()
{
    int x[] = {1, 2, 3, 4, 5};
    double y[5];
    char c[5]={'H','e','l','l','o'},e[5];

    mcopy(x, y, 5);
    mcopy(c, e, 5);
    for (int i=0;i<5;i++)
    {
        cout << y[i] << ' ';
    }
    cout<<endl;
    for (int i=0;i<5;i++)
    {
        cout << e[i] << ' ';
    }
    cout<<endl;
    return 0;
}
```
* 배열을 출력하는 print()템플릿 함수의 문제점
    문자를 출력하는 경우가 print()는 문자 그대로 출력하기 때문에, char배열의 각 요소가 문자로 출력이 된다.
    만약 char배열의 원소를 정수로 출력하고 싶을 때 char배열을 위한 별도의 print 함수를 정의해야 한다.
    ```cpp
    #include<iostream>
    #include<cstring>
    using namespace std;

    template <class T>
    void print(T array[],int n){
        for (int i = 0; i < n; i++)
        {
            cout<<array[i]<<"\t";
        }
        cout<<endl;
    }

    void print(char array[],int n){//char 배열을 출력하기 위한 함수 중복
        for (int i = 0; i < n; i++)
        {
            cout<<(int)array[i]<<"\t";//array[i]를 int로 형변환하여 정수 출력
        }
        cout<<endl;
    }

    int main()
    {
        int x[]={1,2,3,4,5};
        double d[5]={1.1,2.2,3.3,4.4,5.5};
        print(x,5);
        print(d,5);

        char c[5]={1,2,3,4,5}; //템플릿 함수로부터 구체화
        print(c,5); //중복된 print()함수가 우선 바인딩
        return 0;
    }
    ```

* 제네릭 클래스 만들기(스택 클래스)
    1. 제네릭 클래스 선언
        ```cpp
        template <class T>
        class MyStack{
            int tos;
            T data [100];//T타입의 배열
            public:
                MyStack();
                void push(T element);
                T pop();
        };
        ```
    2. 제네릭 클래스 구현
        ```cpp
        template <class T>
        void MyStack<T>::push(T element){
            if (tos==99){
                cout<<"stack full";
                return;
            }
            tos++;
            data[tos]=element;
        }
        template <class T> 
        T MyStack<T>::pop(){
            T retData;
            if(tos==-1){
                cout<<"stack empty";
                return 0;//오류 표시
            }
            retData=data[tos--];
            return retData;
        }
        ```
    3. 클래스 구체화 및 객체 활용
        ```cpp
        MyStack <int> iStack;
        MyStack <double> dStack;

        iStack.push(3);
        int n=iStack.pop();

        dStack.push(3.5);
        double d=dStack.pop();
        ```
    + 그외 코드
        ```cpp 
        template <class T>
        MyStack<T>::MyStacl()//생성자
        {
            tos=-1;
        }

        int main(){
            //3.번 코드와 마지막 코드는 
            Mystack<char> *p=new MyStack<char>();
            p->push('a');
            cout<<p->pop()<<endl;
            delete p;
            return 0;
        }
        ```


