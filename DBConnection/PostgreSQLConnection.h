#pragma once
#include "IDBConnection.h"
class PostgreSQLConnection : public IDBConnection
{
public:
	void connect() override;
	void execute(const std::string& query) override;
	~PostgreSQLConnection() override = default;
};

