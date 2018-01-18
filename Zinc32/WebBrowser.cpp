// ヘッダのインクルード
// 独自のヘッダ
#include "WebBrowser.h"	// CWebBrowser

// コンストラクタCWebBrowser
CWebBrowser::CWebBrowser() : CUserControl(){

	// メンバの初期化.
	m_pWebBrowserHost = NULL;	// m_pWebBrowserHostにNULLをセット.

}

// デストラクタ~CWebBrowser
CWebBrowser::~CWebBrowser(){

	// メンバの終了処理.
	m_pWebBrowserHost = NULL;	// m_pWebBrowserHostにNULLをセット.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CWebBrowser::RegisterClass(HINSTANCE hInstance){

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CWebBrowser"));	// CUserControl::RegisterClassで登録.

}

// ウィンドウ作成関数Create.
BOOL CWebBrowser::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウの作成.
	return CUserControl::Create(_T("CWebBrowser"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createで作成.

}

// WebBrowserHostのセットとアタッチ.
void CWebBrowser::Attach(CWebBrowserHost *pWebBrowserHost){

	// メンバにセット.
	m_pWebBrowserHost = pWebBrowserHost;	// m_pWebBrowserHostにpWebBrowserHostをセット.

	// アタッチ.
	if (m_hWnd != NULL){	// m_hWndがNULLでない時.
		m_pWebBrowserHost->Attach(m_hWnd);	// m_pWebBrowserHost->Attachでm_hWndをアタッチ.
	}

}

// URLのロード.
void CWebBrowser::Navigate(LPCTSTR lpctszUrl){

	// 指定のURLをロード.
	m_pWebBrowserHost->Navigate(lpctszUrl);	// m_pWebBrowserHost->NavigateでlpctszUrlをロード.

}

// ウィンドウの作成が開始された時.
int CWebBrowser::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CWebBrowser::OnDestroy(){

	// 親クラスのOnDestroyを呼ぶ.
	CUserControl::OnDestroy();	// CUserControl::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CWebBrowser::OnSize(UINT nType, int cx, int cy){

	// 変数の初期化.
	RECT rc = {0, 0, cx, cy};	// rcをcx, cyの大きさで初期化.
	IOleInPlaceObject *pOleInPlaceObject = NULL;	// pOleInPlaceObjectをNULLで初期化.
	
	// サイズ変更.
	if (m_pWebBrowserHost != NULL && m_pWebBrowserHost->m_pWebBrowser != NULL){	// m_pWebBrowserHostがNULLでなく, かつ, m_pWebBrowserHost->m_pWebBrowserがNULLでない場合.
		m_pWebBrowserHost->m_pWebBrowser->QueryInterface(IID_PPV_ARGS(&pOleInPlaceObject));	// QueryInterfaceでpOleInPlaceObjectを取得.
		pOleInPlaceObject->SetObjectRects(&rc, &rc);	// SetObjectRectsでrcをセット.
		pOleInPlaceObject->Release();	// Releaseでリリース.
	}

}