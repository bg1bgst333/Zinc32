// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow
#include "resource.h"		// リソース

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() : CWindow(){

	// メンバの初期化.
	m_pEdit = NULL;	// m_pEditをNULLで初期化.
	m_pButton = NULL;	// m_pButtonをNULLで初期化.
	m_pWebBrowser = NULL;	// m_pWebBrowserをNULLで初期化.

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow(){

	// メンバの終了処理.
	if (m_pEdit != NULL){	// m_pEditがNULLでなければ.
		DestroyWindow(m_pEdit->m_hWnd);	// DestroyWindowでm_pEdit->m_hWndを破棄.
		delete m_pEdit;	// deleteでm_pEditを解放.
		m_pEdit = NULL;	// m_pStaticにNULLをセット.
	}
	if (m_pButton != NULL){	// m_pButtonがNULLでなければ.
		DestroyWindow(m_pButton->m_hWnd);	// DestroyWindowでm_pStatic->m_hWndを破棄.
		delete m_pButton;	// deleteでm_pButtonを解放.
		m_pButton = NULL;	// m_pButtonにNULLをセット.
	}
	if (m_pWebBrowser != NULL){	// m_pWebBrowserがNULLでなければ.
		DestroyWindow(m_pWebBrowser->m_hWnd);	// DestroyWindowでm_pWebBrowser->m_hWndを破棄.
		delete m_pWebBrowser;	// deleteでm_pWebBrowserを解放.
		m_pWebBrowser = NULL;	// m_pWebBrowserにNULLをセット.
	}

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance){

	// ウィンドウプロシージャにはCWindow::StaticWndowProc, メニューはなし(NULL)とする.((LPCTSTR)でキャストしないとオーバーロードが曖昧になる.)
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), (LPCTSTR)NULL);	// CWindow::RegisterClassで登録.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CMainWindow"を指定.

}

// ウィンドウの作成が開始された時.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// エディットコントロールオブジェクトの作成
	m_pEdit = new CEdit();	// CEditオブジェクトの作成.

	// エディットコントロールのウィンドウ作成.
	m_pEdit->Create(_T(""), WS_BORDER | ES_WANTRETURN, 0, 0, 640, 24, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// m_pEdit->Createで作成.

	// ボタンコントロールオブジェクトの作成
	m_pButton = new CButton();	// CButtonオブジェクトの作成.

	// ボタンコントロールのウィンドウ作成.
	m_pButton->Create(_T("ロード"), BS_PUSHBUTTON, 640, 0, 80, 24, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// m_pButton->Createで作成.

	// ボタンハンドラの追加.
	AddCommandHandler(WM_APP + 2, BN_CLICKED, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnLoad);	// AddCommandHandlerでWM_APP + 2に対するハンドラCMainWindow::OnLoadを登録.

	// ウェブブラウザコントロールオブジェクトの作成.
	m_pWebBrowser = new CWebBrowser();	// CWebBrowserオブジェクトの作成.

	// ウェブブラウザコントロールのウィンドウ作成.
	m_pWebBrowser->Create(_T(""), WS_BORDER, 0, 24, 640, 480 - 24, hwnd, (HMENU)(WM_APP + 3), lpCreateStruct->hInstance);	// m_pWebBrowser->Createで作成.

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy(){

	// ハンドラの削除.
	DeleteCommandHandler(WM_APP + 2, BN_CLICKED);	// DeleteCommandHandlerでWM_APP + 2, BN_CLICKEDのハンドラを削除.

	// 子ウィンドウオブジェクトの破棄.
	if (m_pEdit != NULL){	// m_pEditがNULLでなければ.
		DestroyWindow(m_pEdit->m_hWnd);	// DestroyWindowでm_pEdit->m_hWndを破棄.
		delete m_pEdit;	// deleteでm_pEditを解放.
		m_pEdit = NULL;	// m_pStaticにNULLをセット.
	}
	if (m_pButton != NULL){	// m_pButtonがNULLでなければ.
		DestroyWindow(m_pButton->m_hWnd);	// DestroyWindowでm_pStatic->m_hWndを破棄.
		delete m_pButton;	// deleteでm_pButtonを解放.
		m_pButton = NULL;	// m_pButtonにNULLをセット.
	}
	if (m_pWebBrowser != NULL){	// m_pWebBrowserがNULLでなければ.
		DestroyWindow(m_pWebBrowser->m_hWnd);	// DestroyWindowでm_pWebBrowser->m_hWndを破棄.
		delete m_pWebBrowser;	// deleteでm_pWebBrowserを解放.
		m_pWebBrowser = NULL;	// m_pWebBrowserにNULLをセット.
	}

	// 親ウィンドウのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMainWindow::OnSize(UINT nType, int cx, int cy){

	// ウィンドウのサイズ変更.
	if (m_pEdit != NULL){
		MoveWindow(m_pEdit->m_hWnd, 0, 0, cx - 80, 24, TRUE);	// MoveWindowでm_pEdit->m_hWndのサイズを変更.
	}
	if (m_pButton != NULL){
		MoveWindow(m_pButton->m_hWnd, cx - 80, 0, 80, 24, TRUE);	// MoveWindowでm_pButton->m_hWndのサイズを変更.
	}
	if (m_pWebBrowser != NULL){
		MoveWindow(m_pWebBrowser->m_hWnd, 0, 24, cx, cy - 24, TRUE);	// MoveWindowでm_pWebBrowser->m_hWndのサイズを変更.
	}

}

// "ロード"ボタンが押された時のハンドラ.
int CMainWindow::OnLoad(WPARAM wParam, LPARAM lParam){

	// m_pEditに入力されたテキストを表示.
	MessageBox(m_hWnd, m_pEdit->GetText().c_str(), _T("Zinc"), MB_OK | MB_ICONASTERISK);	// MessageBoxでm_pEdit->GetTextで取得したテキストを表示.
	return 0;	// 0を返す.

}