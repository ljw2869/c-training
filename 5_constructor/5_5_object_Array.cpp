#include<iostream>
using namespace std;

class Pizza{
    public:
        Pizza(int s):size(s){}
        int size;
};

void makeDouble(Pizza p)//call-by-value함수라서 달라지지 않음
{
    p.size*=2;
}

//객체의 참조자가 함수의 매개변수로 전달되는 경우
void makeDouble2(Pizza &p)//p는 pizza에 별칭이 되어 같은 공간을 가리키게 됨
{
    p.size*=2;
}//call-by-reference

//함수가 객체를 반환하는 경우에도 객체의 내용이 복사될 뿐 원본이 전달되지 않는다.
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
        axis_c():x{0},y{0},radius{0}{}//기본 생성자가 정의되어 있어야 함
        axis_c(int x,int y,int r):x{x},y{y},radius{r}{}
        void print(){
            cout<<"반지름: "<<radius<<" @("<<x<<","<<y<<")"<<endl;
        }
};

int main(){
    Pizza pizza(10);
    makeDouble2(pizza);//makeDouble(pizza)함수와 비교해보기
    cout<<pizza.size<<"인치 피자"<<endl;

    Pizza pp=createPizza();
    cout<<pp.size<<"인치 피자"<<endl;

    //객체도 배열로 선언할 수 있다.
    Circle cA[3];//객체 배열은 기본생성자를 호출함!! 디폴트 생성자로 만들어짐
    cA[0].setRadius(10);
    cA[1].setRadius(20);
    cA[2].setRadius(30);

    for (int i=0;i<3;i++)
        cout<<"circle "<<i<<" 의 면적은 "<<cA[i].getArea()<<endl;
    
    //처음에 각 객체에 원하는 값을 넣어서 생성하고 싶을 때 
    Circle circleA[3]={Circle(10),Circle(20),Circle()}; //중괄호를 묶어서 설정해 주면 됨
    for (int i=0;i<3;i++)
        cout<<"circle "<<i<<" 의 면적은 "<<circleA[i].getArea()<<endl;
    
    //2차원 배열도 가능함
    
    axis_c objAr[10];
    for (axis_c &c:objAr) //참조를 통해서 for문으로 모든 객체배열을 수정할 수 있다.
    {
        c.x=rand()%500;
        c.y=rand()%300;
        c.radius=rand()%100;
    }
    for(axis_c c:objAr) //자료형이 axis_c객체인 변수 c를 통해 돌고 있음
        c.print();

    return 0;
}