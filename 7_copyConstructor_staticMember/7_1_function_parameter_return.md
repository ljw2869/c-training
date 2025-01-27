7_1_함수의 객체전달방법 및 반환 방법
=====================================
#### 함수로 객체 전달하기
* 값에 의한 호출(call-by-value)
    + 호출하는 코드에서 넘어온 값이 매개변수에 복사됨
* 주소에 의한 호출(call-by-value)
    + 함수의 매개변수는 포인터 타입
    + 호출하는 코드에서는 명시적으로 주소를 넘겨줌
        - 변수나 객체는 주소 전달, 배열은 배열의 이름
        - 호출하는 코드에서 넘어온 주소 값이 매개변수에 저장됨
        ```cpp
        void swap(int *a,int *b){
            int tmp;

            tmp=*a;
            *a=*b;
            *b=tmp;
        }
        int main()
        {
            int m=2,n=9;
            swap(&m,&n);
            return 0;
        }
        ```
* 참조에 의한 호출(call-by-reference)

#### 객체 치환 및 객체 리턴
* 객체 치환
    ```cpp
    Circle c1(5);
    Circle c2(20);
    c1=c2;// c2객체를 c1객체에 비트 단위 복사해서 c1의 반지름이 30이 되나, 치환된 두 객체는 현재 내용물만 같을 뿐 독립적인 공간을 유지하고 있다.
    ```
* 객체 리턴
    - 객체의 복사본 리턴
    ```cpp
    //아래의 함수는 그냥 return type이 Circle인 함수(클래스 내의 함수 외부 정의 아님!)
    Circle getCircle(){
        Circle tmp(30);
        return tmp;
    }
    int main(){
        Circle c;
        c=getCircle(); // tmp객체의 복사본이 c에 치환됨, c의 반지름은 30이 됨
        return 0;
    }
    ```
    - 객체를 함수 매개변수로 전달
        + call-by-value와 같이 클래스의 값이 변하지 않고 복사본만 바뀐 채로 함수가 사라지면 없어지는 클래스가 만들어진다. 그래서 클래스를 넘겨주고 main에 출력해보면 변경되지 않은 것을 확인할 수 있다.

    - 객체의 주소를 함수로 전달
        ```cpp
        void upgrade(Pizza *p){
            p->setRadius(20);
        }
        int main(){
            Pizza obj(10);
            upgrade(&obj);

            obj.print(); //값이 변경되어 출력된 것을 확인
            return 0;
        }
        ```
        + 객체가 복사하지 않아도 돼서 시간 소모가 줄어듦
        + 하지만 반대로 원본 객체의 내용을 조작할 수 있어 의도하지 않은 훼손 가능성

#### 참조 변수 
+ 참조 변수 선언
    * 참조자 &의 도입
    * 이미 존재하는 변수에 대한 다른 이름(별명)을 선언
    * 이름만 생기며, 새로운 공간을 할당하지 않음, 초기화로 지정된 기존 변수를 공유

    ```cpp
    int n=2;
    int &refn=n;
    refn=3;//이렇게 하면 한 공간에 이름이 두개인 것이라서 n과 refn이 이름인 공간 안의 값이 3으로 변경된다.

    Circle c;
    Circle &refc=c;
    refc.setRadius(30);//안의 반지름 값이 30으로 변경된다.
    ```

