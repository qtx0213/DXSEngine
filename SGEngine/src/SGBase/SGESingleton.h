#pragma once

template<typename T>
class CSGESingleton
{
	//���ù��캯��Ϊ��������ֱֹ��ʵ��������
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
