#include "PostgreSQLFactory.h"
#include "PostgreSQLConnection.h"

std::unique_ptr<IDBConnection> PostgreSQLFactory::create()
{
	auto conn = std::make_unique<PostgreSQLConnection>();
	conn->connect();
	return conn;
}
