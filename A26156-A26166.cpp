#include <conio.h>
#include<iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <dos.h>

#define M 10
using namespace std;
struct TuDien
{
	char Anh[M];
	char Viet[M];
	char Loai[M];
};
struct Node
{
	TuDien Data;
	Node *L;
	Node *R;
};
typedef Node*Pnode;
void Init(Pnode &T)
{
	T = NULL;
}
int Empty(Pnode T)
{
	if (T == NULL)
		return 1;
	return 0;
}
Pnode GetNode(TuDien x)
{
	Pnode p = new Node;
	p->Data = x;
	p->L = p->R = NULL;
	return p;
}
void InputA1(Pnode &T, TuDien x)
{
	if (Empty(T) == 1)
	{
		T = GetNode(x);
	}

	else
	{
		if (strcmp(x.Anh, T->Data.Anh)<0)
			InputA1(T->L, x);
		else
			InputA1(T->R, x);
	}

}

void InputA(Pnode &T, TuDien x)
{
	if (Empty(T) == 1)
	{
		T = GetNode(x);
	}
	else
	{
	H:
		if (strcmp(x.Anh, T->Data.Anh) == 0)
		{
			cout << "\nTu Nay Da Co, Moi Nhap Lai ";
			cout << "\nNhap Tu Can Them Neu Khong Hay An Enter) ";
			fflush(stdin);
			gets_s(x.Anh);
			if (strcmp(x.Anh, "") == 0)
				return;
			cout << "Nhap Nghia: ";
			fflush(stdin);
			gets_s(x.Viet);
			cout << "Nhap Loai Tu: ";
			fflush(stdin);
			gets_s(x.Loai);
			goto H;
		}

		else
		{
			if (strcmp(x.Anh, T->Data.Anh)<0)
				InputA(T->L, x);
			else
				InputA(T->R, x);
		}
	}
}
void InA(Pnode &T, TuDien x)
{
	do
	{
		cout << "\nNhap Tu Can Them, Neu Khong Hay An Enter De Bo Qua ";
		fflush(stdin);
		gets_s(x.Anh);
		if (strcmp(x.Anh, "") == 0)
			return;
		cout << "Nhap Nghia: ";
		fflush(stdin);
		gets_s(x.Viet);
		cout << "Nhap Loai Tu: ";
		fflush(stdin);
		gets_s(x.Loai);
		InputA(T, x);
	} while (strcmp(x.Anh, "") != 0);
}
void TraTuA(Pnode T, TuDien x)
{
	//char p;	
	if (T != NULL)
	{
		if (strcmp(T->Data.Anh, x.Anh) == 0)
		{
			cout << "Nghia Cua Tu: ";
			cout << T->Data.Viet;
			cout << "\nLoai Cua Tu:";
			cout << T->Data.Loai;
			return;
		}
		if (strcmp(T->Data.Anh, x.Anh)>0)
			TraTuA(T->L, x);
		else
			TraTuA(T->R, x);
	}
	else
		cout << "Khong Tim Duoc Tu Can Tra";
}
Pnode Search(Pnode T, TuDien x)
{
	Pnode p = T;
	while (p != NULL)
	{
		if (strcmp(x.Anh, p->Data.Anh) == 0)
			return p;
		else
		{
			if (strcmp(x.Anh, p->Data.Anh)<0)
				p = p->L;
			else
				p = p->R;
		}
	}
	return NULL;
}
void SearchF(Pnode &p, Pnode &q)
{
	if (q->L)
		SearchF(p, q->L);
	else
	{
		p->Data = q->Data;
		p = q;
		q = q->L;
	}
}
int Del(Pnode &T, TuDien x)
{
	if (T == NULL)
	{
		cout << "\nTu Dien Trong";
		return 0;
	}
	if (Search(T, x) != NULL)
	{
		if (strcmp(T->Data.Anh, x.Anh)>0)
			Del(T->L, x);
		if (strcmp(T->Data.Anh, x.Anh)<0)
			Del(T->R, x);
		Pnode p = T;
		if (T->L == NULL)
			T = T->R;
		else
			if (T->R == NULL)
				T = T->L;
			else
			{
				SearchF(p, T->R);
				delete p;
			}
		return 1;
	}
	else
	{
		cout << "\nKhong Tim Thay Du Lieu";
		return 0;
	}
}
void SuaA(Pnode&T, TuDien x)
{
	cout << "\nNhap Tu Can Sua";
	fflush(stdin);
	gets_s(x.Anh);
	if ((Del(T, x)) == 0)
		return;
	else
	{
		cout << "\nNhap Tu Moi ";
		fflush(stdin);
		gets_s(x.Anh);
		if (strcmp(x.Anh, "") == 0)
			return;
		cout << "Nhap Nghia Moi: ";
		fflush(stdin);
		gets_s(x.Viet);
		cout << "Nhap Loai Tu Moi: ";
		fflush(stdin);
		gets_s(x.Loai);
		InputA(T, x);
		cout << "\nTu Da Duoc Chinh Sua";
	}
}
/*========================================================*/


