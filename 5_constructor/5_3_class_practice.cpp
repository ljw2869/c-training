#include<iostream>
using namespace std;

class Time{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time(){
            hour=0;
            minute=0;
            second=0;
        }
        Time(int h,int m,int s):hour{h},minute{m},second{s}{}//이 공백의 중괄호쌍을 꼭 넣어줘야 함!
        void set_hour(int h){if (h>23) hour=0; else hour=h;}
        void set_minute(int m){minute=m;}
        int get_hour(){return hour;}//외부에서 private에 접근할 때 get함수 사용
        void inc_hour();
        void print();
};

void Time::inc_hour()
{
    ++hour;
    if (hour>23)
        hour=0;
}

void Time::print()
{
    cout<<hour<<": "<<minute<<": "<<second<<endl;
}

int main()
{
    Time t;//디폴트 생성자 호출
    Time t2(1,30,30);
    t.print();
    t.inc_hour();
    t.print();
    t.set_hour(13);
    t.set_minute(30);
    t.print();
    t2.print();
    cout<<"t time: "<<t.get_hour()<<endl;
    return 0;
}