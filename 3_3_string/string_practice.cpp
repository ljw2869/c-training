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
	// string s1, addr;
	// cin >> s1;
	// cin.ignore(); //����Ű�� ���ֱ� ���� �ʿ� -���ۿ� �ִ� ���� ���ֱ� ����
	// //cin�� ���۸� ���ؼ� �Է��� �� ���ڿ��� �ް� ���͸� ġ�� ���� ���ڿ��� ���Ͱ� ���Եǰ� �ȴ� �׷��� �ּ� ���� ���� �� ����
	// cout << "�ּҸ� �Է��Ͻʽÿ�";
	// getline(cin, addr);//���� ��ü�� �Է� �޾Ƽ� addr�� ������� �ǹ�
	// cout << addr << "�� " << s1 << "�� �ȳ��ϼ���?" << endl;
	// //string Ŭ���� ����Լ� ���
	// //s[i] i��° ����, s.empty()s�� ��������� true��ȯ, 
	// // s.insert(pos,s2) pos��ġ�� s2�� ����, s.remove(pos,len) s�� pos��ġ�� len��ŭ�� ����
	// // s.find(s2) s���� ���ڿ� s2�� �߰ߵǴ� ù��° �ε����� ��ȯ
	// // s.find(pos,s2) s�� pos��ġ���� ���ڿ� s2�� �߰ߵǴ� ù��° �ε����� ��ȯ
	// string ss = "When in Rome, do as the Romans.";

	// int index = ss.find("Rome");
	// cout << index << endl;

	// //�ֹε�� ��ȣ�� �Է��ؼ� -�� ���ŵ� �ֹε�Ϲ�ȣ�� ����ϴ� ���α׷�
	// string num;
	// cout<<"�ֹε�Ϲ�ȣ�� �Է��ϼ���.";
	// cin>>num;
	// cout<<"-�� ���ŵ� �ֹε�Ϲ�ȣ"<<endl;
	// for (auto&c:num) //auto�� �����ν� �ڷ����� �˾Ƽ� ������ �� �� �ִ�. ������ ���� ������ ���� ��ȭ��ų �� ����
	// {
	// 	if (c=='-') continue; //�� ���ھ� ����ϸ鼭 -�� ������ ������� �ʰ� �Ѿ
	// 	cout<<c; 
	// }
	// cout<<endl;


	// //���ڿ��� �迭
	// string list[]={"ö��","����","�浿"};
	// for (auto &x:list)
	// 	cout<<(x+"�� �ȳ�!")<<endl;
	

	//lab �ع� �Ÿ� ���ϱ�
	// string s1,s2;
	// int count=0;

	// cout<<"DNA1";
	// cin>>s1;
	// cout<<"DNA2";
	// cin>>s2;

	// if (s1.length()!=s2.length())
	// 	cout<<"����: ���̰� �ٸ�"<<endl;
	// else{
	// 	for (int i=0;i<s1.length();i++)
	// 	{
	// 		if (s1[i]!=s2[i])
	// 			count++;
	// 	}
	// 	cout<<"�ع� �Ÿ��� "<<count<<endl;
	// }

	//���
	char ch;
	string sol;
	string list[]={"the","c++","programming","language"};
	int n=rand()%4;
	sol=list[n];
	string guess(sol.length(), '_'); //sol�� ���̸�ŭ _�� ä������ ���ڿ��� �����Ǿ� guess�ȿ� �־���
	cout<<"���ڸ� �Է��Ͻÿ�"<<endl;
	cin>>ch;
	while(true){
		for(int i=0;i<sol.length();i++)
		{
			if (ch==sol[i])
				guess[i]=ch;
		}
		if (sol==guess){
			cout<<sol<<endl;
			cout<<"�����Ͽ����ϴ�.";
			break;
		}
	}
	//���Ӱ� ��� ��: �Լ��� �����ε����� add(int a,int b)�� add(float a,float b)�� ���� �� add(1.2,3)�̷��� ������ float���� ȣ���� �ȴ�!!!

	return 0;

}
