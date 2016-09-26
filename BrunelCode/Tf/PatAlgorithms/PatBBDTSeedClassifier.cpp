
#include "PatBBDTSeedClassifier.h"
#include <stdlib.h>
#include <stdio.h>

DECLARE_TOOL_FACTORY( PatBBDTSeedClassifier )


double PatBBDTSeedClassifier::getMvaValue(const std::vector<double>& parametersVector )
{
  auto binIndices = getBinIndices(parametersVector);
  info()<<"bin idicies";
  for (const auto & ind : binIndices)
    info()<<ind<<" ";
  info()<<endmsg;
  int lookupTableIndex = convertBinIndicesToLookupIndex(binIndices);
  info()<<"lookup table index "<< lookupTableIndex<<endmsg; 
  return getBBDTPrediction(lookupTableIndex);
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
    info()<<"init bins edges"<<endmsg;
    m_binsEdgeMap = initBinEdgeMaps();
    info()<<"init lookup table"<<endmsg;
    m_lookupTable = initLookupTable();
    info()<<"initiazliation end"<<endmsg;
    return StatusCode::SUCCESS;
}

std::vector<int> PatBBDTSeedClassifier::getBinIndices(const std::vector<double>& parametersVector)
{
  /* info()<<"input: ";
  for (const auto & el : parametersVector)
    info()<<el<<" ";
    info()<<endmsg;*/
    std::vector<int> binIndicesMap;
    int actualFeature = 0;
    int maxBinPerFeature = 4;
    for (const auto& featurePair: m_binsEdgeMap){
        int binNumber = 0;
        for(const auto& binValue : featurePair.second) {
            if (parametersVector[actualFeature] < binValue) {
	      // info()<<"feature "<<featurePair.first<<" value "<< parametersVector[actualFeature] << "  bin edge "<< binValue<<endmsg;
                binIndicesMap.push_back(binNumber);
                break;
            }
	    binNumber++;
	    if(binNumber > maxBinPerFeature-2){
	      binIndicesMap.push_back(binNumber);
	      break;
	    }   
        }
        actualFeature++;
    }
    return binIndicesMap;
}
/**
 * adopt to C++ python method
 *  hep_ml.speedup.LookupClassifier.convert_lookup_index_to_bins()
 */


int PatBBDTSeedClassifier::convertBinIndicesToLookupIndex(std::vector<int> &binIndices)
{
    int index = 0;
    const int nbinPerFeature =4;

    for (const auto& indice : binIndices){
        index *= nbinPerFeature;
        index += indice;
    }
    return index;
}

double PatBBDTSeedClassifier::getBBDTPrediction(int lookupIndex)
{
  if(lookupIndex > static_cast<int>(m_lookupTable.size()))
    return -1;
  return m_lookupTable[lookupIndex];
}
std::vector<std::pair<std::string, std::vector<double>>> PatBBDTSeedClassifier::initBinEdgeMaps()
{
  std::vector<std::pair<std::string, std::vector<double>>>  binMap ={
    	 {"seed_chi2PerDoF", {1.04402184717,1.61783275814,2.59689245638,}},
	 {"seed_pt", {926.377437342,1129.73667141,1373.44143919,}},
	 {"seed_nLHCbIDs", {17.0,20.0,22.0,}},
	 {"seed_nbIT", {0.0,0.0,0.0,}},
	 {"seed_nLayers", {11.0,12.0,12.0,}},
	 {"abs_seed_x", {207.828515692,488.389691944,926.731525532,}},
	 {"abs_seed_y", {128.703194603,308.451486415,676.400705441,}},
	 {"abs_seed_tx", {0.101668345854,0.229365978794,0.413773822268,}},
	 {"abs_seed_ty", {0.0177061662818,0.041778959923,0.0857171490924,}},
	 {"seed_r", {377.731916305,749.303903514,1232.56385361,}},
	 {"pseudo_rapidity", {0.119803331508,0.243167784582,0.412974432133,}},

 };
return binMap;
}
    

/** right now I am using the simplest idea of importing lookup table.
 *  More sophisticated method is described in 
 *  http://stackoverflow.com/questions/39529799/initialization-of-very-big-vector-in-c/39531749#39531749
 *   thread. Don't know if will be implemented. 
 */

std::vector<double> PatBBDTSeedClassifier::initLookupTable()
{
    FILE *inFile;
    const int elementNumber = 4194304;

    std::vector<double> lookup_table(elementNumber);
    if (!(inFile = fopen("/afs/cern.ch/user/a/adendek/tracking_brunel/BrunelDev_v51r0/Tf/PatAlgorithms/src/BBDT_lookuptable_binary.dat", "rb")))
        exit(EXIT_FAILURE);

    fread(&lookup_table[0], sizeof(double), elementNumber, inFile);
    fclose(inFile);

    return lookup_table;
}
    
