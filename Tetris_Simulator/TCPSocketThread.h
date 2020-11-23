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
public:
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
