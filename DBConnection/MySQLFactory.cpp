#include "MySQLFactory.h"
#include "MySQLConnection.h"

std::unique_ptr<IDBConnection> MySQLFactory::create()
{
	auto conn = std::make_unique<MySQLConnection>();
	conn->connect();
	return conn;
}
