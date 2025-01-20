#include <iomanip>
#include <iostream>
#include <chrono>
#include <conio.h>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>
using namespace std;
HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	bool start{ true };
	chrono::steady_clock::time_point ref = chrono::steady_clock::now();
	chrono::steady_clock::time_point TimeBegin;
	vector<long long> stops;

	SetConsoleTextAttribute(hConsoleOut, 15);
	for (;;)
	{
		bool PrintTime{ false }, Exit{ false };
		char c = _kbhit() ? _getch() : L'\0';

		switch (c)
		{
		case L' ':
			if (start) {
				start = false;
				TimeBegin = chrono::steady_clock::now();
				break;
			}
			PrintTime = true;
			break;
		case L'\r':
			PrintTime = Exit = true;
		}
		if (start) continue;

		auto TimePoint{ chrono::steady_clock::now() };
		auto time = chrono::duration_cast<chrono::milliseconds>(
			TimePoint - TimeBegin
		).count();

		if (!PrintTime) wcout << L'\r' << wstring(50, L' ') << L'\r';
		else {
			wcout << L'\n';
			stops.push_back(time);
		}
		if (Exit) break;

		wcout << time / 60'000 << L" min & " << (time % 60'000) / 1000;
		wcout << L'.' << (time % 1000) / 10 << L" sec";
		Sleep(10);
	}

	vector<long long> intervals(stops.size());
	for (size_t i = 1; i < stops.size(); ++i)
		intervals[i] = stops[i] - stops[i - 1];
	intervals[0] = stops[0];
	
	long double mean{}, deviation{};
	for (const auto& interval : intervals) mean += interval;
	mean /= intervals.size();

	for (const auto& interval : intervals) deviation += pow(mean - interval, 2);
	deviation /= intervals.size();
	deviation = sqrt(deviation);

	wcout << L"\n\nTEMPI:";
	for (size_t i = 0; i < intervals.size(); ++i)
	{
		wcout << L"\n#" << i + 1 << " : ";
		auto time = intervals[i];

		if (time < mean - deviation)
			SetConsoleTextAttribute(hConsoleOut, 10);
		else if (time > mean + deviation)
			SetConsoleTextAttribute(hConsoleOut, 4);
		else SetConsoleTextAttribute(hConsoleOut, 6);

		wcout << time / 60'000 << L" min & " << (time % 60'000) / 1000;
		wcout << L'.' << (time % 1000) / 10 << L" sec";;
		SetConsoleTextAttribute(hConsoleOut, 15);
	}

	_getch();
}