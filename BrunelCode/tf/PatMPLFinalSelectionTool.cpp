// local
#include "PatMPLFinalSelectionTool.h"

// Declaration of the Tool Factory
DECLARE_TOOL_FACTORY( PatMPLFinalSelectionTool )

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
using namespace std;

PatMPLFinalSelectionTool::PatMPLFinalSelectionTool( const std::string& type,
                                          const std::string& name,
                                          const IInterface* parent )
  : GaudiTool ( type, name , parent )
{
  declareInterface<IPatMvaClassifier>(this);
}


StatusCode PatMPLFinalSelectionTool::initialize()
{
    StatusCode sc = GaudiTool::initialize();
    if (sc.isFailure()) return Error("Failed to initialize", sc);

    vector<string> inputParameters  = { "track_chi2", "abs(track_displX)", "abs(track_displY)",
                                       "track_nbHit", "abs(track_p)", "abs(track_tx)",
                                       "abs(track_ty)", "seed_chi2PerDoF", "seed_pt",
                                       "seed_nLHCbIDs", "seed_nbIT" };
   m_mvaClassifier = new ReadMLP_ReLu(inputParameters);
   return sc;
}


double PatMPLFinalSelectionTool::getMvaValue( const std::vector<double>& inputValues )
{
	return m_mvaClassifier->GetMvaValue(inputValues);
}

