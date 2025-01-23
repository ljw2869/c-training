#include<iostream>
using namespace std;

class Time
{
    public:
        int hour;//0~23
        int minute;//0~59

        // Time()
        // {
        //     hour=0;
        //     minute=0;
        // }
        //���� �� �ڵ带 ����Ʈ �Ű������� �̿��ؼ� ����ȭ
        // Time(int h = 0, int m = 0) //�̰� ��������
        // {
        //     hour=h;
        //     minute=m;
        // }

        void print()
        {
            cout<<hour<<":"<<minute<<endl;
        }
        
        //{}�ȿ��� �����Ͽ� �ʱ�ȭ�ϴ� ���� ":"�� �ʱ�ȭ ����Ʈ�� ����Ͽ� 
        Time(int h = 0 ,int m = 0):hour{h},minute{m} //minute(m)���� �ۼ��ص� ������ ���� ���
        {

        }
};

// �Ʒ��� ���� �ۿ��� �������־ �Ǵµ�, ���⼭ �����ڴ� ����Ÿ���� ���� ������ �ٷ� Time::�̷��� �����ָ� �ȴ�.
// Time::Time(int h,int min){

// }


class Circle{
    public:
        int radius;
        Circle();
        Circle(int r);
        double getArea();
};

// Circle::Circle(){
//     radius=1;
//     cout<<"������ "<<radius<<" �� ����"<<endl;
// }

// Circle::Circle(int r){
//     radius=r;
//     cout<<"������ "<<radius<<" �� ����"<<endl;
// }
//���� �� �����ڴ� �Ű����� ��������� ����� ���� ����. �׷� �� ���� �����ڸ� ����ϸ� �� 

Circle::Circle():Circle(1){}//���� ������ -�Ʒ��� �����ڸ� ȣ���ϰ� �ȴ�
Circle::Circle(int r){//Ÿ�� ������
    radius=r;
    cout<<"������ "<<radius<<" �� ����"<<endl;
}

double Circle::getArea()
{
    return 3.14*radius*radius;
}

class Point{
    int x,y; //private�̶�� �� ��� public�ȿ� �� ���� private���� �����Ѵ�
    public:
    Point();
    Point(int a,int b);
};

// Point::Point(){x=0;y=0;}
// Point::Point(int a,int b){x=a;y=b;}
//���� �ڵ带 �Ʒ��� ���� ���ӻ����ڿ� Ÿ�ٻ����ڸ� �̿��ؼ� �ۼ��� �� ����

Point::Point():Point(x=0,y=0){}// ���� ������
Point::Point(int a,int b):x(a),y(b){} // Ÿ�� ������
// ������ �ʱ�ȭ ����Ʈ:�� ����Ͽ� �� ����������.

class Rectangle{
    public:
        int width,height;

        Rectangle();
        Rectangle(int w,int h);
        Rectangle(int length);
        bool isSquare();
};

Rectangle::Rectangle()
{
    width=height=1;
}
Rectangle::Rectangle(int w,int h):width{w},height{h}{}
Rectangle::Rectangle(int length)
{
    width = height = length;
}
bool Rectangle::isSquare()
{
    if (width==height) return true;
    else return false;
}

int main()
{
    //�����ڸ� ȣ���ϴ� ���
    Time a; 
    Time b(10,25);
    Time c{10,25};
    Time d={10,25};

    a.print();
    b.print();

    //class Circle����
    Circle donut;
    double area=donut.getArea();
    cout<<"donut ������ "<<area<<"�Դϴ�"<<endl;

    Circle pizza(30);
    double ar=pizza.getArea();
    cout<<"pizza ������ "<<ar<<"�Դϴ�"<<endl;

    Rectangle r1;
    Rectangle r2(3,5);
    Rectangle r3(3);

    if (r1.isSquare()) cout<<"r1�� ���簢���̴�"<<endl;
    if (r2.isSquare()) cout<<"r2�� ���簢���̴�"<<endl;
    if (r3.isSquare()) cout<<"r3�� ���簢���̴�"<<endl;
    return 0; 
}