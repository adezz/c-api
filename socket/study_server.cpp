#include<winSock2.h>
#include<iostream>
#pragma comment(lib, "ws2_32.lib") //��Ӷ�̬���ӿ�

using namespace std;

int main(int argc, char * argv[]) {
	const int	BUFSIZE = 1024;
	SOCKET		ListeningSocket; //����һ���׽��ֱ���
	SOCKET		NewConnection; //�ͻ��˵��������ɵ��µ��׽���
	SOCKADDR_IN ClientAddr;
	SOCKADDR_IN ServerAddr;
	char		Message[BUFSIZE];
	int			ClientAddrLen;
	ZeroMemory(Message, BUFSIZE);
	
	if (argc <= 1)
	{
		cout << "USAGE: TcpServer <Listen Port>" << endl;
		return -1;
	}

	
	int ret; //��������ʼ���ɹ��Ƿ�
	WSADATA wsaDATA; // ����һ��WSADATA ������ʼ���׽��������
	
	if ( (ret = WSAStartup(MAKEWORD(2,2), &wsaDATA)) != 0) { // ��ʼ���׽��������WinSock2.2�汾
		cout << "WSAStartup��ʼ��ʧ�� with error " << ret << endl;
		return -1;
	}

	//�����׽��� AF_INETЭ�� SOCK_STREAM�� TCPЭ��
	if ((ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR) {
		cout << "�����׽���ʧ�� with error " << WSAGetLastError() << endl;
		WSACleanup();
		return -1; 
	}

	//���׽���
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(atoi(argv[1]));
	ServerAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	if (bind(ListeningSocket, (SOCKADDR *)&ServerAddr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		cout << "���׽���ʧ�� with error " << WSAGetLastError() << endl;
		closesocket(ListeningSocket);
		WSACleanup();
		return -1;
	}
	 
	//�����׽���
	if((ret = listen(ListeningSocket, 1)) == SOCKET_ERROR) {
		cout << "�����׽���ʧ�� with error " << WSAGetLastError() << endl;
		closesocket(ListeningSocket);
		WSACleanup();
		return -1;
	}
	cout << "���ڼ����˿�"<< argv[1] << "��..." << endl;


	//���տͻ�������

	ClientAddrLen = sizeof(SOCKADDR);

	if((NewConnection = accept(ListeningSocket,(SOCKADDR*)&ClientAddr, &ClientAddrLen)) == INVALID_SOCKET){//����һ����ǰ�ͻ��˺ͷ���˵��׽���
		cout << "����NewConnectionʧ�� with error " << WSAGetLastError() << endl;
		closesocket(ListeningSocket);
		WSACleanup();
		return -1;
	}

	//�ر��׽���
	closesocket(ListeningSocket);

	recv(NewConnection, Message, sizeof(Message), 0);
	cout << "���յ�������Ϊ:" << Message << endl;


	closesocket(NewConnection);
	WSACleanup();
	

	return 0;
}