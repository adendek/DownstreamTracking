// $Id: PatDebugTTTruthTool.h,v 1.4 2008-12-04 09:05:07 cattanem Exp $
#ifndef PATDEBUGTTTRUTHTOOL_H 
#define PATDEBUGTTTRUTHTOOL_H 1

// Include files
// from Gaudi
#include "GaudiAlg/GaudiTupleTool.h"
#include "PatKernel/IPatDebugTTTool.h"
#include <TfKernel/TTStationHitManager.h>
class DeSTDetector;

/** @class PatDebugTTTruthTool PatDebugTTTruthTool.h
 *  
 *
 *  @author Olivier Callot
 *  @date   2007-10-22
 */
class PatDebugTTTruthTool : public GaudiTupleTool, virtual public IPatDebugTTTool {
public: 
  /// Standard constructor
  PatDebugTTTruthTool( const std::string& type, 
                       const std::string& name,
                       const IInterface* parent);

  virtual ~PatDebugTTTruthTool( ); ///< Destructor

  virtual StatusCode initialize(); /// initialize

  virtual void debugTTClusterOnTrack( const LHCb::Track* track, 
                                      const PatTTHits::const_iterator beginCoord,
                                      const PatTTHits::const_iterator endCoord   );
  
  virtual void debugTTCluster( MsgStream& msg, const PatTTHit* hit );

  virtual bool isTrueHit( const LHCb::Track* track, const PatTTHit* hit);

  virtual double fracGoodHits( const LHCb::Track* track, const PatTTHits& hits);
  
  virtual bool isTrueTrack( const LHCb::Track* track, const PatTTHits& hits);

  virtual bool isTrueTrack( const LHCb::Track* track, const Tf::TTStationHitManager<PatTTHit>::HitRange& hits);//AD, overload
  

  virtual bool hasMCParticle(const LHCb::Track* seed); // point 1 from the mail
  virtual bool isDownstreamReconstructible(const LHCb::Track* seed); // point 2
  virtual bool hasMCParticleNotElectron(const LHCb::Track* seed);// point 3
  virtual bool isDownstreamReconstructibleNotElectron(const LHCb::Track* seed); //point 3
  virtual bool isTrueSeed(const LHCb::Track* seed);// point 5

  
  virtual void chi2Tuple( const double p, const double chi2, const unsigned int nHits);

  virtual void seedTuple(const LHCb::Track* trackSeed, double seedClassifierValue);
  virtual void trackTuple( const std::map<std::string, double >  downTrackParameters,  const PatTTHits& trackHits, const LHCb::Track* trackSeed);
  std::map<std::string, bool> getMCTrackInfo(const LHCb::Track* seed) const;

  
  //added by AD 2/1/16 for efficiency vs step

  virtual void initializeSteps(std::vector<std::string> steps);//initialize all steps in the process  

  virtual void recordStepInProcess(std::string step, bool result);//record the result of a step in the process
  
  virtual void resetflags();//reset all flags

  virtual void ForceMCHits(PatTTHits& hits, LHCb::Track* track);//Special. Force only MC matched hits in the track.
  

protected:

private:

  DeSTDetector* m_tracker;
  std::map<std::string,bool> m_flags;

};
#endif // PATDEBUGTTTRUTHTOOL_H
