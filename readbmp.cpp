// readbmp.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <string.h>
#include<stdlib.h>
#include "SocketClient.h"
int _tmain(int argc, _TCHAR* argv[])
{
	SocketClient *client = new SocketClient;
	client->Connect("127.0.0.1",5000);

	//length=123
	client->Send("len",strlen("len"));
	Sleep(1000);
	client->Send("gth=",strlen("gth="));
	Sleep(1000);
	client->Send("12",strlen("12"));
	Sleep(1000);
	client->Send("3\r\n",strlen("3\r\n"));
	Sleep(1000);
	client->Disconnect();
	delete client;
	client = NULL;
 return 0;
}

