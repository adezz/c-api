#include<stdio.h>
#include<windows.h>


/*
 * ʵ�ֵݹ����Ŀ¼�Ĳ���
 * ʹ�õ�API������������
 * FindFirstFile
 * FindNextFile
 * WIN32_FIND_DATA
*/
DWORD EnumerateFileInDirectory(LPCWSTR szPath){
	WIN32_FIND_DATA FindFileData;
	HANDLE hListFile; //����һ��ʵ����� ������FindFirstFile api�������صĶ���
	wchar_t szFilePath[MAX_PATH];
	wchar_t szFullPath[MAX_PATH]; //����·��

	lstrcpy(szFilePath, szPath);
	lstrcat(szFilePath, L"\\*");

	hListFile = FindFirstFile(szFilePath, &FindFileData); //FindFirstFile���szFilePath
	if(hListFile == INVALID_HANDLE_VALUE){
		printf("����%d \n", GetLastError());
		return 1;
	}else {
		do {
			if (lstrcmp(FindFileData.cFileName, L".") == 0 || lstrcmp(FindFileData.cFileName, L"..") == 0){
				continue;
			}


			wsprintf(szFullPath, L"%ls\\%ls", szPath, FindFileData.cFileName);
			//printf("%ls\\%ls", szPath, FindFileData.cFileName);
			printf("\n%ls\t", szFullPath);
			//if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) { //�ж��ļ��������Ƿ�Ϊ���أ�����ǵĻ� �����ǰ׺ΪHIDDEN
			//	printf("<HIDDEN> ");
			//}
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { //�ж��Ƿ���Ŀ¼������ǵĻ� �����ǰ׺ΪDIR
				printf("\t<DIR>");
				EnumerateFileInDirectory(szFullPath);
			}
			
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE) {
				printf("\t<FILE>");
			}

			//printf("\n");

		} while (FindNextFile(hListFile, &FindFileData));
	}
	printf("\n");
	return 0;
}



int main() {

	EnumerateFileInDirectory(L"C:\\Users\\dell\\source\\repos\\msgboxtest");
	system("pause");
	return 0;
}