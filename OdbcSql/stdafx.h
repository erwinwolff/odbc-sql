// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define _WIN32_WINNT 0x403

#pragma warning(disable: 4996)
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// Windows Header Files:
#include <windows.h>

#include <iostream>
#include <vector>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <string>

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include <atlbase.h>
#include <atlstr.h>

// TODO: reference additional headers your program requires here

#include <sql.h>
#include <sqlext.h>

#include "OdbcSql.h"
#include "OdbcActions.h"
#include "OdbcSystemQueries.h"


enum OutputType { TABLE, JSON, XML };