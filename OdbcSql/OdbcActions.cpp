
#include "stdafx.h"
#include "formMain.h"

using namespace System;
using namespace std;

namespace OdbcSql {


	System::Boolean ^ OdbcActions::Connect(System::String ^ dsnName ) 
	{
		System::Boolean ^ result = false;
		System::String ^ _connectionDebug = System::String::Empty;
		
		MarshalString(dsnName, this->_dsnName);

		// Initialize The Return Code Variable
		rc = SQL_SUCCESS;
		// Allocate An Environment Handle
		rc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &EnvHandle);
		// Set The ODBC Application Version To 3.x
		if (rc == SQL_SUCCESS)
		{
			rc = SQLSetEnvAttr(EnvHandle, SQL_ATTR_ODBC_VERSION,
				(SQLPOINTER) SQL_OV_ODBC3, SQL_IS_UINTEGER);
		}
		// Allocate A Connection Handle
		if (rc == SQL_SUCCESS)
		{
			rc = SQLAllocHandle(SQL_HANDLE_DBC, EnvHandle, &ConHandle);
		}

		OdbcActions::dsn = strToWchart(this->_dsnName);
		SQLRETURN rc = SQL_SUCCESS;
		SQLWCHAR DBName[255] = {0};

		wcscpy((wchar_t *) DBName, OdbcActions::dsn);
		rc = SQLConnectW(OdbcActions::ConHandle, DBName, SQL_NTS, (SQLWCHAR *) "", SQL_NTS, (SQLWCHAR *) "", SQL_NTS);
		rc = NULL;

		return result;
	}


	vector<vector<string>> OdbcActions::ExecuteSql(std::string SQLstatement)
	{
		return OdbcActions::ExecuteSql(SQLstatement, -1);
	}

	vector<vector<string>> OdbcActions::ExecuteSql(std::string SQLstatement, int maxresults)
	{
		vector<vector<string>> resultTable;

		std::wstring convertQuery = std::wstring(SQLstatement.begin(), SQLstatement.end());

		// Declare The Local Memory Variables
		SQLRETURN rc = SQL_SUCCESS;
		SQLWCHAR DBName[] = {0};
		SQLWCHAR SQLStmt[255] = {0};

		int i = 0;
		if (OdbcActions::ConHandle != NULL)
		{
			// Allocate An SQL Statement Handle
			rc = SQLAllocHandle(SQL_HANDLE_STMT, ConHandle, &StmtHandle);
			if (rc == SQL_SUCCESS)
			{
				// Define A SELECT SQL Statement
				//wcscpy((wchar_t *) SQLStmt, L"SELECT * FROM [AdventureWorks2012].[Production].[Product]");

				wcscpy((wchar_t *) SQLStmt, convertQuery.c_str());

				//quering
				rc = SQLExecDirect(OdbcActions::StmtHandle, SQLStmt, SQL_NTS);
				/* BEGIN - Get the column count */

				//get the column count
				SQLSMALLINT numCols;
				SQLINTEGER numBytes;
				rc = SQLNumResultCols(OdbcActions::StmtHandle, &numCols); 

				/* END - Get the column count */

				rc = SQLFetch(OdbcActions::StmtHandle);
				while(rc == SQL_SUCCESS)
				{
					register char sqlbuf[2048];
					vector<string> rowData;

					//load the entire row to a vector
					for (int z = 0; z < numCols; z++)
					{
						SQLGetData(OdbcActions::StmtHandle, z, SQL_C_CHAR, sqlbuf, 256, &numBytes);
						rowData.push_back(sqlbuf);
					}

					resultTable.push_back(rowData);

					//if -1 is the given parameter, we just return the whole list.
					++i;
					if(maxresults != -1 && i == maxresults)
					{
						break;
					}
					rc = SQLFetch(OdbcActions::StmtHandle);
				}

			}
			else
			{
				//throw "Miserable failure when connecting to ODBC\n";
				throw gcnew System::Exception("Miserable failure when connecting to ODBC");
				//return nullptr;
			}
			// Free The SQL Statement Handle
			if (OdbcActions::StmtHandle != NULL)
			{
				SQLFreeHandle(SQL_HANDLE_STMT, OdbcActions::StmtHandle);
			}

		}

		// Return To The calling function
		return resultTable;
	}

	System::String ^ OdbcActions::ExecuteSql(System::String ^ SQLstatement) 
	{
		System::String ^ result = System::String::Empty;



		return result;
	}

	System::Boolean ^ OdbcActions::Close()
	{
		System::Boolean ^ result = false;

		if (ConHandle != NULL)
		{
			SQLFreeHandle(SQL_HANDLE_DBC, ConHandle);
		}
		// Free The Environment Handle
		if (EnvHandle != NULL)
		{
			SQLFreeHandle(SQL_HANDLE_ENV, EnvHandle);
		}

		SQLRETURN rc = SQL_SUCCESS;
		// Disconnect From Database
		rc = SQLDisconnect(OdbcActions::ConHandle);
		rc = NULL;

		return result;
	}

	OdbcActions::~OdbcActions()
	{
		this->Close();
	}

	/* C++/CLI to regular C++ plumbing */

	const wchar_t * OdbcActions::strToWchart(std::string sInput)
	{
		wchar_t* wCharOutput = new wchar_t[1023];
		size_t* sizeOut = new size_t;
		size_t sizeInWords = 256;

		const char* cStr;
		cStr = sInput.c_str();
		mbstowcs_s( sizeOut, wCharOutput, sizeInWords, cStr, strlen(cStr)+1);

		return wCharOutput;
	}

	const std::string OdbcActions::wchartToStr(const wchar_t* wInput)
	{
		std::string sOutput = "";
		size_t* nbOfChar = new size_t;
		char* cOut = new char[1023];
		size_t sizeInBytes = 1023;

		wcstombs_s( nbOfChar, cOut, sizeInBytes, wInput, 1023);
		sOutput += cOut;

		return sOutput;
	}


	void OdbcActions::MarshalString ( String ^ s, string& os ) {
		using namespace Runtime::InteropServices;
		const char* chars = 
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	void OdbcActions::MarshalString ( String ^ s, wstring& os ) {
		using namespace Runtime::InteropServices;
		const wchar_t* chars = 
			(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
}
