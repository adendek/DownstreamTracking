#ifndef PATKERNEL_IPATMVACLASSIFIER_H
#define PATKERNEL_IPATMVACLASSIFIER_H 1

#include <string>
#include "GaudiKernel/IAlgTool.h"

static const InterfaceID IID_IPatMvaClassifier ( "IPatMvaClassifier", 1, 0 );

/** @class IPatMvaClassifier PatKernel/IPatMvaClassifier.h
 *
 *  @author Adam Dendek
 *  @date   2016-03-17
 */
class IPatMvaClassifier : virtual public IAlgTool {
public:

  // Return the interface ID
  static const InterfaceID& interfaceID() { return IID_IPatMvaClassifier; }

  virtual double getMvaValue(const std::vector<double>& parametersVector ) = 0;
};
#endif //PATKERNEL_IPATMVACLASSIFIER_H
