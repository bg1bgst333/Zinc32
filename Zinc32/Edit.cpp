// ヘッダのインクルード
// 独自のヘッダ
#include "Edit.h"	// CEdit

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CEdit::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)

	// ウィンドウクラス名が"Edit"なカスタムコントロールを作成.
	return CCustomControl::Create(_T("Edit"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, (HMENU)hMenu, hInstance);	// CCustomControl::Createでエディットコントロールを作成.

}