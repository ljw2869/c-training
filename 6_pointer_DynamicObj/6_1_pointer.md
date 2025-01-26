포인터
===================
+ 포인터에 null을 넣고 싶을 때 NULL이 아니라 nullptr로 넣는 것이 c++의 버전
```cpp
    int *p =nullptr;(O)
```
```c
    int *p=NULL;(X)
```
+ 널 값은 0으로 인식하기 때문에 만약 f(NULL)이렇게 반환하게 되면 f(int n), f(int *p)두 오버로드 함수 중에 어느 것으로 들어갈 지 혼동하게 됨
----------------------

동적 메모리 할당(dynaic memory allocation)
==================
+ 프로그램이 실행 도중에 동적으로 메모리를 할당받는 것 
+ 동적 메모리 영역은 heap영역에 할당이 됨 (정적-heap-사용가능 메모리-stack): 메모리 구조

+ c: malloc(size)-메모리 할당, free()-메모리 해제
+ cpp: new (동적 메모리 타입)-메모리 할당, delete()-메모리 해제
+ delete 구조 주의: delete []p : 이렇게 대괄호가 먼저 나옴
+ **반드시 동적 메모리에서는 할당을 해주었으면 꼭 반납도 해주어야 한다!**

```cpp
int *p;
p=new int[5];
```
위와 같이 코드를 작성하면 5칸이 생기기는 하지만, 안에 쓰레기 값이 들어가게 됨

```cpp
int *p = new int[5]{1,2,3,4,5};
```
위와 같이 하면 안에 바로 값이 담긴 5칸의 배열이 생성되게 됨

+ 스마트 포인터
    * 동적 메모리 할당 후 잊어버려도 자동으로 동적 메모리가 삭제됨
    * 스마트 포인터는 자동으로 nullptr로 초기화됨
    ```cpp
    unique_ptr<int> p(new int);

    *p = 99;
    ```
    *unique_ptr은 어떠한 자료형의 포인터도 감쌀 수 있다.

    ```cpp

    unique_ptr<int[]>buf(new int[10]);//정수형 배열을 가리키는 포인터
    for (int i=0;i<10;i++){
        buf[i]=i;
    }
    for (int i=0;i<10;i++)
    {
        cout<<buf[i]<<" ";
    }
    cout<<endl;
    //여기서 메모리 해제 코드를 넣지 않아도 알아서 해제해준다.
    ```
+ 객체의 동적 생성
```cpp 

class Dog{
    private:
        string name;
        int age;
    public:
        Dog(){
            age=1;
            name="바둑이";
        }
        ~Dog(){
            cout<<"소멸자 호출";
        }
        void setAge(int a){
            age=a;
        }
        int getAge(){
            return age;
        }
};

int main(){

    Dog *pDog=new Dog;// 객체도 다음과 같이 new를 사용해서 동적으로 생성할 수 있다.

    // 포인터를 통하여 멤버에 접근할 때는 -> 이 연산자를 사용해야 함
    cout<<"강아지 나이: "<<pDog->getAge()<<endl;
    pDog->setAge(5);
    cout<<"강아지의 나이: "<<pDog->getAge()<<endl;
    delete pDog;

    return 0;
}
```
***무조건 new가 있으면 쌍으로 delete가 있어야 한다!!!**
+ new -> 생성자 호출, delete-> 소멸자 호출

+ 멤버 동적 생성
    * 생성자에서 동적 할당
    * 소멸자에서 동적 메모리 해제

```cpp
class Dog{
    private:
        int *pWeight;
        int *pAge;
    public:
        Dog(){
            pAge = new int(1);
            pWeight = new int(10);
        }
        ~Dog(){
            delete pAge;
            delete pWeight;
        }
        int getAge(){return *pAge;}
        void setAge(int a){*pAge=a;}
        int getWeight(){return *pWeight;}
        void setWeight(int w){*pWeight=w;}
};

int main(){
    //main에서는 멤버 변수 pAge, pWeight가 포인터인 것을 인지 못함
    Dog* pDog=new Dog;
    cout<<"강아지의 나이: " << pDog->getAge()<<endl;

    pDog->setDog(5);
    cout<<"강아지의 나이: "<<pDog->getAge()<<endl;

    delete pDog;
    return 0;
}
```

+ 객체 포인터

```cpp
Circle donut;
double d=donut.getArea();

Circle *p;//객체 포인터
p = &donut;
d = p->getAgrea(); // 이런식으로 멤버에 접근하기 위해 ->연산자 사용
//(*p).getArea()이렇게 사용해도 되기는 하나 ->를 많이 사용함
```

+ 동적 메모리 할당 및 반환
    * 정적 할당: 변수 선언을 통해 필요한 메모리 할당
        ex: int a, circle d;
        - malloc()/free()
    * 동적 할당: 필요 양이 예측되지 않는 경우
        - 실행 중에 힙(heap) 메모리에서 할당
         **힙은 운영체제가 프로세스(프로그램)의 실행을 시작 시킬 때 동적 할당 공간으로 준 메모리 공간**
        
        - new 연산자
        - delete 연산자

        ###### 사용 예시

        ```cpp
        int *pint = new int;
        char *pchar = new char;
        Circle *pCircle = new Circle();

        delete pint;
        delete pchar;
        delete pCircle;
        ```

        ***주의할 점은 포인터의 공간을 해제시켜주는 delete를 쓰면 이제 그 공간에 접근할 수 없음, 다만 포인터는 살아있음**
        ex-
        ```cpp
        int *p=new int;
        *p=5;
        delete p;
        //이렇게 하면 p라는 포인터는 살아있지만, p가 가리키는 곳에 접근하면 안됨
        ```

        
    + 만약 메모리 할당에 실패하게 된다면 포인터에 NULL값이 들어가게 됨
    ex-
    ```cpp
    p = new int;
    if(!p){ // NULL = false, !NULL = true
        cout<<"메모리를 할당할 수 없습니다.";
        return 0;
    }
    *p = 5;
    int n=*p;
    cout<<"*p = "<< *p << endl;
    cout<< "n = "<< n << endl;
    delete p;
    ```

**delete 사용시 주의할 점**

+ 적절하지 않은 포인터로 delete하면 실행시간 오류 발생
    ex: 

    ```cpp
    
    // 1. 동적으로 할당 받지 않은 메모리 반환
    int n;
    int *p = &n;
    delete p;
    //포인터가 가리키는 메모리는 동적으로 할당받은 것이 아님!! 
    //new와 함께 delete를 사용할 수 있는 것임!

    // 2. 동일한 메모리 두 번 반환
    int *p= new int;
    delete p;
    delete p;
    ```
    


