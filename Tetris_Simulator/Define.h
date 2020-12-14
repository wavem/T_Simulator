//---------------------------------------------------------------------------

#ifndef DefineH
#define DefineH
//---------------------------------------------------------------------------
#define MAX_CLIENT_COUNT 60

//#define IP_SERVER "127.0.0.1"
#define IP_SERVER "192.168.35.9"
//#define IP_SERVER "192.168.0.47"

#define TCP_SERVER_PORT 14759

#define MSG_FROM_THREAD	40000

#define TCP_SEND_BUF_SIZE 300
#define TCP_RECV_BUF_SIZE 1300
#define TCP_MAX_TEXT_LEN 296 // It will be used some day...

#define SECURE_CODE_C_TO_S	0x47
#define SECURE_CODE_S_TO_C	0x59


// DATA TYPE
#define DATA_TYPE_SIGN_UP			1
#define DATA_TYPE_SIGN_IN			2
#define DATA_TYPE_SIGN_OUT			3
#define DATA_TYPE_LOBBY_CHATTING	4
#define DATA_TYPE_INGAME_CHATTING	5
#define DATA_TYPE_CHANGE_USER_INFO	6
#define DATA_TYPE_INGAME_CMD		7
#define DATA_TYPE_ENTER_GAME_ROOM	8
#define DATA_TYPE_ESCAPE_GAME_ROOM	9
#define DATA_TYPE_HEART_BEAT		10
#define DATA_TYPE_INGAME_DATA		11

//---------------------------------------------------------------------------
#endif
