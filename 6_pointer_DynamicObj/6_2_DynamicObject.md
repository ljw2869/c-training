6_2.객체의 동적 생성과 반환
==========================

+ new/delete 연산자 사용 형식(배열)

    ```cpp
    int *p = new int[5];

    for (int i=0; i<5; i++)
        p[i] = i;

    delete []p; //배열 대괄호가 먼저!
    ```
+ 동적 할당 메모리 초기화
    ```cpp
    int *pint = new int(20);//이렇게 하면 20이 담긴 int형 메모리 공간을 가리키는 포인터가 만들어지게 됨
    char *pchar = new char('a');

    //배열은 동적 할당 시 초기화 불가능
    int *pArray = new int[10](20);//(X)
    int *pArray = new int(20)[10];//(X)
    int *p = new int[5]{1,2,3,4,5}; //OK

    ```
+ delete 시 [] 생략하면 비정상적인 반환이 됨

+ 객체의 동적 생성 및 반환
    ```cpp
    Circle *p = new Circle; //이렇게 하면 기본 생성자가 호출
    Circle *q = new Circle(30);

    delete p;
    delete q;
    ```
    * 객체를 생성한 순서와 관계 없이 원하는 순서대로 delete 할 수 있음
+ 객체 배열의 동적 생성 및 반환
    > 클래스 이름 *포인터 변수 = new 클래스 이름 [배열 크기]

    ```cpp
    Circle *pArray = new Circle[3];

    pArray[0].setRadius(10);
    //pArray->setRadisu(10);이것도 같은 코드가 됨

    pArray[1].setRadius(20);
    //(pArray+1)->setRadius(20);이것도 같은 역할의 코드

    //아니면 p가 가리키고 있는 주소이기 때문에 for문과 같이 pArray++로 순서대로 접근 가능

    delete [] pArray; //소멸 순서는 pArray[2]->[1]->[0] 소멸자 실행
    ```
    * 동적으로 생성된 배열도 보통 배열처럼 사용
    
+ 동적 메모리 할당과 메모리 누수
    ```cpp
    char n='a';
    char *p=new char[1024];
    p=&n;
    // 이렇게 다른 곳을 가리키게 되면 char[1024]의 메모리는 가리키는 것이 없어서 반환할 수도 없고 사용하지도 않는 누수 메모리가 됨

    char *p;
    for (int i=0;<100000;i++)
        p = new char [1024];
    // 위 코드도 마찬가지로 char [1024]의 공간을 for문을 돌며 만들기만 하고 다시 다른 걸 만들어 가리키는 것을 반복하면 메모리 누수 발생
    ```
