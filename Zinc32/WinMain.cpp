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

// いったんコメントアウト
#if 0
// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI
// 独自のヘッダ
#include "WebBrowserHost.h"	// CWebBrowserHost

// グローバルオブジェクトの定義.
CWebBrowserHost *g_pWebBrowserHost = NULL;	// ウェブブラウザホストオブジェクトのポインタg_pWebBrowserHostをNULLで初期化.

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャWindowProc

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・構造体の宣言
	HWND hWnd;		// HWND型ウィンドウハンドルhWnd
	MSG msg;		// MSG型メッセージ構造体msg
	WNDCLASS wc;	// WNDCLASS型ウィンドウクラス構造体wc
	WNDCLASS wcBrowser;	// WNDCLASS型ウィンドウクラス構造体wcBrowser

	// OLEの初期化.
	OleInitialize(NULL);	// OleInitializeでOLEの初期化.

	// ウィンドウクラス構造体wcにパラメータをセット.
	wc.lpszClassName = _T("Zinc");	// ウィンドウクラス名はとりあえず"Zinc"とする.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// スタイルはとりあえずCS_HREDRAW | CS_VREDRAWにする.
	wc.lpfnWndProc = WindowProc;	// ウィンドウプロシージャには下で定義するWindowProcを指定する.
	wc.hInstance = hInstance;	// アプリケーションインスタンスハンドルは引数のhInstanceを使う.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアプリケーション既定のアイコンをロード.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでアプリケーション既定のカーソルをロード.
	wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);	// GetStockObjectでライトグレーブラシを背景色とする.
	wc.lpszMenuName = NULL;	// とりあえずメニューはなし.(NULLにする.)
	wc.cbClsExtra = 0;	// とりあえず0を指定.
	wc.cbWndExtra = 0;	// とりあえず0を指定.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録する.

		// 戻り値が0なら登録失敗なのでエラー処理.
		MessageBox(NULL, _T("予期せぬエラーが発生しました!(-1)"), _T("Zinc"), MB_OK | MB_ICONHAND);	// MessageBoxで"予期せぬエラーが発生しました!(-1)"と表示.
		OleUninitialize();	// OleInitializeでOLEの終了処理.
		return -1;	// returnで-1を返して異常終了.

	}

	// ウィンドウクラス構造体wcBrowserにパラメータをセット.
	wcBrowser.lpszClassName = _T("Browser");	// ウィンドウクラス名はとりあえず"Browser"とする.
	wcBrowser.style = 0;	// スタイルはとりあえず0にする.
	wcBrowser.lpfnWndProc = WindowProc;	// ウィンドウプロシージャには下で定義するWindowProcを指定する.
	wcBrowser.hInstance = hInstance;	// アプリケーションインスタンスハンドルは引数のhInstanceを使う.
	wcBrowser.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアプリケーション既定のアイコンをロード.
	wcBrowser.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでアプリケーション既定のカーソルをロード.
	wcBrowser.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObjectで白ブラシを背景色とする.
	wcBrowser.lpszMenuName = NULL;	// メニューはなし.(NULLにする.)
	wcBrowser.cbClsExtra = 0;	// とりあえず0を指定.
	wcBrowser.cbWndExtra = 0;	// とりあえず0を指定.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wcBrowser)){	// RegisterClassでウィンドウクラスを登録する.

		// 戻り値が0なら登録失敗なのでエラー処理.
		MessageBox(NULL, _T("予期せぬエラーが発生しました!(-2)"), _T("Zinc"), MB_OK | MB_ICONHAND);	// MessageBoxで"予期せぬエラーが発生しました!(-2)"と表示.
		OleUninitialize();	// OleInitializeでOLEの終了処理.
		return -2;	// returnで-2を返して異常終了.

	}

	// ウィンドウの作成
	hWnd = CreateWindow(wc.lpszClassName, _T("Zinc"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウクラス名が"Zinc"なウィンドウ"Zinc"を作成.
	if (hWnd == NULL){	// hWndがNULLならウィンドウ作成失敗.

		// エラー処理
		MessageBox(NULL, _T("予期せぬエラーが発生しました!(-3)"), _T("Zinc"), MB_OK | MB_ICONHAND);	// MessageBoxで"予期せぬエラーが発生しました!(-3)"と表示.
		OleUninitialize();	// OleInitializeでOLEの終了処理.
		return -3;	// returnで-3を返して異常終了.

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでウィンドウを表示.

	// メッセージループの処理
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでウィンドウメッセージを取得し, msgに格納.(0以下なら, ここを抜ける.)

		// メッセージの変換と送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageでメッセージをウィンドウプロシージャWindowProcに送出.

	}

	// g_pWebBrowserHostの解放.
	delete g_pWebBrowserHost;	// deleteでg_pWebBrowserHostを解放.
	g_pWebBrowserHost = NULL;	// g_pWebBrowserHostにNULLをセット.

	// OLEの終了処理.
	OleUninitialize();	// OleInitializeでOLEの終了処理.

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// ウィンドウプロシージャWindowProcの定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// スタティック変数の初期化.
	static HWND hEdit = NULL;	// エディットコントロールのウィンドウハンドルhEditをNULLで初期化.
	static HWND hButton = NULL;	// ボタンコントロールのウィンドウハンドルhButtonをNULLで初期化.
	static HWND hBrowser = NULL;	// ウェブブラウザコントロールのウィンドウハンドルhBrowserをNULLで初期化.

	// ウィンドウメッセージの処理.
	switch (uMsg){	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// 変数の宣言
				LPCREATESTRUCT lpCS;	// CreateStruct構造体ポインタlpCS.

				// lpCSの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, lpCSに格納.

				// CWebBrowserHostオブジェクトが生成される前.
				if (g_pWebBrowserHost == NULL){

					// エディットコントロールの作成
					hEdit = CreateWindow(_T("Edit"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_WANTRETURN, 0, 0, 640, 24, hwnd, (HMENU)(WM_APP + 1), lpCS->hInstance, NULL);	// CreateWindowでエディットコントロールhEditを作成.(ウィンドウクラス名は"Edit".)

					// ボタンコントロールの作成
					hButton = CreateWindow(_T("Button"), _T("ロード"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 640, 0, 80, 24, hwnd, (HMENU)(WM_APP + 2), lpCS->hInstance, NULL);	// CreateWindowでボタンコントロールhButtonを作成.(ウィンドウクラス名は"Button".)

					// CWebBrowserHostオブジェクトの生成.
					g_pWebBrowserHost = new CWebBrowserHost();	// CWebBrowserHostの生成.

					// ウェブブラウザコントロールの作成
					hBrowser = CreateWindow(_T("Browser"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 30, 640, 510, hwnd, (HMENU)(WM_APP + 3), lpCS->hInstance, NULL);	// CreateWindowでウェブブラウザコントロールとなるウィンドウhBrowserを作成.(ウィンドウクラス名は"Browser".)
					
				}
				if (g_pWebBrowserHost != NULL && hBrowser != NULL){	// g_pWebBrowserHostがNULLでなく, hBrowserもNULLでない時.

					// g_pWebBrowserHostとhBrowserを紐付ける.
					g_pWebBrowserHost->Attach(hBrowser);	// g_pWebBrowserHost->AttachにhBrowserをセット.

				}

				// 常にウィンドウ作成に成功するものとする.
				return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// hwndが親ウィンドウの場合.
				if (hwnd != hEdit && hwnd != hButton && hwnd != hBrowser && g_pWebBrowserHost != NULL){	// hEditでもhButtonでもhBrowserでもなく, g_pWebBrowserHostがNULLでない時.

					// 終了メッセージの送信.
					PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.

				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウサイズが変更された時.
		case WM_SIZE:

			// WM_SIZEブロック
			{

				// 外側のウィンドウの場合.
				if (hwnd != hEdit && hwnd != hButton && hwnd != hBrowser && g_pWebBrowserHost != NULL){	// hEditでもhButtonでもhBrowserでもなく, g_pWebBrowserHostがNULLでない時.

					// 変数の初期化.
					int iWidth = 0;	// クライアント領域幅iWidth.
					int iHeight = 0;	// クライアント領域高さiHeight.

					// クライアント領域の変更後のサイズを取得.
					iWidth = LOWORD(lParam);	// LOWORD(lParam)でクライアント領域の幅を取得し, iWidthに格納.
					iHeight = HIWORD(lParam);	// HIWORD(lParam)でクライアント領域の高さを取得し, iHeightに格納.

					// ウィンドウのサイズ変更.
					MoveWindow(hEdit, 0, 0, iWidth - 80, 24, TRUE);	// MoveWindowでhEditのサイズを変更.
					MoveWindow(hButton, iWidth - 80, 0, 80, 24, TRUE);	// MoveWindowでhButtonのサイズを変更.
					MoveWindow(hBrowser, 0, 30, iWidth, iHeight - 30, TRUE);	// MoveWindowでhBrowserのサイズを変更.

				}
				if (hwnd == hBrowser){	// hBrowserの時.

					// 変数の初期化.
					RECT rc = {0, 0, LOWORD(lParam), HIWORD(lParam)};	// rcをlParamの大きさで初期化.
					IOleInPlaceObject *pOleInPlaceObject = NULL;	// pOleInPlaceObjectをNULLで初期化.
					
					// サイズ変更.
					g_pWebBrowserHost->m_pWebBrowser->QueryInterface(IID_PPV_ARGS(&pOleInPlaceObject));	// QueryInterfaceでpOleInPlaceObjectを取得.
					pOleInPlaceObject->SetObjectRects(&rc, &rc);	// SetObjectRectsでrcをセット.
					pOleInPlaceObject->Release();	// Releaseでリリース.

				}

				// 既定の処理へ向かう.
				break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

			}

		// コマンドが発生した時.
		case WM_COMMAND:

			// WM_COMMANDブロック
			{

				// コマンドの処理.
				switch (LOWORD(wParam)){	// LOWORD(wParam)でリソースIDがわかるので, その値ごとに処理を振り分ける.

					// "ロード"ボタン
					case WM_APP + 2:

						// WM_APP + 2ブロック
						{

							// 入力されたURLを表示.
							TCHAR tszUrl[4096] = {0};	// tszUrlを{0}で初期化.
							GetWindowText(hEdit, tszUrl, 4096);	// GetWindowTextでhEditにセットされたテキストを取得し, tszUrlに格納.
							g_pWebBrowserHost->Navigate(tszUrl);	// g_pWebBrowserHost->NavigateでtszUrlをロード.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// それ以外.
					default:

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

				}

			}

		// 上記以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めてDefWindowProcに既定の処理を任せる.

}
#endif