#include <iostream>
#include<string> //string��ü�� ���� ���� ������ ����� �����;� �Ѵ�
using namespace std;

int main()
{

	//string��ü�� �̿��� ���ڸ� �ٷ��
	//���� ������ ���� find()�� ����� �� ����
	//Ŭ����: ���赵, �ؾ Ʋ, ��ü: ��ǰ, �ؾ
	//string s; //string ��ü ����
	//string s = "Hello World!"; //string��ü ���� �� �ʱ�ȭ
	//string s{ "Hello World!" }; //string ��ü ���� �� �ʱ�ȭ


	string subject = "Money ";
	string other = "has no value if it is not used";
	string sentence = subject + other; //���ڿ����� +�� �̾��ִ� ���̴�.
	cout << sentence;

	//string s1 = "hello", s2 = "world";
	//if (s1 == s2)
	//	cout << "������ ���ڿ��Դϴ�." << endl;
	//else
	//	cout << "������ ���ڿ��� �ƴմϴ�." << endl;
	//if (s1 > s2)
	//	cout << "s1�� �տ� �ֽ��ϴ�." << endl;
	//else
	//	cout << "s2�� �տ� �ֽ��ϴ�." << endl;
	//// c++������ strcmp(s1,s2)==0�̷� ������ ��������� string��ü�� ����ϸ� �ε�ȣ�� �ƽ�Ű�ڵ忡 ����� ���� �� �ִ�.
	//
	string s1, addr;
	cin >> s1;
	cin.ignore(); //����Ű�� ���ֱ� ���� �ʿ� -���ۿ� �ִ� ���� ���ֱ� ����
	//cin�� ���۸� ���ؼ� �Է��� �� ���ڿ��� �ް� ���͸� ġ�� ���� ���ڿ��� ���Ͱ� ���Եǰ� �ȴ� �׷��� �ּ� ���� ���� �� ����
	cout << "�ּҸ� �Է��Ͻʽÿ�";
	getline(cin, addr);//���� ��ü�� �Է� �޾Ƽ� addr�� ������� �ǹ�
	cout << addr << "�� " << s1 << "�� �ȳ��ϼ���?" << endl;
	return 0;

}
