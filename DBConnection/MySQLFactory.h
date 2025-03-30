#pragma once
#include "ConnectionFactory.h"

//��������������MySQLConnection����
class MySQLFactory : public ConnectionFactory
{
public:
	std::unique_ptr<IDBConnection> create() override;
};

