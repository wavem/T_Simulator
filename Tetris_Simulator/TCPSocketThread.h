//---------------------------------------------------------------------------

#ifndef TCPSocketThreadH
#define TCPSocketThreadH
//---------------------------------------------------------------------------
#include "Main.h"

enum ThreadWorkingType
{
	THREAD_STOP = 0,
	THREAD_RUNNING = 1,
	THREAD_TERMINATED = 2,
};
//---------------------------------------------------------------------------

class CTcpSocketThread : public TThread {
private:
	ThreadWorkingType	m_eThreadWork;
	SOCKET	*m_sock;

protected:
public: // Variables
	BYTE sendBuff[TCP_SEND_BUF_SIZE];
	BYTE* p_sendText;
	BYTE recvBuff[TCP_RECV_BUF_SIZE];
	bool isTryingToConnect;
	bool isConnected;

public: // Functions
	__fastcall CTcpSocketThread(SOCKET *p_sock);
	__fastcall ~CTcpSocketThread();
	void __fastcall Execute();
	void __fastcall Stop();
	void __fastcall Resume();
	void __fastcall DoTerminate();
	ThreadWorkingType __fastcall GetThreadStatus();
};
//---------------------------------------------------------------------------
#endif
