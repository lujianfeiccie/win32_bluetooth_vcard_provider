#include "StdAfx.h"
#include "SocketClient.h"

SocketClient::SocketClient(void)
{
 WORD wVersionRequested;
 WSADATA wsaData;
 int err;
 
 wVersionRequested = MAKEWORD( 1, 1 );
 
 err = WSAStartup( wVersionRequested, &wsaData );
 if ( err != 0 ) {
  return;
 }
 
 if ( LOBYTE( wsaData.wVersion ) != 1 ||
        HIBYTE( wsaData.wVersion ) != 1 ) {
  WSACleanup( );
  return;
 }
}
SocketClient::~SocketClient(void)
{
}
int SocketClient::Connect(const char* ip,unsigned short port)
{
 sockClient=socket(AF_INET,SOCK_STREAM,0);
 
  SOCKADDR_IN addrSrv;
  addrSrv.sin_addr.S_un.S_addr=inet_addr(ip);
  addrSrv.sin_family=AF_INET;
  addrSrv.sin_port=htons(port);
  int result = connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
 return result;
}
int SocketClient::Send(const char* buffer,int len)
{
 int result = send(sockClient,buffer,len,0);
 return result;
}
int SocketClient::Read(char* buffer)
{
 int result = recv(sockClient,buffer,1024,0);
 return result;
}
int SocketClient::Disconnect()
{
 int result = closesocket(sockClient);
    WSACleanup();
 return result;
}