//#include<Windows.h>
//#include<iostream>
//#pragma warning(disable:4996)
//
//using namespace std;
//
//int main(int argc, char * argv[]) {
//	OSVERSIONINFO	osver;
//	//char			RecordInfor[1024];
//	//ZeroMemory(RecordInfor, 1024);
//
//	osver.dwOSVersionInfoSize = sizeof(OSVERSIONINFO); //��ȡOSVERSIONINFO�ṹ��Ĵ�С
//
//	if (!GetVersionEx(&osver)) { // �Ƿ��ȡ�ɹ�
//		cout << "��ȡϵͳ�汾ʧ��" << endl;
//		return -1;
//	}
//
//	if (osver.dwMajorVersion == 5) {  //��ȡ�ɹ���ô�ͼ���������ж�
//		if (osver.dwMinorVersion == 0) {
//			cout << "ϵͳ�汾ΪWIN 2000" << endl;
//		}
//		else if (osver.dwMinorVersion == 1) {
//			cout << "ϵͳ�汾ΪWIN XP" << endl;
//		}
//		else if (osver.dwMinorVersion == 2) {
//			cout << "ϵͳ�汾ΪWIN 2003" << endl;
//		}
//	}
//	else if (osver.dwMajorVersion == 6) {
//		if (osver.dwMinorVersion == 0) {
//			cout << "ϵͳ�汾ΪWIN Vista" << endl;
//		}
//		else if (osver.dwMinorVersion == 1) {
//			cout << "ϵͳ�汾ΪWIN 7 ���� Windows Server 2008 R2" << endl;
//		}
//		else if (osver.dwMinorVersion == 2) {
//			cout << "ϵͳ�汾ΪWIN 8 ���� Windows Server 2012" << endl;
//		}
//		else if (osver.dwMinorVersion == 3) {
//			cout << "ϵͳ�汾ΪWIN 8.1 ���� Windows Server 2012 R2" << endl;
//		}
//	}
//	else if (osver.dwMajorVersion == 10) {
//		if (osver.dwMinorVersion == 0) {
//			cout << "ϵͳ�汾ΪWIN 10 ���� Windows Server 2016 Technical Preview " << endl;
//		}
//	}
//	else {
//		cout << "�޷�ʶ��" << endl;
//	}
//
//	cout << "�߰汾�ţ�" << osver.dwMajorVersion << "���ΰ汾�ţ�" << osver.dwMinorVersion << "��build�汾��" << osver.dwBuildNumber << endl;
//	
//	DWORD	dwComputerLen = MAX_COMPUTERNAME_LENGTH + 1;
//	wchar_t	ComputerName[MAX_COMPUTERNAME_LENGTH + 1];
//	
//	GetComputerName(ComputerName, &dwComputerLen); //��ü������
//	cout << ComputerName << endl;
//
//	DWORD dwComputerUserLen = 64;
//	wchar_t ComputerUserName[64];
//	GetUserName(ComputerUserName, &dwComputerUserLen);//��õ�ǰ��½�������û���
//	cout << ComputerUserName << endl;
//
//	
//
//
//
//	cout << "--------------------------------------------------------------------" << endl;
//	cout << "------------------------------Ӳ����Ϣ------------------------------" << endl;
//	cout << "--------------------------------------------------------------------" << endl;
//	
//	SYSTEM_INFO sys_info;  //����һ��SYSTEM_INFO�ṹ��
//
//	GetSystemInfo(&sys_info); //�����йص�ǰϵͳ����Ϣ
//	cout << "������������"<<  sys_info.dwNumberOfProcessors << endl; // ����������
//	cout << "�ڴ��ҳ��С��"<< sys_info.dwPageSize << endl; //�ڴ��ҳ��С
//	cout << "�����ڴ���ʼ��С��" << sys_info.lpMinimumApplicationAddress << endl; //�����ڴ���ʼ��С
//	cout << "�����ڴ������С��" <<sys_info.lpMaximumApplicationAddress << endl; //�����ڴ������С
//	cout << "���������ͣ�" << sys_info.dwProcessorType << endl; //����������
//	cout << "�������ܹ���" << sys_info.wProcessorArchitecture << endl; //�������ܹ�
//	system("pause");
//	return 0;
//
//}