//---------------------------------------------------------------------------

#pragma hdrstop

#include "TCPSocketThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall CTcpSocketThread::CTcpSocketThread(SOCKET *p_sock) {
	m_eThreadWork = THREAD_STOP;
	Priority = tpTimeCritical;
	m_sock = p_sock;
	isTryingToConnect = true;
	isConnected = false;
}
//---------------------------------------------------------------------------

__fastcall CTcpSocketThread::~CTcpSocketThread() {
	UnicodeString tempStr = L"Thread Terminated (from Thread Destroyer)";
	SendMessage(FormMain->Handle, MSG_FROM_THREAD, (unsigned int)&tempStr, 0x10);
}
//---------------------------------------------------------------------------

void __fastcall CTcpSocketThread::Execute() {

	// Common
	UnicodeString t_Str = L"";
	AnsiString t_AnsiStr = "";
	int t_errno = 0;
	int t_ConnectTryingCount = 1;

	struct sockaddr_in	t_sockaddr_in;
	memset(&t_sockaddr_in, 0, sizeof(t_sockaddr_in));
	t_sockaddr_in.sin_family = AF_INET;
	t_sockaddr_in.sin_addr.s_addr = inet_addr(IP_SERVER);
	t_sockaddr_in.sin_port = htons(TCP_SERVER_PORT);

	t_Str = L"Thread Start";
	SendMessage(FormMain->Handle, MSG_FROM_THREAD, (unsigned int)&t_Str, 0x10);
	m_eThreadWork = THREAD_RUNNING;

	// Try to Connect
	while(!Terminated) {
		// For Thread Stop & Resume
		if(m_eThreadWork != THREAD_RUNNING) {
			if(m_eThreadWork == THREAD_TERMINATED) return;
			WaitForSingleObject((void*)this->Handle, 500);
			continue;
		}

		if(t_ConnectTryingCount < 6) {
			t_errno = connect(*m_sock, (struct sockaddr*)&t_sockaddr_in, sizeof(sockaddr_in));
			if(t_errno < 0) {
				t_Str.sprintf(L"Connection Error : Trying Count(%d)", t_ConnectTryingCount);
				SendMessage(FormMain->Handle, MSG_FROM_THREAD, (unsigned int)&t_Str, 0x10);

				t_AnsiStr = strerror(t_errno);
				t_Str = L"Error String : ";
				t_Str += t_AnsiStr;
				SendMessage(FormMain->Handle, MSG_FROM_THREAD, (unsigned int)&t_Str, 0x10);
				m_eThreadWork == THREAD_TERMINATED;
				t_ConnectTryingCount++;
				continue;
			} else {
				t_Str = L"Connected !!!";
				SendMessage(FormMain->Handle, MSG_FROM_THREAD, (unsigned int)&t_Str, 0x10);
				isTryingToConnect = false;
				isConnected = true;
				break;
			}
		} else {
			isTryingToConnect = false;
			isConnected = false;
			t_Str = L"Fail to Connect to Server...";
			SendMessage(FormMain->Handle, MSG_FROM_THREAD, (unsigned int)&t_Str, 0x10);
			break;
		}

		// Just Wait Moment...
		WaitForSingleObject((void*)this->Handle, 1000);
	}

	if(isConnected == false) {
		m_eThreadWork = THREAD_TERMINATED;
		return;
	}

	// Receive Routine
	BYTE recv_buff[TCP_RECV_BUF_SIZE];
	ZeroMemory( &recv_buff, sizeof(recv_buff));
	int recv_buff_size = sizeof(recv_buff);

	while(!Terminated) {
		// For Thread Stop & Resume
		if(m_eThreadWork != THREAD_RUNNING) {
			if(m_eThreadWork == THREAD_TERMINATED) return;
			WaitForSingleObject((void*)this->Handle, 500);
			continue;
		}

		// Receive Routine Funtion
		if(Receive()) {
			t_Str = L"Success to Receive";
			SendMessage(FormMain->Handle, MSG_FROM_THREAD, (unsigned int)&t_Str, 0x10);
		} else {
			t_Str = L"Fail to Receive";
			SendMessage(FormMain->Handle, MSG_FROM_THREAD, (unsigned int)&t_Str, 0x10);
			return;
		}

		// Just Wait Moment...
		WaitForSingleObject((void*)this->Handle, 100);
	}
	m_eThreadWork = THREAD_TERMINATED;
	return;
}
//---------------------------------------------------------------------------

