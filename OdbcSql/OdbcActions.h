#pragma once

#include "stdafx.h"
#include "resource.h"

using namespace std;

namespace OdbcSql {

	struct OdbcActions {
	private:
		std::string _dsnName;
		bool _connected;


	private:
		const wchar_t * strToWchart(std::string sInput);
		const std::string wchartToStr(const wchar_t* wInput);


	public:

		const wchar_t * dsn;

		SQLHANDLE EnvHandle;
		SQLHANDLE ConHandle;
		SQLHANDLE StmtHandle;
		SQLRETURN rc;

		System::Boolean ^ Connect(System::String ^ dsn);
		System::String ^ ExecuteSql(System::String ^ SQLstatement);
		vector<vector<string>> OdbcActions::ExecuteSql(std::string SQLstatement, int maxresults);
		vector<vector<string>> OdbcActions::ExecuteSql(std::string SQLstatement);

		void MarshalString ( System::String ^ s, string& os );
		void MarshalString ( System::String ^ s, wstring& os );

		System::Boolean ^ Close();
		OdbcActions::~OdbcActions();
	};
}