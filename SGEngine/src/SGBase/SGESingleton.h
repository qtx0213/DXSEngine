#pragma once

template<typename T>
class CSGESingleton
{
	//设置构造函数为保护，防止直接实例化对象
protected:
	CSGESingleton(void)
	{
		m_singleton = static_cast<T*>(this);
	};

	~CSGESingleton(void)
	{

	};

private:
	static T* m_singleton;

public:
	static T& getSingleton(void)
	{
		return (*m_singleton);
	};

	static T* getSingletonPtr(void)
	{
		return m_singleton;
	};
};
