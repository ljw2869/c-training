6_3_this 포인터와 문자열 응용
===========================
### this
--------------
- 포인터, 객체 자신 포인터
- 클래스의 멤버 함수 내에서만 사용
- 컴파일러가 선언한 변수, 멤버 함수에 컴파일러에 의해 묵시적으로 삽입 선언되는 매개 변수
사용 예시: 
```cpp
class Circle{
    int radius;
    public:
        Circle(){ this->radius = 1;}
        Circle(int radius){this->radius = radius;} 
        void setRadius(int radius){this->radius = radius;}
        //위와 같이 멤버 변수명과 매개 변수 명이 같을 때 구분해주기 위해 this->를 사용함
};
```
- 현재 객체를 참조하는 포인터
    
    예시:

    ```cpp
    class Rectangle{
        private:
            int length;
            int width;
        public:
            Rectangle(){
                width=30;
                length=40;
            }
            ~Rectangle(){}
            void setLength(int length){this->length=length;}
            void getLength(){return this->length;}//여기서는 this->가 없어도 컴파일러가 자동으로 붙여줌
    }
    ```
    
- 각 객체 속의 this는 다른 객체의 this와 다름

#### this가 필요한 경우
- 매개 변수의 이름과 멤버 변수의 이름이 같은 경우
```cpp
Circle (int radius){
    this->radius=radius; //radius=radius;라고 하면 이게 어떤 건지 인식을 못하기 때문
};
```
- 멤버 함수가 객체 자신의 주소를 리턴할 때 
    * 연산자 중복 시에 매우 필요
    ```cpp
    class Sample{
        public:
            Sample*f(){
                ///
                return this;
            //자기 자신을 리턴해주고 싶을 때!!!! -실습이나 예시를 통해 확인하는 게 좋을 듯
            }
    };
    ```

#### this 의 제약 사항
+ 멤버 함수가 아닌 함수에서 this사용 불가
+ static 멤버 함수에서 this사용 불가
    - 객체가 생기기 전에 static함수 호출이 있을 수 있어서
    - static이라고 적는 순간 static외부 변수와 비슷하게 static클래스가 모든 클래스와 공유하게 됨

```cpp
class Sample{
        int a;
        public:
            void setA(int x){
                this->a=x;
            }
            // void setA(Sample*this,int x){
            //     this->a=x;
            // }
            //위의 코드가 컴파일러에 의해 알아서 변환된 클래스
    }
int main(){
    Sample(ob);
    ob.setA(5);=====ob.set(&ob,5);
    return 0;
}
```

-------------------------------------------
### string 클래스를 이용한 문자열 

+ string 헤더파일 선언 #include<string>
+ 가변 크기의 문자열
    * c에서는 char c[100];처럼 가변 길이로 작성을 해야 했는데
    * string str="love"; str.append("c++");이렇게 하면 문자열이 길어진다.

    
+ 문자열 생성 예시
    ```cpp
    #include<string>

    string str;//빈 문자열을 가진 스트링 객체
    string address("서울시 강남구");
    string copyAddress(address);//복사한 문자열 생성

    //c스트링(char 배열)로 스트링 객체 생성
    char text[]={'L','o','v','e','\0'};
    string title(text);//이렇게 되면 알아서 위의 문자들이 합쳐진 문자열을 만들 수 있음

    ```
+ 문자열 숫자 변환: stoi()함수 사용
    * 예전에는 atoi()를 사용했으나, 2011 cpp표준부터 stoi()사용

    ```cpp
    string s="123";
    int n = stoi(s);
    ```
+ new/delete 를 이용하여 문자열을 동적 생성/반환 가능

    ```cpp
    string *p=new string("C++");
    cout<<*p;
    p->append("Great!");
    cout<<*p;
    delete p;
    ```
    _참고로 getline(cin.names[i],'\n');이 함수를 이용해서 문자열을 입력받을 수 있음_

