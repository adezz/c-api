//#include<Windows.h>
//#include<iostream>
//#define NUMSIZE 100000
//
//using namespace std;
//
//int compare_func(const void *a, const void *b) { //���������������͵�ָ��
//	return *(int *)a - *(int *)b; // �Ƚϵ���intֵ ������Ҫת��Ϊint���͵�ָ�� Ȼ����ȡֵ���бȽ�
//}
//
//int main(int argc, char * argv[]) {
//
//	SYSTEMTIME st;
//	GetLocalTime(&st); //��ȡ��ǰ������ʱ�丳ֵ���ṹ��st
//	cout << "[" << st.wYear << "-" << st.wMonth << "-" << st.wDay << " " << st.wHour << "ʱ" << st.wMinute << "��" << st.wSecond << "��]" << endl;
//
//	st.wHour--;
//	SetLocalTime(&st); //����ʱ��
//	cout << "[" << st.wYear << "-" << st.wMonth << "-" << st.wDay << " " << st.wHour << "ʱ" << st.wMinute << "��" << st.wSecond << "��]" << endl;
//
//	int arr[NUMSIZE];
//
//	srand(GetTickCount());
//
//	for (int i = 0; i < NUMSIZE; i++) {
//		arr[i] = rand() % 1000;
//	}
//	/*
//	qsort�÷�
//	base -- ָ��Ҫ���������ĵ�һ��Ԫ�ص�ָ�롣
//	nitems -- �� base ָ���������Ԫ�صĸ�����
//	size -- ������ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ��
//	compare -- �����Ƚ�����Ԫ�صĺ�����
//	*/
//	int startTime = GetTickCount(); //ȡ��ʼ�����ʱ��
//	qsort(arr, NUMSIZE, sizeof(arr[0]), compare_func);
//	int endTime = GetTickCount(); //ȡ��ʼ�����ʱ��
//	cout << "�ܺ�ʱ " << endTime - startTime << "����" << endl;
//
//
//	//for (int i = 0; i < NUMSIZE; i++)
//	//	cout << arr[i] << endl;
//
//	system("pause");
//	return 0;
//}