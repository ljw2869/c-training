#include<iostream>
#include<string>
using namespace std;
//예외 클래스를 만드는 코드 예시
class MyException{
    int lineNo;
    string func,msg;
    public:
        MyException(int n,string f, string m){
            lineNo=n,func=f,msg=m;
        }
        void print(){
            cout<<func<<" : "<<lineNo<<" ,"<<msg<<endl;
        }
};

class DivideByZeroException:public MyException{//0으로 나누는 예외 클래스 선언
    public:
        DivideByZeroException(int lineNo,string func,string msg):MyException(lineNo,func,msg){}
};

class InvaildInputException:public MyException{//잘못된 입력 예외 클래스 선언
    public:
        InvaildInputException(int lineNo,string func,string msg): MyException(lineNo,func,msg){}
};

int main(){
    int x,y;
    try{
        cout<<"나눗셈을 합니다. 두 개의 양의 정수를 입력하세요."<<endl;
        cin>>x>>y;
        if(x<0||y<0)
            throw InvaildInputException(32,"main()","음수 입력 예외 발생");
        if(y==0)
            throw DivideByZeroException(32,"main()","0으로 나누는 예외 발생");
        cout<<(double)x/(double)y;
        }
    catch (DivideByZeroException &e){
        e.print();
    }
    catch (InvaildInputException &e){
        e.print();
    }
    return 0;
}