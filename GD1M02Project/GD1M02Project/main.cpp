//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//


#define WIN32_LEAN_AND_MEAN

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.

#include "utils.h"
#include "resource.h"
#include "CMatrix4.h"

#define WINDOW_CLASS_NAME L"WINCLASS1"

HMENU g_hMenu;
HWND g_hDlgMatrix, g_hDlgTransformation, g_hDlgGaussian, g_hDlgQuaternion, g_hDlgSLERP;

CMatrix4* Matrix_A = new CMatrix4;
CMatrix4* Matrix_B = new CMatrix4;
CMatrix4* Matrix_R = new CMatrix4;

void GameLoop()
{
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)

{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.

					// What is the message?
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.

		// Return Success.
		return (0);
	}
	break;

	case WM_PAINT:
	{
		// Simply validate the window.
		hdc = BeginPaint(_hwnd, &ps);

		// You would do all your painting here...

		EndPaint(_hwnd, &ps);

		// Return Success.
		return (0);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case ID_EXIT:
		{
			PostQuitMessage(0);
			break;
		}
		case ID_CALCULATOR_MATRIX:
		{
			ShowWindow(g_hDlgMatrix, SW_SHOWNORMAL);
			break;
		}
		case ID_CALCULATOR_TRANSFORMATION:
		{
			ShowWindow(g_hDlgTransformation, SW_SHOWNORMAL);
			break;

		}
		//open the matrix dialog
		case ID_CALCULATOR_GAUSSIAN:
		{
			ShowWindow(g_hDlgGaussian, SW_SHOWNORMAL);
			break;
		}
		//open the gaussian dialog
		case ID_CALCULATOR_QUATERNION:
		{
			ShowWindow(g_hDlgQuaternion, SW_SHOWNORMAL);
			break;
		}
		//open the quaternion dialog
		case ID_CALCULATOR_SLERP:
		{
			ShowWindow(g_hDlgSLERP, SW_SHOWNORMAL);
			break;
		}
		default:
			break;
		}
		return(0);
	}
	break;

	case WM_DESTROY:
	{
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return (0);
	}
	break;

	default:break;
	} // End switch.

	  // Process any messages that we did not take care of...

	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}

BOOL CALLBACK MatrixDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)

