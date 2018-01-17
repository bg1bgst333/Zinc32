// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �I�u�W�F�N�g�̐錾.
	CMainApplication app;	// CMainApplication�I�u�W�F�N�gapp.

	// �C���X�^���X�̏�����.
	if (!app.InitInstance(hInstance, lpCmdLine, nShowCmd)){	// app.InitInstance��FALSE�̏ꍇ.

		// �ُ�I��.
		app.ExitInstance();	// app.ExitInstance�ŏI�����������s.
		return -1;	// return��-1��Ԃ��Ĉُ�I��.

	}

	// ���b�Z�[�W���[�v.
	int iRet = app.Run();	// app.Run�Ń��b�Z�[�W���[�v�ɓ���, �߂�l��iRet�Ɋi�[.

	// ����I��.
	return iRet;	// iRet��Ԃ�.

}

// ��������R�����g�A�E�g
#if 0
// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
// �Ǝ��̃w�b�_
#include "WebBrowserHost.h"	// CWebBrowserHost

// �O���[�o���I�u�W�F�N�g�̒�`.
CWebBrowserHost *g_pWebBrowserHost = NULL;	// �E�F�u�u���E�U�z�X�g�I�u�W�F�N�g�̃|�C���^g_pWebBrowserHost��NULL�ŏ�����.

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��WindowProc

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�\���̂̐錾
	HWND hWnd;		// HWND�^�E�B���h�E�n���h��hWnd
	MSG msg;		// MSG�^���b�Z�[�W�\����msg
	WNDCLASS wc;	// WNDCLASS�^�E�B���h�E�N���X�\����wc
	WNDCLASS wcBrowser;	// WNDCLASS�^�E�B���h�E�N���X�\����wcBrowser

	// OLE�̏�����.
	OleInitialize(NULL);	// OleInitialize��OLE�̏�����.

	// �E�B���h�E�N���X�\����wc�Ƀp�����[�^���Z�b�g.
	wc.lpszClassName = _T("Zinc");	// �E�B���h�E�N���X���͂Ƃ肠����"Zinc"�Ƃ���.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// �X�^�C���͂Ƃ肠����CS_HREDRAW | CS_VREDRAW�ɂ���.
	wc.lpfnWndProc = WindowProc;	// �E�B���h�E�v���V�[�W���ɂ͉��Œ�`����WindowProc���w�肷��.
	wc.hInstance = hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h���͈�����hInstance���g��.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIcon�ŃA�v���P�[�V��������̃A�C�R�������[�h.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursor�ŃA�v���P�[�V��������̃J�[�\�������[�h.
	wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);	// GetStockObject�Ń��C�g�O���[�u���V��w�i�F�Ƃ���.
	wc.lpszMenuName = NULL;	// �Ƃ肠�������j���[�͂Ȃ�.(NULL�ɂ���.)
	wc.cbClsExtra = 0;	// �Ƃ肠����0���w��.
	wc.cbWndExtra = 0;	// �Ƃ肠����0���w��.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)){	// RegisterClass�ŃE�B���h�E�N���X��o�^����.

		// �߂�l��0�Ȃ�o�^���s�Ȃ̂ŃG���[����.
		MessageBox(NULL, _T("�\�����ʃG���[���������܂���!(-1)"), _T("Zinc"), MB_OK | MB_ICONHAND);	// MessageBox��"�\�����ʃG���[���������܂���!(-1)"�ƕ\��.
		OleUninitialize();	// OleInitialize��OLE�̏I������.
		return -1;	// return��-1��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�N���X�\����wcBrowser�Ƀp�����[�^���Z�b�g.
	wcBrowser.lpszClassName = _T("Browser");	// �E�B���h�E�N���X���͂Ƃ肠����"Browser"�Ƃ���.
	wcBrowser.style = 0;	// �X�^�C���͂Ƃ肠����0�ɂ���.
	wcBrowser.lpfnWndProc = WindowProc;	// �E�B���h�E�v���V�[�W���ɂ͉��Œ�`����WindowProc���w�肷��.
	wcBrowser.hInstance = hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h���͈�����hInstance���g��.
	wcBrowser.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIcon�ŃA�v���P�[�V��������̃A�C�R�������[�h.
	wcBrowser.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursor�ŃA�v���P�[�V��������̃J�[�\�������[�h.
	wcBrowser.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObject�Ŕ��u���V��w�i�F�Ƃ���.
	wcBrowser.lpszMenuName = NULL;	// ���j���[�͂Ȃ�.(NULL�ɂ���.)
	wcBrowser.cbClsExtra = 0;	// �Ƃ肠����0���w��.
	wcBrowser.cbWndExtra = 0;	// �Ƃ肠����0���w��.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wcBrowser)){	// RegisterClass�ŃE�B���h�E�N���X��o�^����.

		// �߂�l��0�Ȃ�o�^���s�Ȃ̂ŃG���[����.
		MessageBox(NULL, _T("�\�����ʃG���[���������܂���!(-2)"), _T("Zinc"), MB_OK | MB_ICONHAND);	// MessageBox��"�\�����ʃG���[���������܂���!(-2)"�ƕ\��.
		OleUninitialize();	// OleInitialize��OLE�̏I������.
		return -2;	// return��-2��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(wc.lpszClassName, _T("Zinc"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�N���X����"Zinc"�ȃE�B���h�E"Zinc"���쐬.
	if (hWnd == NULL){	// hWnd��NULL�Ȃ�E�B���h�E�쐬���s.

		// �G���[����
		MessageBox(NULL, _T("�\�����ʃG���[���������܂���!(-3)"), _T("Zinc"), MB_OK | MB_ICONHAND);	// MessageBox��"�\�����ʃG���[���������܂���!(-3)"�ƕ\��.
		OleUninitialize();	// OleInitialize��OLE�̏I������.
		return -3;	// return��-3��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow�ŃE�B���h�E��\��.

	// ���b�Z�[�W���[�v�̏���
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage�ŃE�B���h�E���b�Z�[�W���擾��, msg�Ɋi�[.(0�ȉ��Ȃ�, �����𔲂���.)

		// ���b�Z�[�W�̕ϊ��Ƒ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ń��b�Z�[�W���E�B���h�E�v���V�[�W��WindowProc�ɑ��o.

	}

	// g_pWebBrowserHost�̉��.
	delete g_pWebBrowserHost;	// delete��g_pWebBrowserHost�����.
	g_pWebBrowserHost = NULL;	// g_pWebBrowserHost��NULL���Z�b�g.

	// OLE�̏I������.
	OleUninitialize();	// OleInitialize��OLE�̏I������.

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

}

// �E�B���h�E�v���V�[�W��WindowProc�̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �X�^�e�B�b�N�ϐ��̏�����.
	static HWND hEdit = NULL;	// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit��NULL�ŏ�����.
	static HWND hButton = NULL;	// �{�^���R���g���[���̃E�B���h�E�n���h��hButton��NULL�ŏ�����.
	static HWND hBrowser = NULL;	// �E�F�u�u���E�U�R���g���[���̃E�B���h�E�n���h��hBrowser��NULL�ŏ�����.

	// �E�B���h�E���b�Z�[�W�̏���.
	switch (uMsg){	// uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �ϐ��̐錾
				LPCREATESTRUCT lpCS;	// CreateStruct�\���̃|�C���^lpCS.

				// lpCS�̎擾.
				lpCS = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�ɃL���X�g����, lpCS�Ɋi�[.

				// CWebBrowserHost�I�u�W�F�N�g�����������O.
				if (g_pWebBrowserHost == NULL){

					// �G�f�B�b�g�R���g���[���̍쐬
					hEdit = CreateWindow(_T("Edit"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_WANTRETURN, 0, 0, 640, 24, hwnd, (HMENU)(WM_APP + 1), lpCS->hInstance, NULL);	// CreateWindow�ŃG�f�B�b�g�R���g���[��hEdit���쐬.(�E�B���h�E�N���X����"Edit".)

					// �{�^���R���g���[���̍쐬
					hButton = CreateWindow(_T("Button"), _T("���[�h"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 640, 0, 80, 24, hwnd, (HMENU)(WM_APP + 2), lpCS->hInstance, NULL);	// CreateWindow�Ń{�^���R���g���[��hButton���쐬.(�E�B���h�E�N���X����"Button".)

					// CWebBrowserHost�I�u�W�F�N�g�̐���.
					g_pWebBrowserHost = new CWebBrowserHost();	// CWebBrowserHost�̐���.

					// �E�F�u�u���E�U�R���g���[���̍쐬
					hBrowser = CreateWindow(_T("Browser"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 30, 640, 510, hwnd, (HMENU)(WM_APP + 3), lpCS->hInstance, NULL);	// CreateWindow�ŃE�F�u�u���E�U�R���g���[���ƂȂ�E�B���h�EhBrowser���쐬.(�E�B���h�E�N���X����"Browser".)
					
				}
				if (g_pWebBrowserHost != NULL && hBrowser != NULL){	// g_pWebBrowserHost��NULL�łȂ�, hBrowser��NULL�łȂ���.

					// g_pWebBrowserHost��hBrowser��R�t����.
					g_pWebBrowserHost->Attach(hBrowser);	// g_pWebBrowserHost->Attach��hBrowser���Z�b�g.

				}

				// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
				return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// hwnd���e�E�B���h�E�̏ꍇ.
				if (hwnd != hEdit && hwnd != hButton && hwnd != hBrowser && g_pWebBrowserHost != NULL){	// hEdit�ł�hButton�ł�hBrowser�ł��Ȃ�, g_pWebBrowserHost��NULL�łȂ���.

					// �I�����b�Z�[�W�̑��M.
					PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.

				}

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E�T�C�Y���ύX���ꂽ��.
		case WM_SIZE:

			// WM_SIZE�u���b�N
			{

				// �O���̃E�B���h�E�̏ꍇ.
				if (hwnd != hEdit && hwnd != hButton && hwnd != hBrowser && g_pWebBrowserHost != NULL){	// hEdit�ł�hButton�ł�hBrowser�ł��Ȃ�, g_pWebBrowserHost��NULL�łȂ���.

					// �ϐ��̏�����.
					int iWidth = 0;	// �N���C�A���g�̈敝iWidth.
					int iHeight = 0;	// �N���C�A���g�̈捂��iHeight.

					// �N���C�A���g�̈�̕ύX��̃T�C�Y���擾.
					iWidth = LOWORD(lParam);	// LOWORD(lParam)�ŃN���C�A���g�̈�̕����擾��, iWidth�Ɋi�[.
					iHeight = HIWORD(lParam);	// HIWORD(lParam)�ŃN���C�A���g�̈�̍������擾��, iHeight�Ɋi�[.

					// �E�B���h�E�̃T�C�Y�ύX.
					MoveWindow(hEdit, 0, 0, iWidth - 80, 24, TRUE);	// MoveWindow��hEdit�̃T�C�Y��ύX.
					MoveWindow(hButton, iWidth - 80, 0, 80, 24, TRUE);	// MoveWindow��hButton�̃T�C�Y��ύX.
					MoveWindow(hBrowser, 0, 30, iWidth, iHeight - 30, TRUE);	// MoveWindow��hBrowser�̃T�C�Y��ύX.

				}
				if (hwnd == hBrowser){	// hBrowser�̎�.

					// �ϐ��̏�����.
					RECT rc = {0, 0, LOWORD(lParam), HIWORD(lParam)};	// rc��lParam�̑傫���ŏ�����.
					IOleInPlaceObject *pOleInPlaceObject = NULL;	// pOleInPlaceObject��NULL�ŏ�����.
					
					// �T�C�Y�ύX.
					g_pWebBrowserHost->m_pWebBrowser->QueryInterface(IID_PPV_ARGS(&pOleInPlaceObject));	// QueryInterface��pOleInPlaceObject���擾.
					pOleInPlaceObject->SetObjectRects(&rc, &rc);	// SetObjectRects��rc���Z�b�g.
					pOleInPlaceObject->Release();	// Release�Ń����[�X.

				}

				// ����̏����֌�����.
				break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

			}

		// �R�}���h������������.
		case WM_COMMAND:

			// WM_COMMAND�u���b�N
			{

				// �R�}���h�̏���.
				switch (LOWORD(wParam)){	// LOWORD(wParam)�Ń��\�[�XID���킩��̂�, ���̒l���Ƃɏ�����U�蕪����.

					// "���[�h"�{�^��
					case WM_APP + 2:

						// WM_APP + 2�u���b�N
						{

							// ���͂��ꂽURL��\��.
							TCHAR tszUrl[4096] = {0};	// tszUrl��{0}�ŏ�����.
							GetWindowText(hEdit, tszUrl, 4096);	// GetWindowText��hEdit�ɃZ�b�g���ꂽ�e�L�X�g���擾��, tszUrl�Ɋi�[.
							g_pWebBrowserHost->Navigate(tszUrl);	// g_pWebBrowserHost->Navigate��tszUrl�����[�h.

						}

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

					// ����ȊO.
					default:

						// ����̏����֌�����.
						break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

				}

			}

		// ��L�ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂߂�DefWindowProc�Ɋ���̏�����C����.

}
#endif