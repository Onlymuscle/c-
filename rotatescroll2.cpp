#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstring>

using namespace std;

class RotateScroll {
private:
	int x, x1;
	char* name;
	bool tf;
	int h;
	int src, src2, src3;
	int len, len2 = 0;
	int srce, srce2, srce3;
	int count, count2;
	char* name2;
public:
	RotateScroll(const char* aname, int start, int end, int height, bool RL) {
		x = start;
		name = new char[strlen(aname) + 1];
		strcpy_s(name, strlen(aname) + 1, aname);
		name2 = new char[strlen(aname) + 1];
		if (RL == false) {
			name2 = _strrev(name);
		}
		x1 = end;
		tf = RL;
		h = height;
		src = start;
		src2 = start;
		src3 = start;
		len = strlen(name);
		srce = end;//end 지점 원본
		srce2 = end; //건드리면 안됨
		srce3 = end;//건드려도됨
		len2 = 0;
		count2 = x1 - x - strlen(name);
		count = 0;
	}
	void gotoxy(int a, int b)
	{
		COORD pos = { a,b };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	void Rotate() {
		if (tf == true) {

			if (src2 >= x1) {
				src2 = src;
				gotoxy(x1 - 1, h);
				cout << ' ' << endl;
			}
			x = src2;
			gotoxy(x - 1, h);
			cout << ' ' << endl;

			for (int i = 0; i < *name; i++) {
				gotoxy(x, h);
				x++;
				if (name[i] == NULL) {
					break;
				}
				if (src2 + i >= x1) {
					gotoxy(src3, h);
					src3++;

				}
				else {
					src3 = src;
				}
				cout << name[i] << endl;
			}
			src2++;

		}
		else if (tf==false) {

			if (srce <= x) {
				srce = srce2; //첫 지점으로 돌아왔을때 초기화
				srce3 = srce2;

			}

			gotoxy(x1, h);
			cout << ' ' << endl; // 뒤에 찌꺼기 지우는 줄

			for (int i = 0; i < name2[i]; i++) {

				gotoxy(x1, h);
				 //전체적인 모형 

				if (name2[i] == NULL) {
					break;
				} //널값 차단

				if (x1 <= x) {
					gotoxy(srce3, h);
					srce3--;
				}
				else {
					srce3 = srce2;
				}

				cout << name2[i] << endl; //출력

				gotoxy(x1 + strlen(name), h);
				cout << ' ' << endl; // 뒤에 찌꺼기 지우는 줄

				x1--;
			}

			srce--;
			x1 = srce;
		}
	}
	~RotateScroll() {
		delete[] name2;
		for(int i=0;i<name[i];i++){
			delete[i] name;
		}
	}

};
void main()
{
	class RotateScroll R1("Scroll Object", 30, 50, 12, true);
	class RotateScroll R2("Object Oriented Programming", 10, 60, 8, false);
	int x = 0;

	for (;;) {

		R1.Rotate();
		R2.Rotate();

		Sleep(100);
		x++;

		if (x == 5) {
			break;
		}
	}

}
