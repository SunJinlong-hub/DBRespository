#include "DBConnectionPool.h"

//DBConnectionPool::DBConnectionPool()
//{
//
//}

DBConnectionPool::DBConnectionPool(ConnectionFactory& factory, size_t initSize)
	: fatory_(factory)
{
	for (size_t i = 0; i < initSize; i++)
	{
		m_pool.push(factory.create());
	}
}


std::unique_ptr<IDBConnection> DBConnectionPool::acquire()
{
	std::unique_lock<std::mutex> lock(mtx_);
	cv_.wait(lock, [this] {return !m_pool.empty(); });

	auto conn = std::move(m_pool.front());
	m_pool.pop();
	return conn;
}

void DBConnectionPool::release(std::unique_ptr<IDBConnection> conn)
{
	std::lock_guard<std::mutex> lock(mtx_);
	m_pool.push(std::move(conn));
	cv_.notify_one();
}

DBConnectionPool::~DBConnectionPool()
{

}

DBConnectionPool& DBConnectionPool::getInstance(ConnectionFactory& factory, size_t initSize /*= 5*/)
{
	static DBConnectionPool instance(factory, initSize);
	return instance;
}
