

#include "PatBBDTSeedClassifier.h"
#include <iostream>
#include <sstream>
#include <fstream>

DECLARE_TOOL_FACTORY( PatBBDTSeedClassifier )

using namespace std;


double PatBBDTSeedClassifier::getMvaValue(const std::vector<double>& parametersVector )
{
    auto binIndices = getBinIndices(parametersVector);
    double prediction = getBBDTPrediction(binIndices);
    for(const auto& bin: binIndices) debugFile<<bin<<" ";
    debugFile<<prediction<<endl;
    return prediction; 
}


PatBBDTSeedClassifier::PatBBDTSeedClassifier( const std::string& type,
                                                const std::string& name,
                                                const IInterface* parent )
        : GaudiTool ( type, name , parent )
{
    declareInterface<IPatMvaClassifier>(this);
}


StatusCode PatBBDTSeedClassifier::initialize()
{
    StatusCode sc =  GaudiTool::initialize();
    if(sc.isFailure()) return Error("Failed to initialize", sc);

    initBinEdgeMaps();
    initTupleClassifier();
    debugFile.open("Brunel_indices_debug.txt");
    return StatusCode::SUCCESS;
    
}

std::vector<int> PatBBDTSeedClassifier::getBinIndices(const std::vector<double>& parametersVector)
{
    std::vector<int> binIndices;
    int featureIt = 0;
    for (const auto& featurePair: m_binsEdgeMap){
      binIndices.push_back(getIndex(featurePair.second,parametersVector[featureIt]));
      featureIt++;
    }
    return binIndices;
}


int PatBBDTSeedClassifier::getIndex(const vector<double>& bins, double value)
{
  auto lower_bound = std::lower_bound(bins.begin(), bins.end(), value);
  return std::distance(bins.begin(),lower_bound);   
}


double PatBBDTSeedClassifier::getBBDTPrediction(const std::vector<int>& binIndices)
{
    return m_tupleClassifier[binIndices];
}

void PatBBDTSeedClassifier::initTupleClassifier() {
    
    ifstream file("/afs/cern.ch/user/a/adendek/lb_devs/BrunelDev_v52r0/Tf/PatAlgorithms/src/BBDT_tuple.csv", std::ifstream::in);
    // dodac sprawdzanie checksum aby byc pewnym ze jest dobra wartosc 
    std::string line;
    std::getline(file, line); // skip header
    std::cout<<"list of input features"<<line<<std::endl;
    // get the rest of the lines
    
    while (std::getline(file, line))
    {
        vector<string> substrings = splitString(line,',');
        vector<int> indices; 
        double prediction;
        convertStringArrayToTuple(substrings ,indices, prediction);
        m_tupleClassifier.insert(make_pair(indices, prediction));
    }
    
}

vector<string> PatBBDTSeedClassifier::splitString(const string& toSplit, char token )
{
    vector<string> subStrings;
    
    std::stringstream stringStream;
    stringStream.str(toSplit);
    std::string item;
    while (getline(stringStream, item, token)) {
        subStrings.push_back(item);
    }
    return subStrings;
}

void PatBBDTSeedClassifier::convertStringArrayToTuple(vector<string>& substrings, vector<int>& indicesVector, double& prediction)
{
    for(auto it= substrings.begin();it!= substrings.end()-1;it++ ){
        indicesVector.push_back(atoi((*it).c_str()));
    }
    prediction = atof((*(substrings.end()-1)).c_str());
}


void PatBBDTSeedClassifier::initBinEdgeMaps()
{
    m_binsEdgeMap ={
    	 {"seed_chi2PerDoF", {1.04402184717,1.61783275814,2.59689245638,}},
	 {"seed_p", {2809.3865579,4734.49616298,9835.16115022,}},
	 {"seed_pt", {926.377437342,1129.73667141,1373.44143919,}},
	 {"seed_nLHCbIDs", {17.0,20.0,22.0,}},
	 {"abs_seed_x", {207.828515692,488.389691944,926.731525532,}},
	 {"abs_seed_y", {128.703194603,308.451486415,676.400705441,}},
	 {"abs_seed_tx", {0.101668345854,0.229365978794,0.413773822268,}},
	 {"abs_seed_ty", {0.0177061662818,0.041778959923,0.0857171490924,}},
	 {"seed_r", {377.731916305,749.303903514,1232.56385361,}},
	 {"pseudo_rapidity", {0.119803331508,0.243167784582,0.412974432133,}},

 };
}
    