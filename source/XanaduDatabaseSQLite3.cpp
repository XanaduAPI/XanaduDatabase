#include <XanaduDatabase/XanaduDatabaseSQLite3.h>
#include "SQLite3/sqlite3.h"

XDatabaseSQLite3::XDatabaseSQLite3() XANADU_NOTHROW
{
	this->_database_handle = nullptr;
}

XDatabaseSQLite3::~XDatabaseSQLite3() XANADU_NOTHROW
{
	Close();
}

/// Open the database
bool XDatabaseSQLite3::Open(const XString& _Database) XANADU_NOTHROW
{
	auto		vHandle = static_cast<sqlite3*>(nullptr);
	auto		vResult = sqlite3_open16(_Database.data(), &vHandle);
	if (SQLITE_OK == vResult)
	{
		this->_database_handle = vHandle;
		return true;
	}
	return false;
}

/// Close the database
bool XDatabaseSQLite3::Close() XANADU_NOTHROW
{
	if (this->_database_handle)
	{
		sqlite3_close(static_cast<sqlite3*>(this->_database_handle));
		this->_database_handle = nullptr;
	}
	return true;
}

/// Executes the SQL statement in the specified database
bool XDatabaseSQLite3::Execute(const XString& _Database, const XString& _SQL, std::function<bool(const std::vector<XVariant>& _DBRLine)> _Lambda) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Lambda, false);

	auto		vSQLite3 = XDatabaseSQLite3();
	auto		vSync = SQLITE_ERROR;
	if (vSQLite3.Open(_Database))
	{
		auto	vSQL = _SQL.toUString();
		auto	vHandle = static_cast<sqlite3*>(vSQLite3._database_handle);
		auto	vResultVector = std::vector<XVariant>();
		auto	vResultDB = static_cast<char**>(nullptr);
		auto	vResultError = static_cast<char*>(nullptr);
		auto	vResultRow = static_cast<int>(0);
		auto	vResultColumn = static_cast<int>(0);
		if (vHandle)
		{
			vSync = sqlite3_get_table(vHandle, vSQL.data(), &vResultDB, &vResultRow, &vResultColumn, &vResultError);
			if(SQLITE_OK == vSync)
			{
				/// The callback title [回调标题]
				for(auto vIndexColumn = 0; vIndexColumn < vResultColumn; ++vIndexColumn)
				{
					vResultVector.push_back(XByteArray(vResultDB[vIndexColumn]));
					_Lambda(vResultVector);
				}
				/// Callback result set [回调结果]
				for(auto vIndex = 1; vIndex <= vResultRow && vResultColumn; ++vIndex)
				{
					vResultVector.clear();
					for(auto vIndexColumn = 0; vIndexColumn < vResultColumn; ++vIndexColumn)
					{
						vResultVector.push_back(XByteArray(vResultDB[vIndex * vResultColumn + vIndexColumn]));
						_Lambda(vResultVector);
					}
				}
				sqlite3_free_table(vResultDB);
			}
		}
		vSQLite3.Close();
	}
	return SQLITE_OK == vSync;
}
