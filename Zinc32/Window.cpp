// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// staticメンバ変数の定義.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// ウィンドウマップm_mapWindowMap.

// コンストラクタCWindow()
CWindow::CWindow(){

	// メンバの初期化.
	m_hWnd = NULL;	// m_hWndをNULLで初期化.

}

// デストラクタ~CWindow()
CWindow::~CWindow(){

	// メンバの終了処理.
	if (m_hWnd != NULL){	// m_hWndがNULLでない時.
		DestroyWindow(m_hWnd);	// DestroyWindowでm_hWndを破棄.
		m_hWnd = NULL;	// m_hWndにNULLをセット.
	}

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance){

	// ウィンドウクラス名は"CWindow".
	return RegisterClass(hInstance, _T("CWindow"));	// ウィンドウクラス名に"CWindow"を指定する.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// ウィンドウプロシージャには"CWindow"のモノを指定する.
	return RegisterClass(hInstance, lpctszClassName, StaticWindowProc);	// ウィンドウプロシージャバージョンにStaticWindowProcを指定.
	
}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウプロシージャ指定バージョン.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, WNDPROC lpfnWndProc){

	// lpfnWndProcを指定.
	return RegisterClass(hInstance, lpctszClassName, lpfnWndProc, NULL);	// ウィンドウプロシージャバージョンにlpfnWndProcを指定.

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウプロシージャ省略, メニュー名指定バージョン.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpszMenuName){

	// StaticWindowProc, lpszMenuNameを指定.
	return RegisterClass(hInstance, lpctszClassName, StaticWindowProc, lpszMenuName);	// メニュー名指定バージョンでStaticWindowProcとlpszMenuNameを指定.

}

// ウィンドウクラス登録関数RegisterClass.(メニュー名指定バージョン.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, WNDPROC lpfnWndProc, LPCTSTR lpszMenuName){

	// 構造体の宣言.
	WNDCLASS wc;	// WNDCLASS型ウィンドウクラス構造体wc

	// ウィンドウクラス構造体wcにパラメータをセット.
	wc.lpszClassName = lpctszClassName;	// ウィンドウクラス名にlpctszClassNameを指定する.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// スタイルはとりあえずCS_HREDRAW | CS_VREDRAWにする.
	wc.lpfnWndProc = lpfnWndProc;	// ウィンドウプロシージャには指定されたlpfnWndProc.
	wc.hInstance = hInstance;	// アプリケーションインスタンスハンドルは引数のhInstanceを使う.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアプリケーション既定のアイコンをロード.(第1引数はNULL.)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでアプリケーション既定のカーソルをロード.(第1引数はNULL.)
	wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);	// GetStockObjectでライトグレーブラシを背景色とする.
	wc.lpszMenuName = lpszMenuName;	// lpszMenuNameを指定する.
	wc.cbClsExtra = 0;	// とりあえず0を指定.
	wc.cbWndExtra = 0;	// とりあえず0を指定.

	// ウィンドウクラスの登録
	if (!::RegisterClass(&wc)){	// WindowsAPIのRegisterClassでウィンドウクラスを登録する.

		// 戻り値が0なら登録失敗なのでエラー処理.
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// 登録成功なのでTRUE.
	return TRUE;	// returnでTRUEを返す.

}

