// 二重インクルード防止
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string
// 独自のヘッダ
#include "Window.h"	// CWindow
#include "Edit.h"	// CEdit
#include "Button.h"	// CButton
#include "WebBrowser.h"	// CWebBrowser

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// メインウィンドウクラスCMainWindow
class CMainWindow : public CWindow{

	// publicメンバ
	public:

		// publicメンバ変数
		CEdit *m_pEdit;	// CEditオブジェクトポインタm_pEdit.
		CButton *m_pButton;	// CButtonオブジェクトポインタm_pButton.
		CWebBrowser *m_pWebBrowser;	// CWebBrowserオブジェクトポインタm_pWebBrowser.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMainWindow();	// コンストラクタCMainWindow()
		virtual ~CMainWindow();	// デストラクタ~CMainWindow()
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時.
		virtual int OnLoad(WPARAM wParam, LPARAM lParam);	// "ロード"ボタンが押された時のハンドラ.

};

#endif