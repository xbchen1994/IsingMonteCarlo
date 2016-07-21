#pragma once

class Options
{
public:
	typedef enum IsingStart {
		ZeroTemperature,
		InfiniteTemperature
	} IsingStart;


	typedef enum BlockRenormalizationType {
		Majority,
		Decimation
	} BlockRenormalizationType;

	IsingStart startIsing;
	BlockRenormalizationType renormalizationType;

	double J;
	double B;

	unsigned long int warmupSteps;
	unsigned long int equilibrationSteps;
	unsigned long int collectionSteps;

	int numThreads;
	int latticeSize;

	double temperatureStep;
	double lowTemperature;
	double highTemperature;

	unsigned int MaxRenormalizations;
	double renormalizationTemperature1, renormalizationTemperature2, renormalizationTemperature3;

	unsigned int timerInterval;

	COLORREF spinUpColor;
	COLORREF spinDownColor;

	unsigned int chartLineThickness;
	COLORREF energyColor, magnetizationColor, specificHeatColor, susceptibilityColor;

	unsigned int maxSpecificHeat, maxSusceptibility;

	unsigned int ticksSusceptibility, ticksSpecificHeat;


	Options();
	~Options();

	void Load();
	void Save();
protected:
	static COLORREF GetColor(LPCTSTR param, COLORREF defval = RGB(0,0,0));
	static double GetDouble(LPCTSTR param, double defval = 0);
};
