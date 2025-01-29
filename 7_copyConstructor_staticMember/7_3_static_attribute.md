7.3 static 속성의 이해
=========================
#### 정적 변수
+ 정적 변수는 static을 붙여서 선언하는 변수로, **클래스마다 하나만 생성**
+ 클래스의 모든 객체가 하나의 변수를 공유

+ 변수와 함수에 대한 기억 부류의 한 종류
    * 생멍 주기: 프로그램 시작될 때 생성~ 프로그램 종료 시 소멸
    * 사용 범위: 선언된 범위, 접근 지정에 따름


- 클래스의 멤버 2가지
    + static 멤버
        * 프로그램이 시작할 때 생성
        * 클래스 당 하나만 생성, **클래스 멤버**라고 불림
        * 클래스의 모든 인스턴스(객체)들이 공유하는 멤버
    + non-static 멤버
        * 객체가 생성될 때 함께 생성
        * 객체마다 객체 내에 생성
        * **인스턴스 멤버**라고 불림
    
```cpp
//정적 변수 예제
class Circle{
    int x,y;
    int radius;

    public:
        static int count;// 정적 변수
        Circle():x{0},y{0},radius{0}{
            count++;
        }
        Circle(int x,int y,int r):x{x},y{y},radius{r}{
            count++;
        }
        ~Circle(){
            count--;
        }
        //정적 멤버 함수
        static int getCount(){
            return count;
        }
};

int Circle::count = 0; // 정적 변수의 초기화는 전역 변수와 비슷하게 클래스 외부에서 수행

int main(){
    Circle c1;
    cout<<"지금까지 생성된 원의 개수: "<<Circle::count<<endl;// 1
    Circle c2(100,100,30);//count변수는 생성자에서 2번 증가
    cout<<"지금까지 생성된 원의 개수: "<<Circle::getCount()<<endl;// 2
    //위의 코드를 통해 정적 멤버 함수 호출도 가능한 것을 확인
    //객체마다 공유하는 정적 변수
    //정적 멤버 변수와 함수 모두 클래스 명으로 불러오는 것(호출)을 확인
    return 0;
}
```

+ static 멤버 선언
    * 클래스 멤버와 함수 앞에 static이 적혀 있지 않으면 non-static 멤버 선언
    * 클래스 선언 블록 밖에 static 변수 공간을 할당 해 놓아서 프로그램 전역 공간에 선언 (초기화)
    * static 멤버 변수 생성
        - 전역 변수로 생성
        - 전체 프로그램 내에 한 번만 생성
    * static 멤버 변수에 대한 외부 선언이 없으면 링크 오류
        - **그렇기 때문에 클래스 선언부 밖에서 초기화 하는 부분의 코드가 꼭 있어야 함!!!**
+ static 멤버와 non-static 멤버 비교
    |항목|non-static 멤버|static 멤버|
    |------|---------|---------|
    |공간의 특성|멤버는 객체마다 별도 생성(인스턴스 멤버)|멤버는 클래스 당 하나 생성(객체 내부 아닌 별도 공간에 생성, 클래스 멤버)|
    |시간적 특성| 객체와 생명을 같이 함(객체 생성, 소멸시간과 같음, 객체 생성 후 사용 가능)|프로그램과 생명을 같이 함(프로그램 생성 시 생성, **객체 없어도 이미 존재**, 프로그램 종료 시 소멸)|
    |공유의 특성|공유되지 않고 멤버는 객체 별로 따로 공간 유지|동일한 클래스의 모든 객체들에 의해 공유됨|
+ static 멤버는 객체 이름이나 객체 포인터로 접근
    * 보통 멤버처럼 접근할 수 있음
    ```cpp
    Person lee;
    lee.sharedMoney=500;//객체.static 멤버 방식

    Person *p;
    p=&lee;
    p->addShared(200);//객체포인터->static 멤버 방식
    ```

+ static 멤버 사용: 클래스명과 범위 지정 연산자(::)로 접근
    - static 멤버는 클래스마다 오직 한 개만 생성되기 때문
        > lee.addShared(200); == Person::addShared(200);
    - non-static 멤버는 클래스 이름으로 접근 불가
        > Person::money=100;  (X)
    ```cpp
    class Person{
        public:
            int money;
            void addMoney(int money){
                this->money += money;
            }
        static int sharedMoney;
        static void addShared(int n){
            sharedMoney +=n;
        }
    };
    // static 변수 생성, 전역 공간에 생성
    int Person::sharedMoney=10;//10으로 초기화
    int main(){
        Person::addShared(60);
        cout<<Person::sharedMoney<<endl;//static멤버 접근, 공급=60

        Person han;
        han.money=100;
        han.sharedMoney=200;//정적 멤버 접근, 공급 200
        Person::sharedMoney=300;//공급 300
        Person::addShared(100);//공급 400
        cout<<han.money<<" "<<Person::sharedMoney<<endl;
        return 0;
    }
    ```
    
+ static의 주요 활용
    - 전역 변수나 전역 함수를 클래스에 캡슐화
        * 전역 변수나 전역 함수를 가능한 사용하지 않도록
        * 전역 변수나 전역 함수를 static으로 선언하여 클래스 멤버로 선언

    - 객체 사이에 공유 변수를 만들고자 할 때
        * static 멤버를 선언하여 모든 객체들이 공유

    ```cpp
    class Math{
        public:
            static int abs(int a){ return a>0?a:-a;}
            static int max(int a,int b){return (a>b)?a:b;}
            static int min(int a,int b){return (a>b)?b:a;}
    };
    int main(){
        cout<<Math::abs(-5)<<endl;
        cout<<Math::max(10,8)<<endl;
        cout<<Math::min(-3,-8)<<endl;
        return 0;
    }
    ```
    ```cpp
    class Circle
    {
        ...
        private:
            static int numOfCircles;
            int radius;
        public:
            ...
            ~Circle(){ numOfCircles--;}
            ...
            static int getNumOfCircles( return numOfCircles;)
    };
    Circle::Circle(int r){
        radius=r;
        numOfCircles++;
    }
    int Circle::numOfCircles=0;// 중요: 꼭 밖에서 0으로 초기화해주어야 한다!

    int main(){
        Circle *p=new Circle[10];//10개의 생성자 실행
        cout<<Circle::getNumOfCircles()<<endl;//10

        delete []p;
        cout<<Circle::getNumOfCircles()<<endl;//0

        Circle c;
        cout<<Circle::getNumOfCircles()<<endl;//1
        Circle c2;
        cout<<Circle::getNumOfCircles()<<endl;//2

        return 0;
    }
    ```

+ static 멤버함수는 static멤버만 접근 가능!!
    static 멤버함수가 접근할 수 있는 것
    * static 멤버 함수
    * static 멤버 변수
    * 함수 내 지역 변수

    **static 멤버 함수는 non-static멤버에 접근 불가**
        - 객체가 생성되지 않은 시점에서 static 멤버 함수가 호출될 수 있기 때문!!
    예시:
        ```cpp
        private:
            int money;
        public:
            static int getMoney(){return money;}//static멤버 함수는 non-static멤버에 접근할 수 없음
        ```
    
    **반면에 non-static 멤버 함수는 static에 접근 가능**
    ```cpp
    class Person{
        public:
            int money;
            static int sharedMoney;
            ...
            int total(){
                return money+sharedMoney;
            }
    };
    ```

    static 멤버 함수에서 this 사용 불가
