#include <iostream>
#include <chrono>
#include <conio.h>
#include <string>
#include <thread>
#include <Windows.h>
using namespace std;

int main()
{
	bool start{ true };
	chrono::steady_clock::time_point TimeBegin;
	for (;;)
	{
		bool PrintTime{ false }, Continue{ false };
		char c = _kbhit() ? _getch() : L'\0';

		switch (c)
		{
		case L' ':
			if (start) {
				start = false;
				TimeBegin = chrono::steady_clock::now();
				Continue = true;
				break;
			}
			PrintTime = true;
			break;
		case L'\r':
			wcout << L"\n\n";
			return 0;
		}

		if (Continue or start) continue;

		auto TimePoint{ chrono::steady_clock::now() };
		if (!PrintTime) wcout << L'\r' << wstring(50, L' ') << L'\r';
		else wcout << L'\n';

		auto interval = chrono::duration_cast<chrono::milliseconds>(
			TimePoint - TimeBegin
		).count();

		wcout << interval / 60'000 << L" min & " << (interval % 60'000) / 1000;
		wcout << L"." << interval % 1000 << L" sec";
		Sleep(10);
	}
}