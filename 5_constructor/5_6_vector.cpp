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
            cout<<"반지름: "<<radius<<" @("<<x<<","<<y<<")"<<endl;
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

    for (auto& number:fibonacci) //auto로 해서 결국은 알아서 int로 맞추어짐
        cout<<number<<" ";

    cout<<endl;

    //벡터 안에 제공하는 함수들이 많이 있어 편리!!
    // 1. push_back(원소) : 벡터 제일 뒤에 공간을 늘이기
    vector<int> v1;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);//추가가 될 때마다 벡터의 크기가 확대됨

    cout<<"v1= ";
    for (auto&e:v1){
        cout<<e<<" ";
    }
    cout<<endl;

    // 2. pop_back() : 제일 뒤의 값을 없애기 & empty(), back()
    cout<<"삭제 요소 = ";
    // 벡터가 공백이 될 때까지 pop_back()호출
    while(v1.empty()!=true){
        cout<<v1.back()<<" ";
        v1.pop_back();
    }
    cout<<endl;

    v1={1,2,3,4,5};
    // 3. 벡터에서 요소의 위치는 반복자(iterator)를 이용하여 표시
    for (auto p =v1.begin();p!=v1.end();++p)
        cout<<*p<<endl; //p는 포인터이다.

    // 4. .erase() : 벡터의 중간에서 삭제
    v1.erase(v1.begin()+1);//여기서 1이 아니라 원하는 인덱스의 값을 삭제 가능
    
    // 5. 벡터와 연산자
    v1={1,2,3,4,5};
    vector<int>v2(v1); //v1을 복사하여 v2를 생성하는 것은 다음과 같다
    
    if (v1==v2)
        cout<<"2개의 벡터가 일치합니다."<<endl;
    
    // 벡터에 문자열 저장
    vector<string> vec;

    vec.push_back("milk");
    vec.push_back("bread");
    vec.push_back("butter");
    for (auto e:vec)
        cout<<" "<<e;
    cout<<endl;
    
    //클래스 객체도 벡터로 저장할 수 있음
    vector<Circle> objectArray;

    for (int i=0;i<10;i++)
    {
        Circle obj{rand()%300,rand()%500,rand()%100};
        objectArray.push_back(obj);
    }
    for (Circle c:objectArray)
        c.print();

    //벡터와 알고리즘
    vector<Person> list;

    list.push_back(Person("Kim",30));
    list.push_back(Person("Park",22));
    list.push_back(Person("Lee",26));

    //algorithm헤더를 추가하면 sort함수 제공
    sort(list.begin(),list.end(),compare);
    //정렬 대상의 범위를 주어서 리스트의 시작위치와 마지막 위치를 주고, 어떤 기준으로 정렬할 지 함수 전달
    // compare함수가 오름차순 함수이기 때문에 그대로 참이 되도록 정렬을 해줌
    for(auto &e:list){
        e.print();
    }

    //문제에서 학생이 몇명인지 알 수 없다고 하면 동적으로 입력을 받아야 한다는 힌트!
    //학생들 평균 성적을 계산하는 프로그램(-1을 받으면 종료)
    vector<int>scores;
    int i,sum=0;

    while(true){
        int score;
        cout<<"성적을 입력하시오(종료는 -1): ";
        cin>>score;
        if(score==-1)break;
        scores.push_back(score);
    }
    for (auto&val:scores)
        sum+=val;
    double avg=(double)sum/scores.size();
    cout<<"평균= "<<avg<<endl;

    //영화 정보를 저장하는 클래스를 만들어서 저장
    vector<Movie> movies;

    movies.push_back(Movie("titinic",9.9));
    movies.push_back(Movie("gone with the wind",9.6));
    movies.push_back(Movie("terminator",9.7));

    for(auto&e:movies)
        e.print_movie();

    //vector는 생성과 소멸을 하는데 상당한 시간이 소요
    //위의 문제를 해결하기 위해 array클래스를 사용하면 장점만 얻을 수 있음
    
    array<int,3> list2{1,2,3}; //동적으로 할당할 수는 없으나, 다양한 함수 제공
    for(int i=0;i<list.size();++i)
        ++list2[i];

    for(auto&elem:list2)
        cout<<elem<<" ";

    cout<<endl;
    // 다음과 같은 함수 제공
    // size(), fill()(배열 모든 원소를 동일한 값으로 채우기)
    // empty(), at()(배열 요소 접근할 때), front(), back()
    return 0;
}