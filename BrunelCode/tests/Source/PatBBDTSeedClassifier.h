    
#pragma once

#include <vector>
#include <map>


class PatBBDTSeedClassifier 
{
public:
    PatBBDTSeedClassifier();

    void initialize();
    double getMvaValue(const std::vector<double>& parametersVector );
    

private:
    //initialization phase
    std::vector <std::pair<std::string, std::vector<double>>> initBinEdgeMaps();
    std::vector<double> initLookupTable();

    // model prediction phase
    std::vector<int> getBinIndices(const std::vector<double>& parametersVector);
    int convertBinIndicesToLookupIndex(std::vector<int>& binIndices);
    double getBBDTPrediction(int lookupIndex);


    std::vector <std::pair<std::string, std::vector<double>>> m_binsEdgeMap;
    std::vector<double> m_lookupTable;
};

