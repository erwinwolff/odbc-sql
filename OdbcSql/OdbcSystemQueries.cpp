#include "stdafx.h"
#include "formMain.h"
#include <iostream>

using namespace System;
using namespace std;

namespace OdbcSql {

	System::String ^ OdbcSystemQueries::GetDrivers()
	{
		System::String ^ result = System::String::Empty;

		//get ODBC drivers
		SQLHENV env;
		SQLWCHAR driver[256];
		SQLWCHAR attr[256];
		SQLSMALLINT driver_ret;
		SQLSMALLINT attr_ret;
		SQLUSMALLINT direction;
		SQLRETURN ret;

		SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
		SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);

		direction = SQL_FETCH_FIRST;
		while(SQL_SUCCEEDED(ret = SQLDrivers(env, direction,
			driver, sizeof(driver), &driver_ret,
			attr, sizeof(attr), &attr_ret))) {
				direction = SQL_FETCH_NEXT;

				result += System::String::Format("{0}\n", gcnew String(driver));

		}

		SQLFreeHandle(SQL_HANDLE_ENV, env);
		return result;
	}

	System::String ^ OdbcSystemQueries::GetDSN()
	{
		System::String ^ result = System::String::Empty;
		SQLHENV env;
		SQLWCHAR dsn[256];
		SQLWCHAR desc[256];
		SQLSMALLINT dsn_ret;
		SQLSMALLINT desc_ret;
		SQLUSMALLINT direction;
		SQLRETURN ret;

		SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
		SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);

		direction = SQL_FETCH_FIRST;
		while(SQL_SUCCEEDED(ret = SQLDataSources(env, direction,
			dsn, sizeof(dsn), &dsn_ret,
			desc, sizeof(desc), &desc_ret))) {
				direction = SQL_FETCH_NEXT;
				//printf("%s - %s\n", dsn, desc);
				result += System::String::Format("{0} - {1}\n", gcnew String(dsn), gcnew String(desc));
		}

		SQLFreeHandle(SQL_HANDLE_ENV, env);

		return result;
	}


	System::Collections::Generic::List<System::String ^> ^  OdbcSystemQueries::GetDSNList()
	{
		System::Collections::Generic::List<System::String ^> ^ result = gcnew System::Collections::Generic::List<System::String ^>();
		SQLHENV env;
		SQLWCHAR dsn[256];
		SQLWCHAR desc[256];
		SQLSMALLINT dsn_ret;
		SQLSMALLINT desc_ret;
		SQLUSMALLINT direction;
		SQLRETURN ret;

		SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
		SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);

		direction = SQL_FETCH_FIRST;
		while(SQL_SUCCEEDED(ret = SQLDataSources(env, direction,
			dsn, sizeof(dsn), &dsn_ret,
			desc, sizeof(desc), &desc_ret))) {
				direction = SQL_FETCH_NEXT;
				//printf("%s - %s\n", dsn, desc);
				//result += System::String::Format("{0} - {1}\n", gcnew String(dsn), gcnew String(desc));
				result->Add(gcnew String(dsn));
		}

		SQLFreeHandle(SQL_HANDLE_ENV, env);

		return result;
	}
}