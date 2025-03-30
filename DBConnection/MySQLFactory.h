#pragma once
#include "ConnectionFactory.h"

//工厂方法，创建MySQLConnection对象
class MySQLFactory : public ConnectionFactory
{
public:
	std::unique_ptr<IDBConnection> create() override;
};

