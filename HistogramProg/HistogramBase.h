#ifndef HISTOGRAMBASE_H
#define HISTOGRAMBASE_H

//FOR DEBUGGING
#include <iostream>
#include <string>

#include "Log.h"
#include <memory>


namespace Hist
{
	enum EInteger : int
	{
		Zero = 0,
		One = 1,
		Two = 2,
		Three = 3,
		Four = 4
	};


	class RandomEintegerGeneratorBase
	{
	public:
		// Returns a pseudo-random EInteger value
		virtual EInteger operator()() = 0;
	};


	/*
	* CLASS STRUCTURE IS WAY TOO COMPLICATED TO RELATING SOFTWARE
	* THIS Base class shuold be all way virtual to present only what is needed
	* In case if there multiple interfaces to different datasources
	*
	*/
	class HistogramBase
	{

	public:
		HistogramBase() = delete;
		HistogramBase(int);
		HistogramBase(std::unique_ptr<Logger>);

		virtual void add(EInteger) = 0;

		// Return the value that occurrs most often in the data set (I.e. there exists no other value that occurs more often than the return value)
		virtual EInteger getMode() const = 0;

		// Return the smallest value in the data set, according to default ordering relation of integer numbers
		virtual EInteger getMinValue() const = 0;

		// Return the largest value in the data set
		virtual EInteger getMaxValue() const = 0;

	//virtual ~HistogramBase();

		//EInterger MAX VALUE
		static const EInteger EIntMax = Four;

		//EInterger MIN VALUE
		static const EInteger EIntMin = Zero;

		//EInterger Error value when no values is not presented
		int EIntError = -1;


	private:
		std::unique_ptr<Logger> m_log;

	};



}
#endif

