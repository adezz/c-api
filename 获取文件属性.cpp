#include<stdio.h>
#include<Windows.h>

/*
WIN32_FILE_ATTRIBUTE_DATA
GetFileAttributesEx

*/
DWORD ShowFileAttribute(LPCWSTR FilePath) { 
	WIN32_FILE_ATTRIBUTE_DATA wfad;//����һ���ṹ��
	if (GetFileAttributesEx(FilePath, GetFileExInfoStandard, &wfad) {

	}
}

int main() {
	ShowFileAttribute(L"C:\\Users\\dell\\source\\repos\\msgboxtest\\AbleWrite.txt");
	system("pause");
	return 0;

}