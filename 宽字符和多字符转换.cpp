#include<windows.h>
#include<string>
#include<stdio.h>


int main() {
	char a[] = "���Ƕ��ַ�ת���ַ�";
	setlocale(LC_ALL, "");
	//�Ȼ�ȡ��a�Ĵ�С
	DWORD Mnum; //���������С
	Mnum = MultiByteToWideChar(CP_ACP, 0, a, -1, NULL, 0); //����a�Ĵ�С , ����������Ϊ��ת�����ַ������ĸ�ȡ���\0֮ǰ�ģ����������Ϊ����ת��֮������ݣ��������������ȼ����С���Բ���ΪNULL,����������Ϊ��ת���Ĵ�С
	wchar_t * b = new wchar_t[Mnum];
	if (!b) {
		delete[] b;
		return 1;
	}

	MultiByteToWideChar(CP_ACP, 0, a, -1, b, Mnum);
	wprintf(L"L->M %s\n", b);


	DWORD Mnum2;
	wchar_t c[] = L"���ǿ��ַ�ת���ַ�";
	Mnum2 = WideCharToMultiByte(CP_OEMCP, 0, c, -1, NULL, 0,NULL,NULL);

	char * d = new char[Mnum2];
	if (!d) {
		delete[] d;
		return 1;
	}
	WideCharToMultiByte(CP_OEMCP, 0, c, -1, d, Mnum2,NULL,NULL);
	printf("M->L %s\n", d);



	system("pause");
	return 0;
}