// スタティックウィンドウプロシージャStaticWindowProcの定義
LRESULT CALLBACK CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ポインタの初期化.
	CWindow *pWindow = NULL;	// CWindowオブジェクトポインタpWindowをNULLで初期化.

	// ウィンドウメッセージの処理.
	switch (uMsg){	// uMsgの値ごとに処理を振り分ける.

		
		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ポインタの初期化
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT構造体へのポインタlpCreateStructをNULL.
				// lParamからlpCreateStructを取り出す.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCT型にキャストしてlpCreateStructに格納.
				if (lpCreateStruct != NULL){	// lpCreateStructがNULLでなければ.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParamsはCWindowオブジェクトポインタにキャストし, pWindowに格納.
					m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// m_mapWindowMapにhwndとpWindowのペアを登録.
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて既定の処理へ向かう.

		// それ以外の時.
		default:

			// defaultブロック
			{

				// hwndでCWindowオブジェクトポインタが引けたら, pWindowに格納.
				if (m_mapWindowMap.find(hwnd) != m_mapWindowMap.end()){	// findでキーをhwndとするCWindowオブジェクトポインタが見つかったら.
					pWindow = m_mapWindowMap[hwnd];	// pWindowにhwndで引けるCWindowオブジェクトポインタを格納.
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて既定の処理へ向かう.

	}

	// CWindowオブジェクトポインタが取得できなかった場合, 取得できた場合で分ける.
	if (pWindow == NULL){	// pWindowがNULL

		// DefWindowProcに任せる.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcに引数をそのまま渡して, DefWindowProcの戻り値をそのまま返す.

	}
	else{	// pWindowがNULLでない時.

		// そのCWindowオブジェクトのDynamicWindowProcに渡す.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProcに引数をそのまま渡して, DynamicWindowProcの戻り値をそのまま返す.

	}

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)

	// ウィンドウクラス名は"CWindow".
	return CWindow::Create(_T("CWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CWindow"を指定.

}

// ウィンドウ作成関数Create.
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウの作成.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindowでウィンドウを作成し, ハンドルをm_hWndに格納.(最後の引数にはthis(自分自身)を渡す.)
	if (m_hWnd == NULL){	// m_hWndがNULLなら失敗.

		// 失敗ならFALSEを返す.
		MessageBox(NULL, _T("予期せぬエラーが発生しました!"), _T("Zinc"), MB_OK | MB_ICONHAND);	// MessageBoxで"予期せぬエラーが発生しました!"と表示.
		return FALSE;	// FALSEを返す.

	}

	// 成功ならTRUE.
	return TRUE;	// 成功なのでTRUEを返す.

}

// ウィンドウ表示関数ShowWindow.
BOOL CWindow::ShowWindow(int nCmdShow){

	// ウィンドウの表示.
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPIのShowWindowでm_hWndを表示.

}

// テキストセット関数SetText.
void CWindow::SetText(LPCTSTR lpctszText){

	// テキストのセット.
	SetWindowText(m_hWnd, lpctszText);	// SetWindowTextでlpctszTextのセット.

}

// テキストの長さ取得関数GetTextLength.
int CWindow::GetTextLength(){

	// テキストの長さを取得し, それを返す.
	return GetWindowTextLength(m_hWnd);	// GetWindowTextLengthでテキストの長さを取得し, それをそのまま返す.

}

// テキスト取得関数GetText.
tstring CWindow::GetText(){

	// テキストの長さを返す.
	int iLen = GetTextLength();	// GetTextLengthでテキストの長さを取得し, iLenに格納.

	// バッファの確保.
	TCHAR *ptszBuf = new TCHAR[iLen + 1];	// iLen + 1の長さのTCHAR動的配列を確保.
	ZeroMemory(ptszBuf, (sizeof(TCHAR) * (iLen + 1)));	// ptszBufを0で埋める.

	// テキストの取得.
	GetWindowText(m_hWnd, ptszBuf, iLen + 1);	// GetWindowTextでテキストを取得し, ptszBufに格納.

	// テキストをtstringに移す.
	tstring tstrText = ptszBuf;	// tstrTextをptszBufで初期化.

	// バッファの解放.
	delete [] ptszBuf;	// delete[]でptszBufを解放.

	// テキストを返す.
	return tstrText;	// tstrTextを返す.

}

// ダイナミックウィンドウプロシージャDynamicWindowProc.
LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ウィンドウメッセージの処理.
	switch (uMsg){	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// OnCreateに任せる.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwndとlParamをOnCreateに渡し, あとは任せる.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// OnDestroyに任せる.
				OnDestroy();	// OnDestroyを呼ぶ.
				
			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウのサイズが変更された時.
		case WM_SIZE:

			// WM_SIZEブロック
			{

				// 変数の初期化
				UINT nType = (UINT)wParam;	// UINT型nTypeにwParamをセット.
				int cx = LOWORD(lParam);	// int型cxにLOWORD(lParam)をセット.
				int cy = HIWORD(lParam);	// int型cyにHIWORD(lParam)をセット.

				// OnSizeに任せる.
				OnSize(nType, cx, cy);	// OnSizeにhwnd, nType, cx, cyを渡す.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// コマンドが発生した時.
		case WM_COMMAND:

			// WM_COMMANDブロック
			{

				// OnCommandに任せる.
				return OnCommand(wParam, lParam) ? 0 : 1;

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めてDefWindowProcに既定の処理を任せる.

}

// ウィンドウの作成が開始された時.
int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CWindow::OnDestroy(){

	// 終了メッセージの送信.
	PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.

}

// ウィンドウのサイズが変更された時.
void CWindow::OnSize(UINT nType, int cx, int cy){

}

// コマンドが発生した時.
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam){

	// 処理していないのでFALSE.
	return FALSE;	// returnでFALSEを返す.

}