//�л��� ��Ÿ���� Ŭ���� student ����
//���͸� ����Ͽ� ���� ��ü �迭 �����
//����ڷκ��� 3�� �Է¹޾� �迭�� ���� �� sort()�Լ� ����� ������ ���� ������ ��� �л� ���� ���
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
    return p.get_degree()>q.get_degree();//���������̴� �ε�ȣ >����
}//����Լ� ���� �ٷ� ���� �� ���� ������ getter�� �ʿ�

int main()
{
    vector<Student> list;
    string name;
    double marks;

    for(int i=0;i<3;i++)
    {
        cout<<"�̸�: ";
        cin>>name;
        cout<<"����: ";
        cin>>marks;
        list.push_back(Student(name,marks));
    }
    list.push_back(Student("jeong",4.5));
    list[0].set_degree(4.1);//�Լ��� ���� ���� �����ϱ� ���� setter�ʿ�(������ ���� �Ұ����ؼ�)
    sort(list.begin(),list.end(),compare);//�տ��� ������ �������� �������� ����
    for(auto&e:list)
        e.print();

    return 0;
}


