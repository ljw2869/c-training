#include<iostream>
using namespace std;

// class TV{
//     int size;
//     public:     
//         TV(){
//             size=20;
//         }
//         TV(int size){
//             this->size=size;
//         }
//         int getSize(){
//             return size;
//         }
// };

// class WideTV : public TV{
//     bool videoIn;
//     public:
//         WideTV(int size, bool videoIn):TV(size){
//             this->videoIn=videoIn;
//         }
//         bool getVideoIn(){
//             return videoIn;
//         }
// };

// class SmartTV : public WideTV{
//     string ipAddr;
//     public:
//         SmartTV(string ipAddr, int size):WideTV(size,true){
//             this->ipAddr=ipAddr;
//         }
//         string getIp(){
//             return ipAddr;
//         }
// };

// int main(){
//     SmartTV tv("192.0.0.1",32);
//     cout<<"size: "<<tv.getSize()<<endl;
//     cout.setf(ios::boolalpha); //1->true, 0->false로 바꿔주기!
//     cout<<"videoIn: "<<tv.getVideoIn()<<endl;
//     cout<<"ipAddr: "<<tv.getIp()<<endl;
//     return 0;
// }


class Shape{
    int x,y;
    public:
        Shape(int x,int y):x{x},y{y}{}
        void setX(int x){ this->x=x;}
        void setY(int y){ this->y=y;}
        int getX(){ return x;}
        int getY(){ return y;}
        void draw(){ cout<<"Shape Draw"<<endl;}
        int getArea(){return 0;}
};
class Circle:public Shape{
    int r;
    public: 
        Circle(int r,int x,int y): Shape(x,y),r{r}{} //생성자가 protected가 되면 안됨
        void draw(){
            cout<<"Circle Draw..."<<endl;
        }
        double getArea(){ //부모클래스의 함수를 재정의(overriding)(중복 정의가 아님)
            return 3.14*r*r;
        }
};

class Rect:public Shape{
    int w,h;
    public:
        Rect(int w,int h,int x,int y):Shape(x,y),w{w},h{h}{}
        void draw(){
            cout<<"Rect Draw..."<<endl;
        }
        int getArea(){ //부모클래스의 함수를 재정의(overriding)(중복 정의가 아님)
            return w*h;
        }
};
int main(){
    Circle c(10,5,5);
    Rect r(10,5,5,5);
    c.draw();
    r.draw();
    cout<<"Circle Area: "<<c.getArea()<<endl;
    cout<<"Rect Area: "<<r.getArea()<<endl;
    //만약에 아무리 부모 클래스의 public 멤버여도, private으로 상속을 받았다면 main함수에서는 접근이 불가능하다.
    // 그래서 main입장에서는 상속 받은 클래스의 public 함수를 불러와서 사용하는 것만 가능하다
    return 0;
}