#include "Histogram.h"

using namespace Hist;



Histogram::Histogram(int i) : HistogramBase(i)
{
	//std::cout << "Histogram::Histogram(" + std::to_string(i) + ")\n";
	//std::cout << "iTEST(" + std::to_string(iTest) + ")\n";
}


Histogram::Histogram(std::unique_ptr<Logger> log) : HistogramBase(std::make_unique<Logger>())
{
	m_log = std::move(log);
}

void Histogram::add(EInteger e)
{
	//int i =  m_log->AddData(e);3
	m_log->vec.push_back(e);

}

EInteger Histogram::getMode() const
{
	int _Mode = EIntError;
	int _Count = 0 ;

	if (m_log->vec.size() != 0)
	{
		//GET ALL MODES TO VECTOR MAP
		std::map<int, int> _Modes;

		for (auto i : m_log->vec)
		{
			++_Modes[i];
		}

		//CHECK MOST COMMON

		for (unsigned int i = 0; i < _Modes.size(); i++)
		{
			if (_Count < _Modes[i])
			{
				_Count = _Modes[i];
				_Mode  = i;
			}
		}
	}


	return static_cast<EInteger>(_Mode);
}

//GET VECTOR MIN VALUE WITH VECTOR ALGORITMS
EInteger Histogram::getMinValue() const
{
	int _Min = EIntError;
	if (m_log->vec.size() != 0)
	{
		std::vector<int>::iterator result = std::min_element(m_log->vec.begin(), m_log->vec.end());
		_Min = result[0];
	}
	return static_cast<EInteger>(_Min);
}

//GET VECTOR MAX VALUE WITH VECTOR ALGORITMS
EInteger Hist::Histogram::getMaxValue() const
{

	int _Max = EIntError;
	//RETURN -1 If vector is empty
	if (m_log->vec.size() != 0)
	{
		std::vector<int>::iterator result = std::max_element(m_log->vec.begin(), m_log->vec.end());
		_Max = result[0];
	}

	return static_cast<EInteger>(_Max);
}


//Get count of Database
int Hist::Histogram::getCount() const
{
	return m_log->vec.size();
}

EInteger Hist::Histogram::getOneData(int iPos) const
{
	return static_cast<EInteger>(m_log->vec[iPos]);
}
