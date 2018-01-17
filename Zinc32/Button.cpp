// ヘッダのインクルード
// 独自のヘッダ
#include "Button.h"	// CButton

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CButton::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウクラス名が"Button"なカスタムコントロールを作成.
	return CCustomControl::Create(_T("Button"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, (HMENU)hMenu, hInstance);	// CCustomControl::Createでボタンコントロールを作成.

}