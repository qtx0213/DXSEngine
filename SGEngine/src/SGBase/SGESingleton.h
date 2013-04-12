#pragma once

template<typename T>
class CSGESingleton
{
public:
	CSGESingleton(void);
	~CSGESingleton(void);
private:
	static T* m_singleton;
public:
	static T& getSingleton(void)
	{
		return (*m_singleton);
	}

	static T* getSingletonPtr(void)
	{
		return m_singleton;
	}
};
