// OdbcSql.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "OdbcSql.h"

#include "formMain.h"

using namespace OdbcSql;


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	
	formMain ^ main = gcnew formMain();

	main->ShowDialog();

	return 0;
}

