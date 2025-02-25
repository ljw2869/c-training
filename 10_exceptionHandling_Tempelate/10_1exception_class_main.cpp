#include<iostream>
#include<string>
using namespace std;
//���� Ŭ������ ����� �ڵ� ����
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

class DivideByZeroException:public MyException{//0���� ������ ���� Ŭ���� ����
    public:
        DivideByZeroException(int lineNo,string func,string msg):MyException(lineNo,func,msg){}
};

class InvaildInputException:public MyException{//�߸��� �Է� ���� Ŭ���� ����
    public:
        InvaildInputException(int lineNo,string func,string msg): MyException(lineNo,func,msg){}
};

int main(){
    int x,y;
    try{
        cout<<"�������� �մϴ�. �� ���� ���� ������ �Է��ϼ���."<<endl;
        cin>>x>>y;
        if(x<0||y<0)
            throw InvaildInputException(32,"main()","���� �Է� ���� �߻�");
        if(y==0)
            throw DivideByZeroException(32,"main()","0���� ������ ���� �߻�");
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