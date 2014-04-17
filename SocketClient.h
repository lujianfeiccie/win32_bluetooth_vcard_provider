#pragma once
#include <winsock2.h>
class SocketClient
{
private:
 SOCKET sockClient;
public:
 SocketClient(void);
 ~SocketClient(void);
 int Connect(const char* ip,unsigned short port);
 int Send(const char* buffer,int len);
 int Read(char* buffer);
 int Disconnect();
};

