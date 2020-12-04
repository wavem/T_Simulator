//---------------------------------------------------------------------------

#ifndef VersionH
#define VersionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormVersion : public TForm
{
__published:	// IDE-managed Components
	TPanel *__pnBase_Version;
	TLabel *lb_ProgramName;
	TLabel *lb_Version;
	TLabel *lb_UpdateDate;
	TLabel *lb_DeveloperName;
private:	// User declarations
public:		// User declarations
	__fastcall TFormVersion(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormVersion *FormVersion;
//---------------------------------------------------------------------------
#endif
