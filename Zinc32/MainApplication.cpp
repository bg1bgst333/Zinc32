// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"	// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// OLEの初期化.
	OleInitialize(NULL);	// OleInitializeでOLEの初期化.

	// CWebBrowserHostの生成.
	m_pWebBrowserHost = new CWebBrowserHost();	// CWebBrowserHostオブジェクトポインタをm_pWebBrowserHostに格納.

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance);	// CMainWindow::RegisterClassでウィンドウクラス"CMainWindow"を登録.
	CWebBrowser::RegisterClass(hInstance);	// CWebBrowser::RegisterCkassでウィンドウクラス"CWebBrowser"を登録.

	// CMainWindowオブジェクトの作成.
	m_pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, m_pMainWndに格納.

	// m_pMainWndにm_pWebBrowserHostをセット.
	((CMainWindow *)m_pMainWnd)->SetWebBrowserHost(m_pWebBrowserHost);	// m_pMainWnd->SetWebBrowserHostでm_pWebBrowserHostをセット.

	// ウィンドウの作成.
	if (!m_pMainWnd->Create(_T("Zinc"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->Createでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// 終了処理関数ExitInstance.
int CMainApplication::ExitInstance(){

	// メインウィンドウの破棄
	if (m_pMainWnd != NULL){	// m_pMainWndがNULLでない時.

		// 破棄する.
		delete m_pMainWnd;	// deleteでm_pMainWndを破棄.
		m_pMainWnd = NULL;	// m_pMainWndにNULLをセット.

	}

	// CWebBrowserHostの破棄
	if (m_pWebBrowserHost != NULL){	// m_pWebBrowserHostがNULLでない時.
		
		// 破棄する.
		delete m_pWebBrowserHost;	// deleteでm_pWebBrowserHostを破棄.
		m_pWebBrowserHost = NULL;	// m_pWebBrowserHostにNULLをセット.

	}

	// OLEの終了処理.
	OleUninitialize();	// OleUninitializeでOLEの終了処理.

	// 今回は常に0を返す.
	return 0;	// returnで0を返す.

}