bool __fastcall CTcpSocketThread::Receive() {

	// Common
	UnicodeString tempStr = L"";
	int t_recvSize = 0;
	int t_CurrentSize = 0;
	BYTE t_SecureCode = 0;
	unsigned short t_PacketSize = 0;
	BYTE t_MessageType = 0;

	// Reset Buffer
	memset(recvBuff, 0, sizeof(recvBuff));

	// First Receive
	t_recvSize = recv(*m_sock, (char*)&t_SecureCode, 1, 0);

	// Check Connection
	if(t_recvSize == 0 || t_recvSize == -1) return false;

	// Check Secure Code
	if(t_SecureCode != SECURE_CODE_C_TO_S) return false;

	// Check Data Size
	t_recvSize = recv(*m_sock, (char*)&t_PacketSize, 2, 0);

	// Check Message Type
	t_recvSize = recv(*m_sock, (char*)&t_MessageType, 1, 0);

	// Receive Routine
	t_CurrentSize = 4;
	while(t_CurrentSize != t_PacketSize) {
		t_recvSize = recv(*m_sock, (char*)(recvBuff + t_CurrentSize), t_PacketSize - t_CurrentSize, 0);
		t_CurrentSize += t_recvSize;
	}

	return true;
}
//---------------------------------------------------------------------------

void __fastcall CTcpSocketThread::Stop() {
	m_eThreadWork = THREAD_STOP;
}
//---------------------------------------------------------------------------

void __fastcall CTcpSocketThread::Resume() {
	m_eThreadWork = THREAD_RUNNING;
}
//---------------------------------------------------------------------------

void __fastcall CTcpSocketThread::DoTerminate() {
	m_eThreadWork = THREAD_TERMINATED;
}
//---------------------------------------------------------------------------

ThreadWorkingType __fastcall CTcpSocketThread::GetThreadStatus() {
	return m_eThreadWork;
}
//---------------------------------------------------------------------------


#if 0
	// From KVMRT2 Source

	// Common
	UnicodeString t_Str = L"";
	UnicodeString tempStr = L"";

	struct sockaddr_in multicastAddr;
	multicastAddr.sin_family = AF_INET;
	multicastAddr.sin_addr.s_addr = inet_addr(MULTICAST_IP);
	multicastAddr.sin_port = htons(MULTICAST_PORT);

	m_eThreadWork = THREAD_RUNNING;
	while(!Terminated) {
		if(m_eThreadWork != THREAD_RUNNING) {
			if(m_eThreadWork == THREAD_TERMINATED) break;
			WaitForSingleObject((void*)this->Handle, 500);
			continue;
		}

		unsigned char recv_buff[MCAST_PACKET_SIZE_RCV];
		ZeroMemory( &recv_buff, sizeof(recv_buff));
		int recv_buff_size = sizeof(recv_buff);

		struct sockaddr_in sender_addr;
		int sender_addr_size = sizeof(sender_addr);

		int recv_size = recvfrom( *m_MCast_socket, recv_buff, recv_buff_size, 0, (SOCKADDR*)&sender_addr, &sender_addr_size);
		if(recv_size < 0)
		{
			t_Str = L"Receive Error ";
			SendMessage(FormMain->Handle, MSG_LOG, (unsigned int)&t_Str, 0x10);
		} else {
			// Continue, If received packet is from mine.
			if(recv_size == 8) continue;

			// Convert IP Address as String
			t_Str = inet_ntoa(sender_addr.sin_addr);

			// Set Connection Information
			for(int i = 0 ; i < 8 ; i++) {
				if(t_Str == t_StrList_IP[i]) {
					///FormMain->m_Info[i].m_isConnected = true;
					//FormMain->m_Info[i].m_ConnectionTimeOutCnt = 0;
					memcpy(FormMain->m_Info[i].m_DataBuf, recv_buff, MCAST_PACKET_SIZE_RCV);
				}
			}

			// Show Received Data
			t_Str += L" : ";
			for(int i = 0 ; i < MCAST_PACKET_SIZE_RCV ; i++) {
				tempStr.sprintf(L"%02X ", recv_buff[i]);
				t_Str += tempStr;
			}
			//SendMessage(FormMain->Handle, MSG_LOG, (unsigned int)&t_Str, 0x10);
		}

		WaitForSingleObject((void*)this->Handle, 50);
	}
	m_eThreadWork = THREAD_TERMINATED;

#endif
