    
    
#pragma once

#include <vector>
#include <map>
#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>


class PatBBDTSeedClassifier 
{
public:
    PatBBDTSeedClassifier();

    void initialize();
    double getMvaValue(const std::vector<double>& parametersVector );
    std::vector<int> getBinIndices(const std::vector<double>& parametersVector);


private:
    //initialization phase
    void initBinEdgeMaps();
    void initTupleClassifier();

    // model prediction phase
    double getBBDTPrediction(const std::vector<int>& binIndices);


    std::vector <std::pair<std::string, std::vector<double>>> m_binsEdgeMap;
    std::map <std::vector<int>, double > m_tupleClassifier;


    // tree specific member fields

    // Declaration of leaf types
    std::vector<Double_t*> m_leafTypes;

    Double_t           x;
    Double_t           y;
    Double_t        pred;

    // List of branches
    TBranch        *b_x;   //!
    TBranch        *b_y;   //!
    TBranch        *b_pred;   //!
};


