#ifndef			_XANADU_DATABASE_SQLITE3_H_
#define			_XANADU_DATABASE_SQLITE3_H_

#include <XanaduDatabase/Header.h>

// SQLite3 database operations
class XANADU_DATABASE_EXPORT XDatabaseSQLite3
{
private:
	// Database handle
	HANDLE				_database_handle;

public:
	// Structure
	XDatabaseSQLite3() noexcept;

	// Virtual destructor
	virtual ~XDatabaseSQLite3() noexcept;

public:
	// Open the database
	virtual bool Open(const XString& _Database) noexcept;

	// Close the database
	virtual bool Close() noexcept;

public:
	// Executes the SQL statement in the specified database
	static bool Execute(const XString& _Database, const XString& _SQL, std::function<bool(const std::vector<XVariant>& _DBRLine)> _Lambda) noexcept;
};

#endif
