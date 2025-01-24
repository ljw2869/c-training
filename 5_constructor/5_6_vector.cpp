#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<array>

using namespace std;

class Circle{
    public:
        int x,y;
        int radius;
        Circle():x{0},y{0},radius{0}{}
        Circle(int x,int y,int r):x{x},y{y},radius{r}{};
        void print(){
            cout<<"������: "<<radius<<" @("<<x<<","<<y<<")"<<endl;
        }
};

class Person{
    private:
        string name;
        int age;
    public:
        Person(string n,int a){
            name=n;
            age=a;
        }
        string get_name(){return name;}
        int get_age(){return age;}
        void print(){cout<<name<<" "<<age<<endl;}
};

bool compare(Person &p,Person&q){
    return p.get_age()<q.get_age();
}

class Movie{
    private:
        string title;
        double rating;

    public:
        Movie(string t="",double r=0.0){
            title=t; rating =r;
        }
        void print_movie(){cout<<title<<": "<<rating<<endl;}
};

int main()
{
    vector<int> fibonacci{0,1,1,2,3,5,8,13,21,34,55,89};

    for (auto& number:fibonacci) //auto�� �ؼ� �ᱹ�� �˾Ƽ� int�� ���߾���
        cout<<number<<" ";

    cout<<endl;

    //���� �ȿ� �����ϴ� �Լ����� ���� �־� ��!!
    // 1. push_back(����) : ���� ���� �ڿ� ������ ���̱�
    vector<int> v1;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);//�߰��� �� ������ ������ ũ�Ⱑ Ȯ���

    cout<<"v1= ";
    for (auto&e:v1){
        cout<<e<<" ";
    }
    cout<<endl;

    // 2. pop_back() : ���� ���� ���� ���ֱ� & empty(), back()
    cout<<"���� ��� = ";
    // ���Ͱ� ������ �� ������ pop_back()ȣ��
    while(v1.empty()!=true){
        cout<<v1.back()<<" ";
        v1.pop_back();
    }
    cout<<endl;

    v1={1,2,3,4,5};
    // 3. ���Ϳ��� ����� ��ġ�� �ݺ���(iterator)�� �̿��Ͽ� ǥ��
    for (auto p =v1.begin();p!=v1.end();++p)
        cout<<*p<<endl; //p�� �������̴�.

    // 4. .erase() : ������ �߰����� ����
    v1.erase(v1.begin()+1);//���⼭ 1�� �ƴ϶� ���ϴ� �ε����� ���� ���� ����
    
    // 5. ���Ϳ� ������
    v1={1,2,3,4,5};
    vector<int>v2(v1); //v1�� �����Ͽ� v2�� �����ϴ� ���� ������ ����
    
    if (v1==v2)
        cout<<"2���� ���Ͱ� ��ġ�մϴ�."<<endl;
    
    // ���Ϳ� ���ڿ� ����
    vector<string> vec;

    vec.push_back("milk");
    vec.push_back("bread");
    vec.push_back("butter");
    for (auto e:vec)
        cout<<" "<<e;
    cout<<endl;
    
    //Ŭ���� ��ü�� ���ͷ� ������ �� ����
    vector<Circle> objectArray;

    for (int i=0;i<10;i++)
    {
        Circle obj{rand()%300,rand()%500,rand()%100};
        objectArray.push_back(obj);
    }
    for (Circle c:objectArray)
        c.print();

    //���Ϳ� �˰���
    vector<Person> list;

    list.push_back(Person("Kim",30));
    list.push_back(Person("Park",22));
    list.push_back(Person("Lee",26));

    //algorithm����� �߰��ϸ� sort�Լ� ����
    sort(list.begin(),list.end(),compare);
    //���� ����� ������ �־ ����Ʈ�� ������ġ�� ������ ��ġ�� �ְ�, � �������� ������ �� �Լ� ����
    // compare�Լ��� �������� �Լ��̱� ������ �״�� ���� �ǵ��� ������ ����
    for(auto &e:list){
        e.print();
    }

    //�������� �л��� ������� �� �� ���ٰ� �ϸ� �������� �Է��� �޾ƾ� �Ѵٴ� ��Ʈ!
    //�л��� ��� ������ ����ϴ� ���α׷�(-1�� ������ ����)
    vector<int>scores;
    int i,sum=0;

    while(true){
        int score;
        cout<<"������ �Է��Ͻÿ�(����� -1): ";
        cin>>score;
        if(score==-1)break;
        scores.push_back(score);
    }
    for (auto&val:scores)
        sum+=val;
    double avg=(double)sum/scores.size();
    cout<<"���= "<<avg<<endl;

    //��ȭ ������ �����ϴ� Ŭ������ ���� ����
    vector<Movie> movies;

    movies.push_back(Movie("titinic",9.9));
    movies.push_back(Movie("gone with the wind",9.6));
    movies.push_back(Movie("terminator",9.7));

    for(auto&e:movies)
        e.print_movie();

    //vector�� ������ �Ҹ��� �ϴµ� ����� �ð��� �ҿ�
    //���� ������ �ذ��ϱ� ���� arrayŬ������ ����ϸ� ������ ���� �� ����
    
    array<int,3> list2{1,2,3}; //�������� �Ҵ��� ���� ������, �پ��� �Լ� ����
    for(int i=0;i<list.size();++i)
        ++list2[i];

    for(auto&elem:list2)
        cout<<elem<<" ";

    cout<<endl;
    // ������ ���� �Լ� ����
    // size(), fill()(�迭 ��� ���Ҹ� ������ ������ ä���)
    // empty(), at()(�迭 ��� ������ ��), front(), back()
    return 0;
}