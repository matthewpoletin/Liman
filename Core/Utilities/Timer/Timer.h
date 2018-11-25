/**
 * @file Timer.h
 * @author matthewpoletin
 */

#pragma once

class Timer
{
public:
	Timer();

	double GetTime();

	void StartTimer();
	void StopTimer();

	double GetDelta();
protected:

private:
	double m_time;
	double m_startTime;
	double m_stopTime;
	double m_delta;

};
