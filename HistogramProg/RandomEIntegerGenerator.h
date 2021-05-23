#ifndef RandomEIntegerGenerator_H
#define RandomEIntegerGenerator_H

#include "HistogramBase.h"

#include <ctime>

namespace Hist
{

	class RandomEIntegerGenerator : public RandomEintegerGeneratorBase
	{
	public:
	
		EInteger  operator ()()
		{

			//GIVES SMALL VALUES ON SMALL CHANGE
			//THIS ALSO MIGHT CAUSE PROBLEM WHEN EINTEGER HAS OTHER THAN x + 1 VALUES
			//THOSE NEED TO BE CHECHED OTHER WÌSE
			//CURRENT SETUP IS GOOD CAUSE EInteger SI BETWIX 0-4
			int num = (rand() % (Hist::HistogramBase::EIntMax + 1));

			
			return static_cast<EInteger>(num);
		};

		EInteger GetRand();

		
	};
}

#endif

