# 접근 지정자
+ private : 동일한 클래스의 멤버 함수에만 제한함
+ public : 모든 다른 클래스에 적용
+ protected : 클래스 자신과 상속받은 자식 클래스만 허용

+ private-public-private이런 식으로 꼭 순서대로 적지 않아도 괜찮음
+ 접근 지정자를 사용하지 않는다면 자동으로 디폴트 접근 지정이 private이므로, private으로 설정됨

    **멤버 변수는 private 지정이 바람직함**
+ 생성자도 private으로 설정할 수 있고, private으로 설정하는 경우는 클래스에서 오직 하나의 객체만 생성할 수 있도록 하기 위한 것

    **set함수로 값을 설정하고 get함수로 값을 받아올 수 있다.** 
    **set = 설정자, get = 접근자**