#pragma once
#include <chrono>

namespace mtimer
{
	using Time = std::chrono::steady_clock::time_point;
	using Duration = std::chrono::duration<float>;
	class Timer
	{
	private:
		Time start_point;
		float& time;
	public:
		Timer(float& time);
		~Timer();
	};
}