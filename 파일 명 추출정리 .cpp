#include <iostream>
#include <io.h>
#include <string>
#include<locale>
#include <regex>
#include<fstream>
using namespace std;

class File {
private:
	string Name;
	string Number;
	string AllName;
	string NameLast;
	int Len;
	//�����Ƽ� �ۼ��ߴ� ���ؼ� ���� ���� ���� ����
public:

	File(string aFileName) {
		AllName = aFileName;
		Len = AllName.length();
	}

	void FileBunryu() {
		Number = AllName.substr(0, 8); // �տ� ��ȣ�� ���� ���� 
		Name = AllName.erase(0, 8); //�ڿ� ���� �����°� 
		NameLast = regex_replace(Name, regex("webp"), ""); //�ڿ� ���� �����ſ� webp ���� ���� 

		/*cout << '"' << Number << '"' << ':' << '"' << NameLast << '"' << endl;*/
	}
	string ReturnName() {
		return NameLast; // Ŭ���� ������ ���� ���� ����
	}
	string ReturnNumber() {
		return Number; //2
	}
	~File() {
		Name.clear();
		Number.clear();
		AllName.clear();
		//Ȥ�� ���� �ı��� 
	}
};

class TextWrite {
private:
	string Name;
	string Number;
	ofstream Sibal;
public:

	TextWrite(string aNumber, string aName) {
		Name = aName;
		Number = aNumber;
	}
	void Write() {
		Sibal.open("C:\\Users\\kim\\Desktop\\111.txt", ios::ate | ios::app); //  Sibal�� Ŭ���� ���� ������ ��ƴ� ����� ate�� ���� ���� ���°� app�� �����ؼ� ���°�
		Sibal << '"' << Number << '"' << ':' << '"' << Name << '"' << endl; // �������� ���°� �ٵ� ���������� 
		Sibal.close(); // �ݱ�
	}
	~TextWrite() {
		Name.clear();
		Number.clear();//�ı��� Ȥ�� ���� 
	}
};

void main() {

	string path = "C:\\Users\\kim\\Desktop\\kai re sei\\*.*"; // ���
	struct _finddata_t fd;
	intptr_t handle;
	string Name;

	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)
		cout << "No file in directory!" << endl; //������ ǥ��
	do {
		if (fd.name != NULL) {
			Name = fd.name; // ������ ����

			File n(Name); //Ŭ���� ���� ����

			n.FileBunryu();

			TextWrite wr(n.ReturnNumber(), n.ReturnName()); //�ؽ�Ʈ ���� Ŭ���� ������
			wr.Write();// �������� �ؽ�Ʈ ���� �б�
		}
	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);




}

