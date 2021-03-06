//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include "Define.h"
#include "TCPSocketThread.h"
#include "Version.h"

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "dxBar.hpp"
#include "dxRibbon.hpp"
#include "dxRibbonCustomizationForm.hpp"
#include "dxRibbonSkins.hpp"
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinsdxBarPainter.hpp"
#include "dxSkinsdxRibbonPainter.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "AdvMemo.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include <Vcl.Grids.hpp>
#include <Vcl.ImgList.hpp>
#include "AdvGlassButton.hpp"
#include "AdvEdit.hpp"
//---------------------------------------------------------------------------
class CTcpSocketThread;
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TdxRibbon *RibbonMenu;
	TdxRibbonTab *RibbonMenuTab_Main;
	TdxBarManager *BarMgr;
	TdxBar *BarMgrBar1;
	TdxBarLargeButton *MenuBtn_View;
	TdxBarLargeButton *MenuBtn_Setting;
	TdxBarLargeButton *dxBarLargeButton3;
	TPanel *__pnBase;
	TNotebook *Notebook_Main;
	TPanel *_pnBase_01_Main;
	TPanel *_pnBase_02_Setting;
	TdxBar *BarMgrBar2;
	TdxBarLargeButton *MenuBtn_Version;
	TPanel *pnBase_Status;
	TAdvMemo *memo;
	TAdvMemo *AdvMemo1;
	TAdvStringGrid *grid;
	TImageList *ImgList;
	TTimer *tm_Connect_Lamp;
	TPanel *_pnBase_03_Login;
	TPanel *_pnBase_04_Lobby;
	TPanel *_pnBase_05_InGame;
	TAdvGlassButton *btn_Send;
	TAdvEdit *ed_Chat;
	TAdvEdit *ed_Signup_UserName;
	TLabel *lb_Login_Signup_UserName;
	TLabel *lb_Login_Title_Signup;
	TLabel *lb_Login_Title_Signin;
	TLabel *lb_Login_Title_Signout;
	TLabel *lb_Login_Signup_UserID;
	TLabel *lb_Login_Signup_Password;
	TAdvEdit *ed_Signup_UserID;
	TAdvEdit *ed_Signup_UserPW;
	TButton *btn_Signup;
	TLabel *lb_Login_Signin_UserName;
	TLabel *lb_Login_Signin_UserID;
	TLabel *lb_Login_Signin_Password;
	TAdvEdit *ed_Signin_UserName;
	TAdvEdit *ed_Signin_UserID;
	TAdvEdit *ed_Signin_UserPW;
	TButton *btn_Signin;
	TButton *btn_Signout;
	TLabel *lb_Login_Signout_UserName;
	TLabel *lb_Login_Signout_UserID;
	TLabel *lb_Login_Signout_Password;
	TAdvEdit *ed_Signout_UserName;
	TAdvEdit *ed_Signout_UserID;
	TAdvEdit *ed_Signout_UserPW;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall MenuBtn_ViewClick(TObject *Sender);
	void __fastcall MenuBtn_SettingClick(TObject *Sender);
	void __fastcall gridButtonClick(TObject *Sender, int ACol, int ARow);
	void __fastcall MenuBtn_VersionClick(TObject *Sender);
	void __fastcall tm_Connect_LampTimer(TObject *Sender);
	void __fastcall btn_SendClick(TObject *Sender);
	void __fastcall ed_ChatKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall btn_SignupClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);

// START TETRIS SIMULATOR
public: // MEMBER
	CTcpSocketThread *m_Client[MAX_CLIENT_COUNT];
	SOCKET m_sock_Client[MAX_CLIENT_COUNT];
	int m_SelectedClientIdx;

public: // BASIC FUNCTIONS
	void __fastcall InitProgram();
	void __fastcall ExitProgram();
	void __fastcall PrintMsg(UnicodeString _str);
	void __fastcall InitGrid();



	bool __fastcall CreateTCPSocket(SOCKET* _socket);
	bool __fastcall DeleteTCPSocket(SOCKET* _socket);
	void __fastcall ClickConnectButton(int _ColIdx, int _RowIdx);
	void __fastcall ClickDisConnectButton(int _ColIdx, int _RowIdx);
	void __fastcall ClickEnterButton(int _ColIdx, int _RowIdx);

	// Send
	bool __fastcall SendChatData();

	// Message Handler
	void __fastcall ReceiveMsg(TMessage &_msg);


BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(MSG_FROM_THREAD, TMessage, ReceiveMsg)
END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
