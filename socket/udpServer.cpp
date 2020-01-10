#include<WinSock2.h>
#include<iostream>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main(int argc, char * argv[]) {
	const int BUFSIZE = 1024;
	SOCKET		ServerSocket;
	SOCKADDR_IN ServerAddr;
	SOCKADDR_IN ClientAddr;
	WSADATA		wsaData;
	char		buf[BUFSIZE];
	int ret;
	
	if ((ret = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		cout << "WSAStartup����ʧ��" << endl;
		return -1;
	}

	//�����׽���socket

	if((ServerSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
		cout << "�����׽���ʧ��" << WSAGetLastError() << endl;
		WSACleanup();
		return -1;
	}

	//���׽���
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	ServerAddr.sin_port = htons(atoi(argv[1]));
	
	if(bind(ServerSocket, (SOCKADDR *)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR) {
		cout << "���׽���ʧ�� " << WSAGetLastError() << endl;
		closesocket(ServerSocket);
		WSACleanup();
		return -1;
	}
	int ClientLen = sizeof(ClientAddr);
	cout << "�˿�:" << argv[1] << "���ڽ�������...." << endl;
	while (true) {
		//��������
		ZeroMemory(buf, sizeof(buf));
		if ((ret = recvfrom(ServerSocket, buf, sizeof(buf), 0, (SOCKADDR *)&ClientAddr, &ClientLen)) == SOCKET_ERROR) {
			cout << "��������ʧ��" << WSAGetLastError() << endl;
			closesocket(ServerSocket);
			WSACleanup();
			return -1;
		}
		else {
			//��������
			cout << "�����: " << buf << endl;
			sendto(ServerSocket, buf, sizeof(buf), 0, (SOCKADDR *)&ClientAddr, ClientLen);
		}
	}

	closesocket(ServerSocket);
	WSACleanup();
	return 0;
}