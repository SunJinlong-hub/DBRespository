#pragma once
#include <queue>
#include <memory>
#include <mutex>
#include "IDBConnection.h"
#include "ConnectionFactory.h"

//数据库连接池核心实现
class DBConnectionPool
{
public:
	//DBConnectionPool();
	~DBConnectionPool();
	static DBConnectionPool& getInstance(ConnectionFactory& factory, size_t initSize = 5);

private:
	std::queue<std::unique_ptr<IDBConnection>> m_pool;
	std::mutex mtx_;
	std::condition_variable cv_;
	ConnectionFactory& fatory_;

	DBConnectionPool(ConnectionFactory& factory, size_t initSize);
	std::unique_ptr<IDBConnection> acquire();
	void release(std::unique_ptr<IDBConnection> conn);
};

