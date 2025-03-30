#pragma once
#include "ConnectionFactory.h"

class PostgreSQLFactory : public ConnectionFactory	
{
public:
	std::unique_ptr<IDBConnection> create() override;
};

