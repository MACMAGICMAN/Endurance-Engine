#pragma once

class EnduranceEngine
{
public:
	EnduranceEngine();
	~EnduranceEngine();
	void Initialize();
	int Start(_In_ HINSTANCE hInstance,
		_In_ HINSTANCE hPrevInstance,
		_In_ LPSTR lpCmdLine,
		_In_ int nCmdShow);
};