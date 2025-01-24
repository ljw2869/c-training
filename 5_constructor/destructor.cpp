#include <iostream>
#include <cstring>

using namespace std;

class MyString{
    private:
        char *s;
        int size;
    public:
        MyString(const char *c){
            size=strlen(c)+1;
            s = new char[size];//���� �Ҵ�
            strcpy(s,c);
        }
        ~MyString(){ //�տ� ƿ�带 ���̰� Ŭ���� ��� ������ �Լ��� �Ҹ���
            delete[] s;//�������� �Ҵ��� �޸𸮸� ����
        }
        //�Ҹ��ڵ� �ڵ����� �˾Ƽ� ȣ���� ��
};

class Circle{
    public:
        int radius;
        Circle();
        Circle(int r);
        ~Circle();
        double getArea();
};

Circle::Circle(){
    radius=1;
    cout<<"������ :"<<radius<<" �� ����"<<endl;
}

Circle::Circle(int r){
    radius=r;
    cout<<"������ :"<<radius<<" �� ����"<<endl;
}

Circle::~Circle(){
    cout<<"������ "<<radius<<" �� �Ҹ�"<<endl;
}

double Circle::getArea(){
    return 3.14*radius*radius;
}

Circle globalDonut(1000);//���� ��ü ����
Circle globalPizza(2000);

void f(){
    Circle fDonut(100);//���� ��ü ����
    Circle fPizza(200);
}

int main()
{
    MyString str("abcdefghijk");
    
    Circle mainDonut;
    Circle mainPizza(30);//���� ��ü ����
    f();
    // �Ҹ� ����� ���� �������� �Ҹ��� �� ���� Ȯ���� �� ����
    //adderŬ������ calculatorŬ������ ���� ���� �� 5���� ���Ϸ� ������ �����ϴ� ���⸦ ���� �� �ִ�!!
    //(12:20)
    return 0;
}