#include<iostream>
#include<string>
#include<ctime>

using namespace std;

class Circle{
    private:
        int radius;
    public:
        Circle(){
            radius = 1;
        }
        ~Circle(){
            cout <<radius<< "소멸자 호출" << endl;
        }
        double getArea(){
            return 3.14 * radius * radius;
        }
        int getRadius(){
            return radius;
        }
        void setRadius(int radius){
            this->radius = radius;
        }
};


int main()
{
    /* 문제
    circle클래스를 이용하여 동적 배열을 생성한다.
    동적 배열의 크기는 사용자가 입력
    원의 반지름은 1부터 100 사이 난수로 설정
    동적 배열에 저장된 원의 면적이 100을 초과하는 원의 개수를 출력
    동적 배열은 사용이 끝나면 삭제
    circle클래스
    멤버 변수 : radius
    멤버 함수 : 생성자, 소멸자, 면적, 멤버 변수, 설정자와 접근자
    */
    int n;
    int count=0;

    cout<<"생성할 원의 개수 :";
    cin>>n;
    Circle *pArray = new Circle[n];// 동적으로 할당할거라 포인터로 선언
    // 배열을 만들 때 각각 기본 생성자 호출
    

    srand(time(NULL));
    for(int i=0;i<n;i++){
        pArray[i].setRadius(rand()%100+1);
        if (pArray[i].getArea()>100){
            count++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<"반지름 "<<pArray[i].getRadius()<<"인 원"<<endl;
    }
    cout<<"면적이 100보다 큰 원의 개수 : "<<count<<endl;
    delete[] pArray;
    
    return 0;
}