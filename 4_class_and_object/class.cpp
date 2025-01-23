#include<iostream>
using namespace std;

class Circle{
    public:
        int radius;
        string color;

        double calcArea();
};
//Ŭ���� ����� Ŭ���� ���� �и�-Ŭ������ �ٸ� ���Ͽ��� Ȱ���ϱ� ���ؼ�
//�Լ��� ����Ÿ��- Ŭ���� �̸�::(�������� ������)-����Լ���� �Ű�����
double Circle::calcArea()
{
    return 3.14*radius*radius;
}

class Rectangle{
    public:
        int width,height;
        int calcArea()
        {
            return width*height;
        }
        //���� �ȿ� ���ǵǾ� �ִ� �Լ��� �ζ��� �Լ�!(inline function!)
};

class Car
{
    public:
    //��� ���� ����
        int speed;
        int gear;
        string color;

        //��� �Լ� ����
        void speedUp()
        {
            speed+=10;
        }
        void speedDown()
        {
            speed-=10;
        }
};//�� �����ݷ����� �ݾ��־�� �Ѵ�!

//�������̵�
class PrintData{//��� �Լ� �ߺ� ���� 
    public:
        void print(int i){cout<<i<<endl;}
        void print(double d){cout<<d<<endl;}
        void print(string s="No Data!"){cout<<s<<endl;}
};

//Ŭ������ �������̽��� ������ �и�

int main()
{
    Circle obj; //���� ���� ��ü�� ������ �� ������, ��ü���� �޸𸮸� ���� �Ҵ� �޴´�.
    obj.radius=100;
    obj.color="blue";

    cout<<"���� ���� ="<<obj.calcArea()<<endl;

    //myCar
    Car myCar;

    myCar.speed=100;
    myCar.gear=3;
    myCar.color="red";

    myCar.speedUp();
    myCar.speedDown();

    //PrintData
    PrintData pd;

    pd.print(1);
    pd.print(3.14);
    pd.print("C++14 is cool.");
    pd.print();//�ƹ��͵� �� �ָ� ����Ʈ ���ڰ� ������ no data�� ��� Ȯ��

    return 0;
} 