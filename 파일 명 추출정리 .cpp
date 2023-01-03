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
	//귀찮아서 작성했다 안해서 제거 안한 변수 여럿
public:

	File(string aFileName) {
		AllName = aFileName;
		Len = AllName.length();
	}

	void FileBunryu() {
		Number = AllName.substr(0, 8); // 앞에 번호만 따로 저장 
		Name = AllName.erase(0, 8); //뒤에 한자 모으는거 
		NameLast = regex_replace(Name, regex("webp"), ""); //뒤에 한자 모은거에 webp 문장 제거 

		/*cout << '"' << Number << '"' << ':' << '"' << NameLast << '"' << endl;*/
	}
	string ReturnName() {
		return NameLast; // 클래스 선언을 위해 따로 리턴
	}
	string ReturnNumber() {
		return Number; //2
	}
	~File() {
		Name.clear();
		Number.clear();
		AllName.clear();
		//혹시 몰라 파괴자 
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
		Sibal.open("C:\\Users\\kim\\Desktop\\111.txt", ios::ate | ios::app); //  Sibal이 클래스 선언 변수임 욕아님 절대로 ate는 쓰기 위해 여는거 app는 연속해서 쓰는거
		Sibal << '"' << Number << '"' << ':' << '"' << Name << '"' << endl; // 실직적인 쓰는거 근데 더러워보임 
		Sibal.close(); // 닫기
	}
	~TextWrite() {
		Name.clear();
		Number.clear();//파괴자 혹시 몰라서 
	}
};

void main() {

	string path = "C:\\Users\\kim\\Desktop\\kai re sei\\*.*"; // 경로
	struct _finddata_t fd;
	intptr_t handle;
	string Name;

	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)
		cout << "No file in directory!" << endl; //없을때 표시
	do {
		if (fd.name != NULL) {
			Name = fd.name; // 변수에 저장

			File n(Name); //클래스 파일 선언

			n.FileBunryu();

			TextWrite wr(n.ReturnNumber(), n.ReturnName()); //텍스트 파일 클래스 생성문
			wr.Write();// 실질적인 텍스트 파일 읽기
		}
	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);




}