{
	static float _value;
	
	
	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case IDC_EDIT_A11:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
			Matrix_A->SetElement(0, 0, _value);
			break;
		}

		case IDC_EDIT_A12:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
			Matrix_A->SetElement(0, 1, _value);
			break;
		}

		case IDC_EDIT_A13:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
			Matrix_A->SetElement(0, 2, _value);
			break;
		}

		case IDC_EDIT_A14:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A14);
			Matrix_A->SetElement(0, 3, _value);
			break;
		}

		case IDC_EDIT_A21:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
			Matrix_A->SetElement(1, 0, _value);
			break;
		}

		case IDC_EDIT_A22:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
			Matrix_A->SetElement(1, 1, _value);
			break;
		}

		case IDC_EDIT_A23:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
			Matrix_A->SetElement(1, 2, _value);
			break;
		}

		case IDC_EDIT_A24:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A24);
			Matrix_A->SetElement(1, 3, _value);
			break;
		}

		case IDC_EDIT_A31:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			Matrix_A->SetElement(2, 0, _value);
			break;
		}

		case IDC_EDIT_A32:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
			Matrix_A->SetElement(2, 1, _value);
			break;
		}

		case IDC_EDIT_A33:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
			Matrix_A->SetElement(2, 2, _value);
			break;
		}

		case IDC_EDIT_A34:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A34);
			Matrix_A->SetElement(2, 3, _value);
			break;
		}

		case IDC_EDIT_A41:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
			Matrix_A->SetElement(3, 0, _value);
			break;
		}

		case IDC_EDIT_A42:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
			Matrix_A->SetElement(3, 1, _value);
			break;
		}

		case IDC_EDIT_A43:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
			Matrix_A->SetElement(3, 2, _value);
			break;
		}

		case IDC_EDIT_A44:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_A44);
			Matrix_A->SetElement(3, 3, _value);
			break;
		}

		case IDC_EDIT_B11:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
			Matrix_B->SetElement(0, 0, _value);
			break;
		}

		case IDC_EDIT_B12:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
			Matrix_B->SetElement(0, 1, _value);
			break;
		}

		case IDC_EDIT_B13:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
			Matrix_B->SetElement(0, 2, _value);
			break;
		}

		case IDC_EDIT_B14:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B14);
			Matrix_B->SetElement(0, 3, _value);
			break;
		}

		case IDC_EDIT_B21:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
			Matrix_B->SetElement(1, 0, _value);
			break;
		}

		case IDC_EDIT_B22:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
			Matrix_B->SetElement(1, 1, _value);
			break;
		}

		case IDC_EDIT_B23:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
			Matrix_B->SetElement(1, 2, _value);
			break;
		}

		case IDC_EDIT_B24:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B24);
			Matrix_B->SetElement(1, 3, _value);
			break;
		}

		case IDC_EDIT_B31:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
			Matrix_B->SetElement(2, 0, _value);
			break;
		}

		case IDC_EDIT_B32:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B32);
			Matrix_B->SetElement(2, 1, _value);
			break;
		}

		case IDC_EDIT_B33:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
			Matrix_B->SetElement(2, 2, _value);
			break;
		}

		case IDC_EDIT_B34:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B34);
			Matrix_B->SetElement(2, 3, _value);
			break;
		}

		case IDC_EDIT_B41:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
			Matrix_B->SetElement(3, 0, _value);
			break;
		}

		case IDC_EDIT_B42:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
			Matrix_B->SetElement(3, 1, _value);
			break;
		}

		case IDC_EDIT_B43:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
			Matrix_B->SetElement(3, 2, _value);
			break;
		}

		case IDC_EDIT_B44:
		{
			_value = ReadFromEditBox(_hwnd, IDC_EDIT_B44);
			Matrix_B->SetElement(3, 3, _value);
			break;
		}

		case IDOK4:
		{
			//Perform Identity function on Matrix A
			(*Matrix_A).Identity(*Matrix_A);
			
			// Write Results to Matrix A boxes

			//First Row
			WriteToEditBox(_hwnd, IDC_EDIT_A11, Matrix_A->GetElement(0, 0));
			WriteToEditBox(_hwnd, IDC_EDIT_A12, Matrix_A->GetElement(0, 1));
			WriteToEditBox(_hwnd, IDC_EDIT_A13, Matrix_A->GetElement(0, 2));
			WriteToEditBox(_hwnd, IDC_EDIT_A14, Matrix_A->GetElement(0, 3));

			//Second Row
			WriteToEditBox(_hwnd, IDC_EDIT_A21, Matrix_A->GetElement(1, 0));
			WriteToEditBox(_hwnd, IDC_EDIT_A22, Matrix_A->GetElement(1, 1));
			WriteToEditBox(_hwnd, IDC_EDIT_A23, Matrix_A->GetElement(1, 2));
			WriteToEditBox(_hwnd, IDC_EDIT_A24, Matrix_A->GetElement(1, 3));

			//Third Row
			WriteToEditBox(_hwnd, IDC_EDIT_A31, Matrix_A->GetElement(2, 0));
			WriteToEditBox(_hwnd, IDC_EDIT_A32, Matrix_A->GetElement(2, 1));
			WriteToEditBox(_hwnd, IDC_EDIT_A33, Matrix_A->GetElement(2, 2));
			WriteToEditBox(_hwnd, IDC_EDIT_A34, Matrix_A->GetElement(2, 3));

			//Fourth Row
			WriteToEditBox(_hwnd, IDC_EDIT_A41, Matrix_A->GetElement(3, 0));
			WriteToEditBox(_hwnd, IDC_EDIT_A42, Matrix_A->GetElement(3, 1));
			WriteToEditBox(_hwnd, IDC_EDIT_A43, Matrix_A->GetElement(3, 2));
			WriteToEditBox(_hwnd, IDC_EDIT_A44, Matrix_A->GetElement(3, 3));
		}
		break;

		case IDOK8:
		{
			//Perform Identity function on Matrix B
			(*Matrix_B).Identity(*Matrix_B);

			// Write Results to Matrix A boxes

			//First Row
			WriteToEditBox(_hwnd, IDC_EDIT_B11, Matrix_B->GetElement(0, 0));
			WriteToEditBox(_hwnd, IDC_EDIT_B12, Matrix_B->GetElement(0, 1));
			WriteToEditBox(_hwnd, IDC_EDIT_B13, Matrix_B->GetElement(0, 2));
			WriteToEditBox(_hwnd, IDC_EDIT_B14, Matrix_B->GetElement(0, 3));

			//Second Row
			WriteToEditBox(_hwnd, IDC_EDIT_B21, Matrix_B->GetElement(1, 0));
			WriteToEditBox(_hwnd, IDC_EDIT_B22, Matrix_B->GetElement(1, 1));
			WriteToEditBox(_hwnd, IDC_EDIT_B23, Matrix_B->GetElement(1, 2));
			WriteToEditBox(_hwnd, IDC_EDIT_B24, Matrix_B->GetElement(1, 3));

			//Third Row
			WriteToEditBox(_hwnd, IDC_EDIT_B31, Matrix_B->GetElement(2, 0));
			WriteToEditBox(_hwnd, IDC_EDIT_B32, Matrix_B->GetElement(2, 1));
			WriteToEditBox(_hwnd, IDC_EDIT_B33, Matrix_B->GetElement(2, 2));
			WriteToEditBox(_hwnd, IDC_EDIT_B34, Matrix_B->GetElement(2, 3));

			//Fourth Row
			WriteToEditBox(_hwnd, IDC_EDIT_B41, Matrix_B->GetElement(3, 0));
			WriteToEditBox(_hwnd, IDC_EDIT_B42, Matrix_B->GetElement(3, 1));
			WriteToEditBox(_hwnd, IDC_EDIT_B43, Matrix_B->GetElement(3, 2));
			WriteToEditBox(_hwnd, IDC_EDIT_B44, Matrix_B->GetElement(3, 3));

		}
		break;

		case IDOK:
		{
			//Perform addition of Matrix's A and B
			Matrix_A->Add(*Matrix_A, *Matrix_B, *Matrix_R);

			//Write result to Resultant Matrix
			//First Row
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R11, Matrix_R->GetElement(0, 0));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R12, Matrix_R->GetElement(0, 1));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R13, Matrix_R->GetElement(0, 2));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R14, Matrix_R->GetElement(0, 3));
									   			   
			//Second Row			   			   
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R21, Matrix_R->GetElement(1, 0));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R22, Matrix_R->GetElement(1, 1));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R23, Matrix_R->GetElement(1, 2));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R24, Matrix_R->GetElement(1, 3));
									   			   
			//Third Row				   			   
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R31, Matrix_R->GetElement(2, 0));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R32, Matrix_R->GetElement(2, 1));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R33, Matrix_R->GetElement(2, 2));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R34, Matrix_R->GetElement(2, 3));
									   			   
			//Fourth Row			   			   
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R41, Matrix_R->GetElement(3, 0));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R42, Matrix_R->GetElement(3, 1));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R43, Matrix_R->GetElement(3, 2));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R44, Matrix_R->GetElement(3, 3));
		}
		break; 

		case IDCANCEL:
		{
			//Perform subtraction of Matrix's A and B
			Matrix_A->Subtract(*Matrix_A, *Matrix_B, *Matrix_R);

			//Write result to Resultant Matrix
			//First Row
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R11, Matrix_R->GetElement(0, 0));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R12, Matrix_R->GetElement(0, 1));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R13, Matrix_R->GetElement(0, 2));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R14, Matrix_R->GetElement(0, 3));

			//Second Row			   			   
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R21, Matrix_R->GetElement(1, 0));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R22, Matrix_R->GetElement(1, 1));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R23, Matrix_R->GetElement(1, 2));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R24, Matrix_R->GetElement(1, 3));

			//Third Row				   			   
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R31, Matrix_R->GetElement(2, 0));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R32, Matrix_R->GetElement(2, 1));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R33, Matrix_R->GetElement(2, 2));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R34, Matrix_R->GetElement(2, 3));

			//Fourth Row			   			   
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R41, Matrix_R->GetElement(3, 0));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R42, Matrix_R->GetElement(3, 1));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R43, Matrix_R->GetElement(3, 2));
			WriteToEditBox(g_hDlgMatrix, IDC_EDIT_R44, Matrix_R->GetElement(3, 3));
		}
		break;


		default:
			break;
		}
		return TRUE;
		break;
	}
	case WM_CLOSE:
	{
		MessageBox(_hwnd, ToWideString(_value).c_str(), L"Value in A11", MB_OK);
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK TransformationDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}


