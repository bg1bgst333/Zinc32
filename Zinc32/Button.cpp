// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Button.h"	// CButton

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CButton::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X����"Button"�ȃJ�X�^���R���g���[�����쐬.
	return CCustomControl::Create(_T("Button"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, (HMENU)hMenu, hInstance);	// CCustomControl::Create�Ń{�^���R���g���[�����쐬.

}