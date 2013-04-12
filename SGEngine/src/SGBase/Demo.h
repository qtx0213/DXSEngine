#pragma once

class CDemo
{
private:
	CDemo(void);
	~CDemo(void);
public:
	bool	initDirectx9(HWND hwnd);
	void	render();
};