+ 참조에 의한 호출
    * **참조를 가장 많이 활용하는 사례**
    * call-by-reference
    * 함수의 매개변수를 참조타입으로 선언
        - 참조 매개변수(reference parameter)라고 부름
            + 이때, 참조 매개변수는 실인자 변수를 참조함
        - 참조매개 변수의 이름만 생기고 공간이 생기지 않음
        - 참조매개 변수는 실인자 변수 공간 공유
        - 참조매개 변수에 대한 조작은 실인자 변수 조작 효과

    ```cpp
    void upgrade(Pizza &pizza){ // 참조자를 매개변수로 사용
        pizza.setRadius(20);
    }
    int main(){
        Pizza obj(10);
        upgrade(obj);// 참조자를 통해 원본 객체 변경 가능

        obj.print()
        return 0;
    }
    ```
    앞에서 call-by-adress는 안의 값이 바뀌는 효과가 있지만 따로 포인터 공간을 만들어줘야 했다. 
    하지만 아래와 같이 참조를 사용하면 공간을 따로 만들어주지 않아도 됨

    ```cpp
    void swap(int &a,int &b){  // 참조 매개 변수를 보통 변수처럼 사용
        int tmp;
        tmp=a;
        a=b;
        b=tmp;
    }
    int main(){
        int m=2,n=9;
        swap(m,n);
        cout<<m<<' '<<n;
        return 0;
    }
    ```
    **즉, 참조는 이름만 생성할 뿐, 변수 공간이 생기지 않고, 참조자를 통해 원본의 내용을 변경할 수 있다!**

    + 참조가 필요한 상황 예시
        >만약 배열의 평균을 구해서, 오류가 발생하면 0반환, 그 외는 평균을 리턴하는데 0을 반환했다면 그게 평균값인지 오류인지 구별할 수 없는 문제 발생
        
        **값과 잘 동작했는지 확인하고 싶을 때 여러 개의 값을 돌려주어야 한다면 address도 가능하지만 참조도 효과적인 방식**
        예제 코드
        ```cpp
        #include<iostream>


        using namespace std;

        bool average(int a[],int size,int &avg){
            if (size<=0)
                return false;
            int sum=0;
            for (int i=0;i<size;i++){
                sum+=a[i];
            }
            avg=sum/size;
            return true; 
            // 이 함수 자체에서는 성공 여부를 return하고, 참조 매개변수를 통해 평균을 리턴
        }
        int main()
        {
            
            int x[]={0,1,2,3,4,5};
            int avg;
            if(average(x,6,avg))cout<<"평균은 "<<avg<<endl;
            else cout<<"배열의 크기가 0이거나 음수입니다."<<endl;
            
            if (average(x,-2,avg))
                cout<<"평균은 "<<avg<<endl;
            else cout<<"배열의 크기가 0이거나 음수입니다."<<endl;
            return 0;
        }
        ```

        + 참조에 의한 호출로 circle객체에 참조 전달
        ```cpp
        void increaseCircle(Circle &c){
            int r=c.getRadius();
            c.setRadius(r+1);
        }
        int main(){
            Circle waffle(30);
            increaseCircle(waffle);
            cout<<waffle.getRadius()<<endl;
        }
        ```
    * 참조 리턴
        c언어에서는 함수는 반드시 값만 리턴 가능 ex: c=f(x)만 가능
        cpp에서는 함수가 값 외에 참조 리턴 가능, 즉 현존하는 공간에 대한 참조 리턴, 변수의 값을 리턴하는 것이 아님 ex: f()=3도 가능 (참조가 반환되면)

        **아래 코드 예시 중요**
        ```cpp
        char c='a';
        char & find(){//char 타입의 참조 리턴
            *return c;//변수 c에 대한 참조 리턴
        }
        char a=find();//a='a'가 됨
        char &ref=find()//ref는 c에 대한 참조
        ref='M';//c='M';
        find()='b';//c='b'; 
        //find가 리턴한 공간에 'b'문자를 저장
        ```

        ```cpp
        char &find(char s[],int index){
            return s[index];//참조 리턴
        }
        //그 위치에 다른 명칭을 연결시켜줌

        int main(){
            char name[]="Mike";
            cout<<name<<endl;

            find(name,0),='S';//name[0]='S'로 변경
            cout<<name<<endl;

            char& ref=find(name,2);
            ref='t';//name='Site'
            cout<<name<<endl;
            return 0;
        }
        ```
#### Lab: 객체를 함수로 전달하기
```cpp
    #include<iostream>


    using namespace std;

    class Complex{
        public:
        double real,imag;
        Complex(double r=0.0, double i=0.0):real{r},imag{i}{
            cout<<"Constructor called"<<endl;
            print();
        }
        ~Complex(){cout<<"Destructor called"<<endl;print();}
        void print(){
            cout<<real<<" + "<<imag<<"i"<<endl;
        }
    };
    Complex add(Complex c1,Complex c2){
        Complex temp;
        temp.real=c1.real+c2.real;;
        temp.imag=c1.imag+c2.imag;
        return temp; //리턴할 때 복사객체가 만들어짐
    }
    //위의 함수가 끝나고 나가기 전에 temp, c1, c2가 소멸됨
    int main()
    {
        Complex c1{1,2},c2{3,4};
        Complex t;
        t=add(c1,c2);//여기서 반환객체가 생성됨
        t.print();

        
        return 0;
    }
    /*
    Constructor called : c1
    1 + 2i
    Constructor called : c2
    3 + 4i
    Constructor called : t
    0 + 0i
    Constructor called : temp
    0 + 0i
    Destructor called : temp
    4 + 6i
    Destructor called : c1
    1 + 2i
    Destructor called : c2
    3 + 4i
    4 + 6i
    Destructor called : t
    4 + 6i
    Destructor called : c2
    3 + 4i
    Destructor called : c1
    1 + 2i
    //생성된 것의 역순으로 소멸 
    //(하지만 강의와 다르게 소멸자가 하나 덜 출력됨... add에서 복사객체(반환객체)가 소멸하는 과정이 없음)
    */
```