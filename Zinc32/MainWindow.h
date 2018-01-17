// 二重インクルード防止
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string
// 独自のヘッダ
#include "Window.h"	// CWindow

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
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// コマンドが発生した時.

};

#endif