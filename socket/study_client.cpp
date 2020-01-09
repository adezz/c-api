#include<WinSock2.h>
#include<iostream>
#pragma comment(lib, "ws2_32.lib") //��Ӷ�̬���ӿ�
#pragma warning(disable:4996) //���Ծɺ���ʹ��ȱ�ݵľ���

using namespace std;

int main(int argc, char * argv[]) {
	const int	BUFSIZE = 1024;
	SOCKET		ClientSocket;
	SOCKADDR_IN ServerAddr;
	char		SendBuf[BUFSIZE];  //���ʹ洢�����ݻ�����
	char		BufRecv[BUFSIZE]; //�����յ������ݻ�����
	
	ZeroMemory(SendBuf, BUFSIZE);
	ZeroMemory(BufRecv, BUFSIZE);
	strcpy(SendBuf, "Hello, My Name is Client");

	if (argc <= 2)
	{
		cout << "USAGE: TcpServer <Server IP> <Server PORT>" << endl;
		return -1;
	}

	WSADATA		WSAData;
	int			ret;
	if ((ret = WSAStartup(MAKEWORD(2, 2), &WSAData)) != 0) {
		cout << "WSAStartup��ʼ��ʧ�� with error " << ret << endl;
		return -1;
	}
	

	//�����׽���
	if ((ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR) {
		cout << "�����׽���ʧ�� with error " << WSAGetLastError() << endl;
		WSACleanup();
		return -1;
	}

	//����connet�����
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.s_addr = inet_addr(argv[1]);
	ServerAddr.sin_port = htons(atoi(argv[2]));
	if (connect(ClientSocket, (SOCKADDR *)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR) {
		cout << "���ӷ����ʧ�� with error " << WSAGetLastError() << endl;
		closesocket(ClientSocket);
		WSACleanup();
		return -1;
	}

	cout << "���ӽ����ɹ�!";


	//send��������
	if ((ret = send(ClientSocket, SendBuf, strlen(SendBuf), 0)) == SOCKET_ERROR){
		cout << "send failed with error " << WSAGetLastError() << endl;;
		closesocket(ClientSocket);
		WSACleanup();
		return -1;
	}

	//�ر��׽���
	closesocket(ClientSocket);
	WSACleanup();
	return 0;

	
}