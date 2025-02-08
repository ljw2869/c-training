#include<iostream>
using namespace std;

class Converter{ //추상클래스 -기본클래스로만 사용됨
    protected:
        double ratio;
        virtual double converter(double src)=0;//순수 가상함수
        virtual string getSourceString()=0;
        virtual string getDestString()=0;
    public:
        Converter(double ratio){
            this->ratio=ratio;
        }
        void run(){
            double src;
            cout<<getSourceString()<<"을 "<<getDestString()<<"로 바꿉니다. ";
            cout<<getSourceString()<<"을 입력하세요>> ";
            cin>>src;
            cout<<"변환 결과: "<<converter(src)<<getDestString()<<endl;
        }
};

class WontoDollar: public Converter{
    protected:
        virtual double converter(double src){ //무조건 가상함수화 된 함수들은 오버라이딩 해야함
            return src/ratio;
        }
        virtual string getSourceString(){
            return "원";
        }
        virtual string getDestString(){
            return "달러";
        }
        public:
            WontoDollar(double ratio):Converter(ratio){}
};

class KmToMile:public Converter{
    protected:
        virtual double converter(double src){ return src/ratio;}
        virtual string getSourceString(){ return "Km";}
        virtual string getDestString(){ return "mile";}

    public:
        KmToMile(double ratio):Converter(ratio){}
};

int main(){
    WontoDollar wd(1010);//1달러=1010원
    wd.run();

    KmToMile toMile(1.609344);
    // toMile.run();
    Converter *ptr=&toMile; //converter는 객체는 만들 수 없지만 포인터는 만들 수 있음
    ptr->run();
    ptr=&wd;//가리키는 객체가 무엇인지에 따라서 호출되는 함수가 달라진다(다형성)
    ptr->run();
    return 0;
}