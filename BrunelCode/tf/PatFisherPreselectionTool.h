#ifndef PATFISHERPRESELECTIONTOOL
#define PATFISHERPRESELECTIONTOOL 1

#include "PatKernel/IPatMvaClassifier.h"
#include "GaudiAlg/GaudiTool.h"
#include <string>
#include <vector>


/** @class PatFisherPreselectionTool PatFisherPreselectionTool.h
 *
 *
 *  @author Adam Dendek
 *  @date   2016-03-15
 */
class PatFisherPreselectionTool : public GaudiTool, virtual public IPatMvaClassifier {
public:
  /// Standard constructor
  PatFisherPreselectionTool( const std::string& type,
                       const std::string& name,
                       const IInterface* parent);

  virtual ~PatFisherPreselectionTool( ){};

  virtual StatusCode initialize();
  virtual double getMvaValue(const std::vector<double>& parametersVector );

private:
  int m_nParameters;
  std::vector<std::string> m_parametersName;
  double                  m_fishConst;
  std::vector<double>    m_fishCoefficients;

};
#endif // PATDEBUGTTTRUTHTOOL_H
