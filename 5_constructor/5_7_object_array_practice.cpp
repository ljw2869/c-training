//학생을 나타내는 클래스 student 정의
//벡터를 사용하여 동적 객체 배열 만들기
//사용자로부터 3명 입력받아 배열에 저장 후 sort()함수 사용해 학점이 높은 순으로 모든 학생 정보 출력
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Student{
    private:
        string name;
        double degree;
    public:
        Student(string s,double d):name(s),degree(d){};
        void print(){
            cout<<name<<" : "<<degree<<endl;
        }
        void set_name(string n){name=n;}
        string get_name(){ return name;}
        void set_degree(double d){degree=d;}
        double get_degree(){return degree;}
};

bool compare(Student &p,Student &q){
    return p.get_degree()>q.get_degree();//오름차순이니 부등호 >방향
}//멤버함수 값을 바로 얻을 수 없기 때문에 getter가 필요

int main()
{
    vector<Student> list;
    string name;
    double marks;

    for(int i=0;i<3;i++)
    {
        cout<<"이름: ";
        cin>>name;
        cout<<"학점: ";
        cin>>marks;
        list.push_back(Student(name,marks));
    }
    list.push_back(Student("jeong",4.5));
    list[0].set_degree(4.1);//함수를 통해 값을 변경하기 위해 setter필요(직접적 수정 불가능해서)
    sort(list.begin(),list.end(),compare);//앞에서 정의한 오름차순 기준으로 정렬
    for(auto&e:list)
        e.print();

    return 0;
}


