
#pragma once

#include "stdafx.h"
#include "resource.h"

namespace OdbcSql {
	struct OdbcSystemQueries {
	
	public:
		System::String ^ GetDrivers();
		System::String ^ GetDSN();
		System::Collections::Generic::List<System::String ^> ^  GetDSNList();
	};

}