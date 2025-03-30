#pragma once
#include "IDBConnection.h"
class MySQLConnection : public IDBConnection
{
public:
	void connect() override;
	void execute(const std::string& query) override;
	~MySQLConnection() override = default;
};

