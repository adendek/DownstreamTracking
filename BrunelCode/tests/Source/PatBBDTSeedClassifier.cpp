

#include "PatBBDTSeedClassifier.h"
#include <iostream>

using namespace std;


double PatBBDTSeedClassifier::getMvaValue(const std::vector<double>& parametersVector )
{
    auto binIndices = getBinIndices(parametersVector);
    return getBBDTPrediction(binIndices);
}


PatBBDTSeedClassifier::PatBBDTSeedClassifier( )
{
    initialize();
}

void PatBBDTSeedClassifier::initialize()
{
    initBinEdgeMaps();
    initTupleClassifier();
}

std::vector<int> PatBBDTSeedClassifier::getBinIndices(const std::vector<double>& parametersVector)
{
    int actualFeature = 0;
    int binPerFeatures = 2;
    std::vector<int> binIndicesMap;
    for (const auto& featurePair: m_binsEdgeMap){
        int binNumber = 0;
        for(const auto& binValue : featurePair.second) {
            if (parametersVector[actualFeature] < binValue) {
                binIndicesMap.push_back(binNumber);
                break;
            }
            binNumber++;
            if(binNumber == binPerFeatures -1 ) binIndicesMap.push_back(binNumber);

        }
        actualFeature++;
    }
    return binIndicesMap;
}

double PatBBDTSeedClassifier::getBBDTPrediction(const std::vector<int>& binIndices)
{
    return m_tupleClassifier[binIndices];
}

void PatBBDTSeedClassifier::initTupleClassifier() {
    TTree *tree = 0;
    TFile *f = (TFile *) gROOT->GetListOfFiles()->FindObject("Source/tuple_classifer.root");
    if (!f || !f->IsOpen()) {
        f = new TFile("Source/tuple_classifer.root");
    }
    f->GetObject("tree", tree);

    if (!tree) cout << "Tree is null" << endl;

    tree->SetBranchAddress("x", &x, &b_x);
    tree->SetBranchAddress("y", &y, &b_y);
    tree->SetBranchAddress("pred", &pred, &b_pred);

    m_leafTypes.push_back(&x);
    m_leafTypes.push_back(&y);


    Long64_t nentries = tree->GetEntriesFast();
    for (Long64_t jentry = 0; jentry < nentries; jentry++) {
        tree->GetEntry(jentry);
        std::vector<int> binIndices;
        for (const auto &leaf : m_leafTypes) {
            binIndices.push_back(*leaf);
        }
        m_tupleClassifier.insert(std::make_pair(binIndices, pred));
    }
    
}

void PatBBDTSeedClassifier::initBinEdgeMaps()
{
    m_binsEdgeMap ={
    	 {"x", {5.0,}},
	 {"y", {5.0,}},

 };
}
    