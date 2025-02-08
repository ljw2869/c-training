#include<iostream>
using namespace std;

class Converter{ //�߻�Ŭ���� -�⺻Ŭ�����θ� ����
    protected:
        double ratio;
        virtual double converter(double src)=0;//���� �����Լ�
        virtual string getSourceString()=0;
        virtual string getDestString()=0;
    public:
        Converter(double ratio){
            this->ratio=ratio;
        }
        void run(){
            double src;
            cout<<getSourceString()<<"�� "<<getDestString()<<"�� �ٲߴϴ�. ";
            cout<<getSourceString()<<"�� �Է��ϼ���>> ";
            cin>>src;
            cout<<"��ȯ ���: "<<converter(src)<<getDestString()<<endl;
        }
};

class WontoDollar: public Converter{
    protected:
        virtual double converter(double src){ //������ �����Լ�ȭ �� �Լ����� �������̵� �ؾ���
            return src/ratio;
        }
        virtual string getSourceString(){
            return "��";
        }
        virtual string getDestString(){
            return "�޷�";
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
    WontoDollar wd(1010);//1�޷�=1010��
    wd.run();

    KmToMile toMile(1.609344);
    // toMile.run();
    Converter *ptr=&toMile; //converter�� ��ü�� ���� �� ������ �����ʹ� ���� �� ����
    ptr->run();
    ptr=&wd;//����Ű�� ��ü�� ���������� ���� ȣ��Ǵ� �Լ��� �޶�����(������)
    ptr->run();
    return 0;
}