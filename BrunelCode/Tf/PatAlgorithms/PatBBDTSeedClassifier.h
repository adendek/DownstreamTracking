
/** This file was generated automaticly by python script 
https://github.com/adendek/DownstreamTracking/blob/master/SeedClasifier/BDT-XGBoost.ipynb
DO NOT MODIFY IT MANUALLY!!!!!!
*/
    
#pragma once

#include "PatKernel/IPatMvaClassifier.h"
#include "GaudiAlg/GaudiTool.h"
#include <vector>
#include <map>


class PatBBDTSeedClassifier : public GaudiTool, virtual public IPatMvaClassifier
{
public:
    PatBBDTSeedClassifier( const std::string& type,
                           const std::string& name,
                           const IInterface* parent);

    double getMvaValue(const std::vector<double>& parametersVector );

    virtual StatusCode initialize();

private:
    //initialization phase
    std::vector<std::pair<std::string, std::vector<double>>> initBinEdgeMaps();
    std::vector<double> initLookupTable();

    // model prediction phase
    std::vector<int> getBinIndices(const std::vector<double>& parametersVector);
    int convertBinIndicesToLookupIndex(std::vector<int>& binIndices);
    double getBBDTPrediction(int lookupIndex);


    std::vector< std::pair<std::string, std::vector<double> >> m_binsEdgeMap;
    std::vector<double> m_lookupTable;
};

