#include "HistogramBase.h"

using namespace Hist;

HistogramBase::HistogramBase(int i) 
{
	std::cout << "HistogramBase::HistogramBase(" + std::to_string(i) + ")\n";
	std::cout << "iTEST(" + std::to_string(i) + ")\n";
	//iStatus = i;
}

HistogramBase::HistogramBase(std::unique_ptr<Logger> log)  
{
	m_log = std::move(log);
}
