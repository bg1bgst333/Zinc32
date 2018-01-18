// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// オブジェクトの宣言.
	CMainApplication app;	// CMainApplicationオブジェクトapp.

	// インスタンスの初期化.
	if (!app.InitInstance(hInstance, lpCmdLine, nShowCmd)){	// app.InitInstanceがFALSEの場合.

		// 異常終了.
		app.ExitInstance();	// app.ExitInstanceで終了処理を実行.
		return -1;	// returnで-1を返して異常終了.

	}

	// メッセージループ.
	int iRet = app.Run();	// app.Runでメッセージループに入り, 戻り値をiRetに格納.

	// 正常終了.
	return iRet;	// iRetを返す.

}