void InputV1(Pnode &T, TuDien x)
{
	if (Empty(T) == 1)
	{
		T = GetNode(x);
	}

	else
	{
		if (strcmp(x.Viet, T->Data.Viet)<0)
			InputV1(T->L, x);
		else
			InputV1(T->R, x);
	}

}
void InputV(Pnode &T, TuDien x)
{
	if (Empty(T) == 1)
	{
		T = GetNode(x);
	}
	else
	{

	H:
		if (strcmp(x.Viet, T->Data.Viet) == 0)
		{
			cout << "\nTu Nay Da Co, Moi Ban Nhap Lai: ";
			cout << "\nTu Can Them: ";
			fflush(stdin);
			gets_s(x.Viet);
			cout << "Nghia Cua Tu: ";
			fflush(stdin);
			gets_s(x.Anh);
			cout << "Loai Cua Tu: ";
			fflush(stdin);
			gets_s(x.Loai);
			goto H;
		}
		else
		{
			if (strcmp(x.Viet, T->Data.Viet)<0)
				InputV(T->L, x);
			else
				InputV(T->R, x);
		}
	}
}
void InV(Pnode &T, TuDien x)
{
	do
	{
		cout << "\nNhap Tu Can Them, Neu Khong Nhap Nua Hay An Phim Enter De Bo Qua ";
		fflush(stdin);
		gets_s(x.Viet);
		if (strcmp(x.Viet, "") == 0)
			return;
		cout << "Nhap Nghia: ";
		fflush(stdin);
		gets_s(x.Anh);
		cout << "Nhap Loai Tu: ";
		fflush(stdin);
		gets_s(x.Loai);
		InputV(T, x);
	} while (strcmp(x.Viet, "") != 0);
}
void TraTuV(Pnode T, TuDien x)
{
	if (T != NULL)
	{
		if (strcmp(T->Data.Viet, x.Viet) == 0)
		{
			cout << "\nNghia Cua Tu: ";	cout<< T->Data.Anh;
			cout << "\nLoai Cua Tu: ";	 cout<<T->Data.Loai;
			return;
		}
		if (strcmp(T->Data.Viet, x.Viet)>0)
			TraTuV(T->L, x);
		else
			TraTuV(T->R, x);
	}
	else
		cout << "Khong Tim Duoc Tu Can Tra";
}
Pnode SearchV(Pnode T, TuDien x)
{
	Pnode p = T;
	while (p != NULL)
	{
		if (strcmp(x.Viet, p->Data.Viet) == 0)
			return p;
		else
		{
			if (strcmp(x.Viet, p->Data.Viet)<0)
				p = p->L;
			else
				p = p->R;
		}
	}
	return NULL;
}
int DelV(Pnode &T, TuDien x)
{
	if (T == NULL)
	{
		cout << "\nTu Dien Trong";
		return 0;
	}
	if (SearchV(T, x) != NULL)
	{
		if (strcmp(T->Data.Viet, x.Viet)>0)
			Del(T->L, x);
		if (strcmp(T->Data.Viet, x.Viet)<0)
			Del(T->R, x);
		Pnode p = T;
		if (T->L == NULL)
			T = T->R;
		else
			if (T->R == NULL)
				T = T->L;
			else
			{
				SearchF(p, T->R);
				delete p;
			}
		return 1;
	}
	else
	{
		cout << "\nKhong Tim Thay Du Lieu";
		return 0;
	}
}
void SuaV(Pnode&T, TuDien x)
{
	cout << "\nNhap Tu Can Sua";
	fflush(stdin);
	gets_s(x.Viet);
	if ((DelV(T, x)) == 0)
		return;
	else
	{
		cout << "\nNhap Tu Moi ";
		fflush(stdin);
		gets_s(x.Anh);
		if (strcmp(x.Anh, "") == 0)
			return;
		cout << "Nhap Nghia Moi: ";
		fflush(stdin);
		gets_s(x.Viet);
		cout << "Nhap Loai Tu Moi: ";
		fflush(stdin);
		gets_s(x.Loai);
		InputA(T, x);
		cout << "\nTu Da Duoc Chinh Sua";
	}
}



