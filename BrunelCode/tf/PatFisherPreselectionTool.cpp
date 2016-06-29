// local
#include "PatFisherPreselectionTool.h"

// Declaration of the Tool Factory
DECLARE_TOOL_FACTORY( PatFisherPreselectionTool )

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
PatFisherPreselectionTool::PatFisherPreselectionTool( const std::string& type,
                                          const std::string& name,
                                          const IInterface* parent )
  : GaudiTool ( type, name , parent )
{
  declareInterface<IPatMvaClassifier>(this);
}


StatusCode PatFisherPreselectionTool::initialize()
{
    StatusCode sc = GaudiTool::initialize();
    if (sc.isFailure()) return Error("Failed to initialize", sc);
  m_nParameters = 7;
  m_parametersName= { "seed_chi2PerDoF", "seed_p", "seed_nLayers",
                   "seed_pt", "seed_nLHCbIDs", "seed_nbIT",
                   "abs(seed_ty)" };

  m_fishConst = -2.10444241941;
  m_fishCoefficients = { -0.291515832162 , -3.12088742e-06,  -0.0148087507355,
                         0.000120653859246 ,  0.163667146786 , 0.154560528597,
                         -1.72091945493 };
  info() << "========================================================= "     << endmsg
         <<" fisher constans        = "<<m_fishConst<< endmsg;
           for(int coefficientIt=0;coefficientIt<m_nParameters; coefficientIt++)
               info()<<"variable " << m_parametersName[coefficientIt]
               << " :fisher Coefficient = "<<m_fishCoefficients[coefficientIt]<< endmsg
         <<  "========================================================= "   << endmsg;

  return sc;
}

double PatFisherPreselectionTool::getMvaValue(const std::vector<double>& parametersVector )
{
  double fishVal =  m_fishConst;
  for(int i = 0; i < m_nParameters ; i++)
    fishVal += parametersVector[i]*m_fishCoefficients[i];
  return fishVal;
}
