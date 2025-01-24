#include<iostream>
using namespace std;

class Pizza{
    public:
        Pizza(int s):size(s){}
        int size;
};

void makeDouble(Pizza p)//call-by-value�Լ��� �޶����� ����
{
    p.size*=2;
}

//��ü�� �����ڰ� �Լ��� �Ű������� ���޵Ǵ� ���
void makeDouble2(Pizza &p)//p�� pizza�� ��Ī�� �Ǿ� ���� ������ ����Ű�� ��
{
    p.size*=2;
}//call-by-reference

//�Լ��� ��ü�� ��ȯ�ϴ� ��쿡�� ��ü�� ������ ����� �� ������ ���޵��� �ʴ´�.
Pizza createPizza()
{
    Pizza p(10);
    return p;
}

class Circle{
    int radius;

    public:
        Circle(){radius=1;}
        Circle(int r){radius=r;};
        void setRadius(int r){radius=r;}
        double getArea();
};

double Circle::getArea(){return 3.14*radius*radius;}

class axis_c{
    public:
        int x,y,radius;
        axis_c():x{0},y{0},radius{0}{}//�⺻ �����ڰ� ���ǵǾ� �־�� ��
        axis_c(int x,int y,int r):x{x},y{y},radius{r}{}
        void print(){
            cout<<"������: "<<radius<<" @("<<x<<","<<y<<")"<<endl;
        }
};

int main(){
    Pizza pizza(10);
    makeDouble2(pizza);//makeDouble(pizza)�Լ��� ���غ���
    cout<<pizza.size<<"��ġ ����"<<endl;

    Pizza pp=createPizza();
    cout<<pp.size<<"��ġ ����"<<endl;

    //��ü�� �迭�� ������ �� �ִ�.
    Circle cA[3];//��ü �迭�� �⺻�����ڸ� ȣ����!! ����Ʈ �����ڷ� �������
    cA[0].setRadius(10);
    cA[1].setRadius(20);
    cA[2].setRadius(30);

    for (int i=0;i<3;i++)
        cout<<"circle "<<i<<" �� ������ "<<cA[i].getArea()<<endl;
    
    //ó���� �� ��ü�� ���ϴ� ���� �־ �����ϰ� ���� �� 
    Circle circleA[3]={Circle(10),Circle(20),Circle()}; //�߰�ȣ�� ��� ������ �ָ� ��
    for (int i=0;i<3;i++)
        cout<<"circle "<<i<<" �� ������ "<<circleA[i].getArea()<<endl;
    
    //2���� �迭�� ������
    
    axis_c objAr[10];
    for (axis_c &c:objAr) //������ ���ؼ� for������ ��� ��ü�迭�� ������ �� �ִ�.
    {
        c.x=rand()%500;
        c.y=rand()%300;
        c.radius=rand()%100;
    }
    for(axis_c c:objAr) //�ڷ����� axis_c��ü�� ���� c�� ���� ���� ����
        c.print();

    return 0;
}