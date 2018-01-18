// 二重インクルード防止
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "Application.h"	// CApplication
#include "WebBrowserHost.h"	// CWebBrowserHost

// メインアプリケーションクラスCMainApplication
class CMainApplication : public CApplication{

	// publicメンバ
	public:

		// publicメンバ変数
		CWebBrowserHost *m_pWebBrowserHost;	// CWebBrowserHostオブジェクトポインタm_pWebBrowserHost.

		// publicメンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance.
		virtual int ExitInstance();	// 終了処理関数ExitInstance.

};

#endif