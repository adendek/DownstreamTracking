#ifndef PATMPLFINALSELECTIONTOOL
#define PATMPLFINALSELECTIONTOOL 1

#include "PatKernel/IPatMvaClassifier.h"
#include "GaudiAlg/GaudiTool.h"
#include <string>
#include <vector>


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

  // input variable transformation
  double fMin_1[3][11];
  double fMax_1[3][11];
  void InitTransform_1();
  void Transform_1( std::vector<double> & iv, int sigOrBgd ) const;
  void InitTransform();
  void Transform( std::vector<double> & iv, int sigOrBgd ) const;

  // common member variables
  const char* fClassName;

  const size_t fNvars;
  size_t GetNvar()           const { return fNvars; }
  char   GetType( int ivar ) const { return fType[ivar]; }

  // normalisation of input variables
  const bool fIsNormalised;
  bool IsNormalised() const { return fIsNormalised; }
  double fVmin[11];
  double fVmax[11];
  double NormVariable( double x, double xmin, double xmax ) const {
     // normalise to output range: [-1, 1]
     return 2*(x - xmin)/(xmax - xmin) - 1.0;
  }

  // type of input variable: 'F' or 'I'
  char   fType[11];

  // initialize internal variables
  void buildNetworkStructure();
  double GetMvaValue__( const std::vector<double>& inputValues ) const;

  // private members (method specific)

  double ActivationFnc(double x) const;
  double OutputActivationFnc(double x) const;

  int fLayers;
  int fLayerSize[3];
  double fWeightMatrix0to1[17][12];   // weight matrix from layer 0 to 1
  double fWeightMatrix1to2[1][17];   // weight matrix from layer 1 to 2

  double * fWeights[3];
};
#endif // PATMPLFINALSELECTIONTOOL
