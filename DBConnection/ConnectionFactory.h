#pragma once
#include "IDBConnection.h"
#include <memory>

class ConnectionFactory
{
public:
	virtual std::unique_ptr<IDBConnection> create() = 0;
	virtual ~ConnectionFactory() = default;
};

