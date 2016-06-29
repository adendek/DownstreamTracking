#ifndef PATMPLFINALSELECTIONTOOL
#define PATMPLFINALSELECTIONTOOL 1

#include "PatKernel/IPatMvaClassifier.h"
#include "GaudiAlg/GaudiTool.h"
#include <string>
#include <vector>
#include "ReadMLP_ReLu.h"


/** @class PatMPLFinalSelectionTool PatMPLFinalSelectionTool.h
 *
 *
 *  @author Adam Dendek
 *  @date   2016-03-15
 */
class PatMPLFinalSelectionTool : public GaudiTool, virtual public IPatMvaClassifier {
public:
  /// Standard constructor
  PatMPLFinalSelectionTool( const std::string& type,
                       const std::string& name,
                       const IInterface* parent);

  virtual ~PatMPLFinalSelectionTool(){};

  virtual StatusCode initialize();
  virtual double getMvaValue(const std::vector<double>& parametersVector );

private:
  ReadMLP_ReLu* m_mvaClassifier;

};
#endif // PATMPLFINALSELECTIONTOOL