/*=========================================================*/
int main() {
		Pnode T;
		Init(T);
		TuDien x;
		bool isExit = false;
		int option;
		do
		{
			system("cls");
			cout << "(1) Tu Dien Anh - Viet" << endl;
			cout << "(2) Tu Dien Viet - Anh" << endl;
			cout << "(0) Thoat" << endl;
			cout << "Moi Ban Nhap Lua Chon" << endl;
			int menu; cin >> menu; cin.ignore();
			switch (menu)
			{
			case 0:
				cout << "Thoat!!!\n";
				exit(1);
				break;
			case 1:
				do
				{
					system("cls");
					cout << "\n\t\t\t====Tu-Dien-Anh-Viet====";
					cout << "\nPhim 0: Thoat";
					cout << "\nPhim 1: Them Tu";
					cout << "\nPhim 2: Tra Mot Tu Tieng Anh";
					cout << "\nPhim 3: Xoa Mot Tu Tieng Anh";
					cout << "\nPhim 4: Sua Mot Tu Tieng Anh";
					cout << "\nMoi Ban Nhap Su Lua Chon" << endl;
					int option; cin >> option; cin.ignore();
					system("cls");
					switch (option)
					{
					case 0:
						cout << "Thoat!!!\n";
						exit(1);
						break;
					case 1:
						InA(T, x);
						cin.ignore();
						break;
					case 2:
						cout << "\nNhap Tu Can Tra: ";
						fflush(stdin);
						gets_s(x.Anh);
						TraTuA(T, x);
						cin.ignore();
						break;
					case 3:
						cout << "\nNhap Tu Can Xoa: ";
						fflush(stdin);
						gets_s(x.Anh);
						Del(T, x);
						cout << "\nThao Tac Hoan Thanh!";
						cin.ignore();
						break;
					case 4:
						SuaA(T, x);
						cin.ignore();
						break;
					default:
						cout << "\nBan Chon Sai Moi Chon Lai";
						cin.ignore();
						break;
					}
				} while (!isExit);
				break;
			case 2:
			{
				do
				{
					system("cls");
					cout << "\n\t\t\t====Tu-Dien-Viet-Anh====";
					cout << "\nPhim 0: Thoat";
					cout << "\nPhim 1: Them Tu Tieng Viet";
					cout << "\nPhim 2: Tra Mot Tu Tieng Viet";
					cout << "\nPhim 3: Xoa Mot Tu Tieng Viet";
					cout << "\nPhim 4: Sua Mot Tu Tieng Viet";
					cout << "\nMoi Ban Nhap Su Lua Chon" << endl;
					int choice; cin >> choice; cin.ignore();
					system("cls");
					switch (choice)
					{
					case 0:
						cout << "Thoat!!!\n";
						exit(1);
						break;
					case 1:
						InV(T, x);
						cin.ignore();
						break;
					case 2:
						cout << "\nNhap Tu Can Tra: ";
						fflush(stdin);
						gets_s(x.Viet);
						TraTuV(T, x);
						cin.ignore();
						break;
					case 3:
						cout << "\nNhap Tu Can Xoa: ";
						fflush(stdin);
						gets_s(x.Viet);
						DelV(T, x);
						cout << "\nThao Tac Hoan Thanh!";
						cin.ignore();
						break;
					case 4:
						SuaV(T, x);
						cin.ignore();
						break;
					default:
						cout << "\nBan Chon Sai Moi Chon Lai";
						cin.ignore();
						break;
					}
				} while (!isExit);

			}
			default:
			{
				cout << "\nBan Chon Sai Moi Chon Lai";
				cin.ignore();
				break;
			}
		}
	}
	while (!isExit);
	system("pause");
	return 0;
}
