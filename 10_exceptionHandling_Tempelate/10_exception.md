10.1 예외 처리
=======================
+ 오류
    - 컴파일 오류(syntax error)
        * 문법에 맞지 않는 구문으로 인한 오류
    - 실행 오류(runtime error)
        * 개발자의 논리 오류
        * 예외적으로 발생하는 입력이나 상황에 대한 대처가 없을 때 발생하는 오류
            > 숫자 입력->문자를 입력, 0을 나누는 경우, 배열 인덱스 접근 오류
        * 실행 오류의 결과
            + 결과가 틀리거나 엉뚱한 코드 실행, 프로그램이 비정상 종료
+ 예외
    우리가 당연하다고 가정한 상황이 거짓이 되는 경우
    - 컴퓨터에 사용 가능한 메모리가 부족한 경우
    - 당연히 있을 거라 생각한 파일이 없는 경우
    - 사용자가 잘못된 값을 입력하는 경우

    * 예외 처리
        위와 같은 상황이 발생한 경우에도 프로그램이 올바르게 동작할 수 있도록 처리

+ 예외 처리 기본 형식
    **try-throw-catch**
    - try {}블록
        * 예외가 발생할 가능성이 있는 코드를 묶음
    - throw문
        * 발견된 예외를 처리하기 위해, 예외 발생을 알리는 문장
        * try{}블록 내에서 이루어져야 함
    - catch() {}블록
        * throw에 의해 발생한 예외를 처리하는 코드
    
    ```cpp
        try{
            //예외가 발생할 수 있는 코드
            if (예외가 발생하면)
                throw exception;
        }
        catch(예외 타입 매개변수 exception ex){
            //예외를 처리하는 코드
        }
    ```
    
    > throw 에서 던지면 catch에서 받아서 처리
    > 예외가 발생하면 try 블록의 나머지 부분 무시(try블록 안, throw아래 부분 무시)
    > 예외 처리 후 catch 블록 이후부터 실행(catch블록 실행 후 main안 코드 계속 실행)

    ```cpp
    #include<iostream>
    using namespace std;

    int main()
    {
        int pizza_slices=0;
        int person=-1;
        int slice_per_person=0;

        try{
            cout<<"피자 조각 수를 입력하시오:";
            cin>>pizza_slices;
            cout<<"사람 수를 입력하시오: ";
            cin>>person;
            if (person==0) throw person; //이 던져지는 person의 <타입>에 따라서 매개변수 catch문에 따라가게 된다.
            slice_per_person=pizza_slices/person; //예외가 발생했다면 이 후의 try블록 안의 코드는 실행되지 않음 
            cout<<"한사람당 피자는 "<<slice_per_person<<"입니다."<<endl;
        }
        catch(int e){
            cout<<"사람이  "<<e<<"명 입니다."<<endl;
            
        }//예외가 발생하지 않는 경우 catch문은 수행되지 않게 됨
        return 0;
    }
    ```

+ 예외 전달
    예외는 함수를 넘어서 전달될 수 있다.
    ```cpp
    int dividePizza(int s,int p){
        if (person==0)
            throw person;//여기 throw에서 아래 catch문으로 전달가능
        ...
    }
    int main(){
        try{
            dividePizza(slices,persons)
        }
        catch(int e){
            cout<<"예외 발생";
        }
    }
    ```
+ 다중 catch 문장
    try 안에 발생할 수 있는 예외가 여러 종류일 때 catch를 여러 개 만들 수 있음

**구체적인 예외를 먼저 잡는다**
    ```cpp
    try{

    }
    catch(TooSmallException e){
        //TooSmallException만 잡힌다
    }
    catch(...){
        //TooSmallException을 제외한 나머지 예외들이 잡힌다
    }
    ```
+ 다중 try{} 블록 내에 try{}블록의 중첩 가능
    안쪽의 throw문에서 걸렸을 때 가장 try와 동등한 위치에 있는 try를 먼저 확인하고 연결할 수 없는 매개변수형태밖에 없다면 try밖으로 나가서 연결된 catch블록으로 점프한다
+ 주의 사항
    - throw문의 위치
        * 항상 try() 블록 안에서 실행되어야 함
        * 시스템이 abort()호출, 강제 종료

    - 예외를 처리할 catch()가 없으면 프로그램 강제 종료

    - catch(){}블록 내에도 try{} catch(){}블록 선언 가능
    - 하나의 try 블록에 다수의 catch블록 연결 가능
    - 발생하는 모든 타입의 catch문이 다 있어야지만 정상적 종료 가능
    - 함수를 포함하는 try블록
+ 예외를 발생시키는 함수의 선언
    함수 원형에 연이어 throw(예외 타입, 예외타입, ...)선언
    ```cpp
    int max(int x,int y)throw(int){
        if(x<0) throw x;
        else if(y<0) throw y; //모두 int 타입 예외 발생
        else if (x>y)return x;
        else return y;
    }
    double valueAt(double *p, int index)throw(int ,char*){
        if (index<0)
            throw "index out of bounds exception";//char * 타입 예외 발생
        else if (p==NULL)
            throw 0; //int 타입 예외 발생
        else
            return p[index];
    }
    ```
    함수의 header = interface 부분에 예외도 선언할 수 있다는 것임
    장점: 프로그램 작동 명확히 하고 가독성을 높임

+ 예외 클래스 만들기
    - 예외 값의 종류
        * 기본 타입의 예외 값: 정수 실수 문자열 등 비교적 간단한 예외정보 전달
        * 객체 예외 값: 예외 값으로 객체를 던질 수 있음, 예외 값으로 사용할 예외 클래스 작성 필요
    - 예외 클래스
        * 사용자는 자신 만의 예외 정보를 포함하는 클래스 작성
        * throw로 객체를 던짐
        * 객체가 복사되어서 예외 파라미터에 전달





