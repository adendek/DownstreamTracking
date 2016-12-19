
/** This file was generated automaticly by python script 
https://github.com/adendek/DownstreamTracking/blob/master/SeedClasifier/BDT-XGBoost.ipynb
DO NOT MODIFY IT MANUALLY!!!!!!
*/
    
#pragma once

#include "PatKernel/IPatMvaClassifier.h"
#include "PatKernel/IPatMvaClassifier.h"
#include "GaudiAlg/GaudiTool.h"

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>


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
    void initBinEdgeMaps();
    void initTupleClassifier();
    
    int getIndex(const std::vector<double>& bins, double value);

    
    std::vector<int> getBinIndices(const std::vector<double>& parametersVector);
    std::vector<std::string> splitString(const std::string& toSplit, char token );
    void convertStringArrayToTuple(std::vector<std::string>& substrings, 
                                   std::vector<int>& indicesVector, double& prediction);

    // model prediction phase
    double getBBDTPrediction(const std::vector<int>& binIndices);


    std::vector <std::pair<std::string, std::vector<double>>> m_binsEdgeMap;
    std::map <std::vector<int>, double > m_tupleClassifier;
    std::ofstream debugFile;
};