BOOL CALLBACK GaussianDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}


BOOL CALLBACK QuaternionDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK SLERPDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG msg;             // Generic message.

						 // First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground =
		static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	//Laod the Menu
	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));

	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"Your Basic Window",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0,                    // Initial x,y.
		400, 100,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}

	//Create the modeless dialog boxes for the calculators
	//Matrix Calculator
	g_hDlgMatrix = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogMatrix), hwnd, (DLGPROC)MatrixDlgProc);
	g_hDlgTransformation = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogTransformations), hwnd, (DLGPROC)TransformationDlgProc);
	g_hDlgGaussian = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogGaussian), hwnd, (DLGPROC)GaussianDlgProc);
	g_hDlgQuaternion = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogQuaternion), hwnd, (DLGPROC)QuaternionDlgProc);
	g_hDlgSLERP = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogSLERP), hwnd, (DLGPROC)SLERPDlgProc);

	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT)
			{
				break;
			}

			if ((g_hDlgMatrix == 0 && g_hDlgTransformation == 0 && g_hDlgGaussian == 0 && g_hDlgQuaternion == 0 && g_hDlgSLERP == 0) ||
				(!IsDialogMessage(g_hDlgMatrix, &msg) && !IsDialogMessage(g_hDlgTransformation, &msg) && !IsDialogMessage(g_hDlgGaussian, &msg) && !IsDialogMessage(g_hDlgQuaternion, &msg) && !IsDialogMessage(g_hDlgSLERP, &msg)))
			{
				// Translate any accelerator keys.
				TranslateMessage(&msg);
				// Send the message to the window proc.
				DispatchMessage(&msg);
			}
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}


