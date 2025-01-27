7_2_얕은 복사와 깊은 복사
=======================
+ 얕은 복사
    * 객체 복사 시, 객체의 멤버를 1:1로 복사
    * 객체의 멤버 변수에 동적 메모리가 할당된 경우 사본은 원본 객체가 할당 받은 메모리 공유 문제 발생

+ 깊은 복사
    * 객체 복사 시, 객체의 멤버를 1:1로 복사
    * 객체의 멤버 변쉥 동적 메모리가 할당된 경우
        - 사본은 원본이 가진 메모리 크기만큼 별도로 동적 할당!!!
        - 원본의 동적 메모리에 있는 내용을 사본에 복사
    * 완전한 형태의 복사
        - 사본과 원본은 메모리를 고유하는 문제 없음

    * 이것을 원할 때는 반드시 복사생성자를 정의해주어야 함
    * 반드시 참조형으로 만들어주어야 함

+ 복사 생성자(copy constructure)
    * 한 클래스에 오직 한 개만 선언 가능
    * 복사 생성자는 보통 생성자와 클래스 내에 중복 선언 가능
    * 클래스에 대한 참조 매개 변수를 가지는 독특한 생성자
    ```cpp
    Circle(const Circle& c){//복사 생성자 선언
    // 자기 클래스에 대한 참조 매개 변수
    };

    Circle::Circle(const Circle& c){//복사 생성자 구현

    }
    ```
    ```cpp
    #include<iostream>
    using namespace std;

    class Circle{
        private:
            int radius;
        public:
            Circle(const Circle& c);
            Circle(){radius=1;}
            Circle(int radius){this->radius=radius;}
            double getArea(){return 3.14*radius*radius;}
    };

    Circle::Circle(const Circle& c){
        radius=c.radius;
        cout<<"Copy constructor called."<<endl;//복사 생성자 실행
    }

    int main()
    {
        Circle src(30);
        Circle dest(src);

        cout<<"원본의 면적 ="<<src.getArea()<<endl;
        cout<<"사본의 면적 ="<<dest.getArea()<<endl;
        return 0;
    }
    ```
    * 복사 생성자가 선언되어 있지 않은 클래스의 경우 컴파일러가 자동으로 디폴트 복사 생성자 삽입
    * 디폴트는 클래스 이름(const 클래스 이름& 다른 참조 이름){ 각 매개변수 값들을 옮겨줌}

    * 얕은 복사의 문제점은 멤버변수 중 동적으로 할당받은 문자열을 공유했을 때 
        1. 하나가 바뀌면 다른 값도 똑같이 바뀌고
        2. **소멸자에서 delete[]name(배열 명)이렇게 해주면 두번 해제되면서 오류가 발생**
    ```cpp
    Person::Person(const Person& person){
        this->id=person.id;
        int len=strlen(person.name);
        this->name=new char(len+1);//name을 위한 공간 따로 할당
        strcpy(this->name,person.name);
    }
    ```
    위와 같이 의식적으로 공간을 만들어서 복사하는 과정이 필요
    + 묵시적 복사 생성에 의해 복사 생성자가 자동 호출되는 경우
        1. 객체로 초기화하여 객체가 생성될 때
        2. 값에 의한 호출로 객체가 전달될 때
        3. 함수에서 객체를 리턴할 때 (복사본의 복사 생성자 호출)
    * 복사생성자(copy constructor)
        + 동일한 클래스의 객체를 복사하여 객체를 생성할 때 사용하는 생성자

        **복사생성자 선언하는 경우**
        1. 같은 종류의 객체로 초기화하는 경우(혹은 대입)
            ```cpp
            myclass ob1;
            myclass ob2(ob1);
            ```
        2. 객체를 함수에 전달하는 경우
        ```cpp
        myclass func(myclass obj){

        }
        ```
        3. 함수가 객체를 반환하는 경우
        ```cpp
        myclass func(myclass obj){
            myclass tmp;
            return tmp;
        }
        ```
        ```cpp
        person kim(21);
        person clone{kim};//복사 생성자 호출
        ```
        **여기서 복사할 때 소괄호가 아니라 중괄호를 사용**
        **멤버 변수 중에서 포인터 변수가 있는 경우에 복사생성자가 필요**

        ```cpp
        int main(){
            myArray buffer(10);
            buffer.data[0]=1;
            {
                myArray clone=buffer;
            }
            buffer.data[0]=2;//여기서 오류가 발생함
            //{}이 사이에 clone이 받았는데, 빠져나오고 소멸자가 호출이 되면 buffer가 공유하고 있던 공간도 해제되어
            //다음 buffer에 접근하려고 하면 공간에 해제되어 접근 오류가 발생
        }
        ```

#### 객체와 연산자
- 객체끼리 복사 가능
    ```cpp
    obj2=obj1;
    ```
- 비교연산자
    ```cpp
    if(obj1==obj2)//이런게 안됨
    //나중에 연산자 오버로딩(재정의)을 해주어야 사용 가능
    ```
+ is-a관계
    - 상속 기반
+ has-a관계
    - 하나의 객체가 다른 객체를 가지고 있는 관계
    ```cpp
    class Date{
        int year,month,day;
    };
    class Person{
        string name;
        Date birth; //has-a관계
    };
    int main(){
        Date d{1998,3,1};
        Person p{"김철수",d};
        p.print();
        return 0;
    }
    ```
