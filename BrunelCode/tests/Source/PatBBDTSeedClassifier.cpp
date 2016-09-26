
#include "PatBBDTSeedClassifier.h"
#include <stdlib.h>
#include <stdio.h>


double PatBBDTSeedClassifier::getMvaValue(const std::vector<double>& parametersVector )
{
    auto binIndices = getBinIndices(parametersVector);
    int lookupTableIndex = convertBinIndicesToLookupIndex(binIndices);
    return getBBDTPrediction(lookupTableIndex);
}



PatBBDTSeedClassifier::PatBBDTSeedClassifier( )
{
    initialize();
}

void PatBBDTSeedClassifier::initialize()
{

    m_binsEdgeMap = initBinEdgeMaps();
    m_lookupTable = initLookupTable();
}

std::vector<int> PatBBDTSeedClassifier::getBinIndices(const std::vector<double>& parametersVector)
{
    std::vector<int> binIndicesMap;
    int actualFeature = 0;
    for (const auto& featurePair: m_binsEdgeMap){
        int binNumber = 0;
        for(const auto& binValue : featurePair.second) {
            if (parametersVector[actualFeature] > binValue) {
                binIndicesMap.push_back(binNumber);
                break;
            }
            binNumber++;
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
    const int binPerFeature = 2;

    for (const auto& indice : binIndices){
        index *= binPerFeature+1;
        index += indice;
    }
    return index;
}

double PatBBDTSeedClassifier::getBBDTPrediction(int lookupIndex)
{
    return m_lookupTable[lookupIndex];
}
    
std::vector< std::pair<std::string, std::vector<double> > > PatBBDTSeedClassifier::initBinEdgeMaps()
{
    std::vector< std::pair<std::string, std::vector<double> > >   binMap ={
    	 {"x", {5.0,}},
	 {"y", {5.0,}},

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
    const int elementNumber = 4;

    std::vector<double> lookup_table(elementNumber);
    if (!(inFile = fopen("BBDT_lookuptable_binary.dat", "rb")))
        exit(EXIT_FAILURE);

    fread(&lookup_table[0], sizeof(double), elementNumber, inFile);
    fclose(inFile);

    return lookup_table;
}
    