+ 문자열을 입력받고 한 문자씩 왼쪽으로 회전하는 프로그램
    ```cpp
    string s;

    getline(cin,s,'\n');//문자열 입력

    int len = s.length();

    for(int i=0;i<len;i++){
        string first=s.substr(0,1);//맨 앞의 문자 1개를 문자열로 분리
        string sub-s.substr(1,len-1);
        s=sub+first;//새로 재배치헤서 만들어주기
        cout<<s<<endl;
    }
    ```
    **위의 예제에서 주목할 점은 문자열 입력과 substr(start,length)의 내장 함수 사용이다!**
    **그리고 string클래스는 내부적으로 null-terminated 문자열을 관리한다, 그래서 객체를 사용해 문자열을 조작할 때 null문자를 신경 쓸 필요가 없음!!!**

    * substr()함수
        - 인수로 아무 것도 전달하지 않으면 원본 문자열 그대로 반환
        - 인수로 시작 인덱스만 전달한다면 해당 인덱스~문자열 마지막 까지 반환
        - 지정된 범위가 원본 문자열 길이를 벗어나면 오류 없이 문자열 마지막까지만 반환

+ 덧셈 문자열을 입력 받아 덧셈 실행하는 프로그램
    ```cpp
    
    #include<iostream>
    #include<string>

    using namespace std;

    int main()
    {
        string s;
        cout<<"7+23+5+100+25와 같이 덧셈 문자열을 입력하세요."<<endl;
        getline(cin, s,'\n');
        int sum=0;
        int startIndex=0;
        while(true){
            int fIndex=s.find('+',startIndex); //find함수에서 두번째 pos인자가 주어지면 pos번째 문자부터 찾는다
            if(fIndex==-1){
                // sum+=stoi(s.substr(startIndex)); //이 코드는 항상 완벽히 입력했을 때 괜찮음
                // break;
                string part=s.substr(startIndex);
                if(part=="")break;//2+3+로 끝나는 경우
                cout<<part<<endl;//위의 상황이 아닌 경우 마지막 숫자인 경우임(출력)
                sum+=stoi(part);//마지막 숫자를 더함
                break;
            }
            int count=fIndex-startIndex;//서브 스트링으로 자를 문자 개수
            string part=s.substr(startIndex,count);
            cout<<part<<endl;//앞에서 자른 숫자가 있는 문자열 출력
            sum+=stoi(part);//자른 숫자를 더함
            startIndex=fIndex+1;//다음 +부터 시작(+1을 더한 이유는 +를 제외하기 위함)
        }
        cout<<"합은 "<<sum<<"입니다."<<endl;
        return 0;
    }
    ```
+ 문자열 find 및 replace
```cpp
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    cout<<"여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다."<<endl;
    getline(cin, s, '&');
    cin.ignore();
    string f,r;
    cout<<endl<<"find: ";
    getline(cin, f,'\n');
    cout<<"replace: ";
    getline(cin, r,'\n');

    int startIndex=0;
    while(true){ //문장에 f가 없을 때까지 반복
        int fIndex=s.find(f, startIndex);
        if(fIndex==string::npos) //같은 표현으로 if(fIndex==-1) break;도 가능
        break;
        s.replace(fIndex, f.length(), r); //replace(교체하고 싶은 문자열의 위치, 교체하고 싶은 문자열의 길이, 새로운 문자열)
        startIndex=fIndex+r.length();
    }
    cout<<s<<endl;
    return 0;
}
```
+ const 포인터 (여기가 좀 어려움...)

    ```cpp
    const int *p1;  // 1
    int *const p2; // 2
    const int *const p3; // 3
    ```
    p1은 변경되지 않는 정수를 가리키는 포인터로, 이 포인터를 통해 참조되는 값은 변경 불가 ex:  *p=5 불가능

    p2는 정수에 대한 상수 포인터, 정수는 변경될 수 있지만 p2는 다른 것을 가리킬 수 없음   ex: 

        p2=&a; //(X)

    p3는 상수에 대한 상수 포인터, 포인터가 가리키는 값도 변경 불가, p3도 다른 것을 가리킬 수 없음

    * 멤버 함수를 const로 정의하면 함수 안에서 멤버 변수를 변경하는 것이 금지 => 임의로 값을 바꾸는 것을 막고 싶고 참조만 하고 싶을 때 const선언을 해주면 됨

    * const 객체를 가리키는 포인터를 정의하면 이 포인터로 호출할 수 있는 함수는 const함수 뿐이다.
    ```cpp
        int getRadius() const{return radius;} //멤버 변수 변경 불가
        ...
        const Circle *pConstObj=new Circle();//Constant Circle을 가리키도록 선언, 멤버 변수를 변경하는 멤버 함수 호출 불가 = set함수 호출 불가
        Circle *const pConstPtr=new Circle();//Circle에 대한 상수 포인터로 선언됨, 다른 객체를 가리킬 수 없다. 객체는 변경 가능
    ```



    

