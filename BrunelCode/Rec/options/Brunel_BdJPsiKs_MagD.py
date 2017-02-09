from GaudiKernel.ProcessJobOptions import importOptions
from Gaudi.Configuration import *
from Configurables import Brunel , LHCbApp , DDDBConf
from Configurables import NTupleSvc 

# Brunel Settings
Brunel().EvtMax     = 50000
Brunel().PrintFreq  = 1
Brunel().DataType   = "2015"
Brunel().WithMC     = True 
Brunel().Simulation = True
Brunel().OutputType = "NONE"
Brunel().InputType="DIGI"
#Brunel().InputType="DST"
#Brunel().InputType="XDST"
Brunel().DatasetName = "test"
#Brunel().SplitRawEventInput=4.1
#Brunel().Histograms = "Expert"
#Brunel().SkipEvents = 3000

# DDDB Settings
#from Configurables import CondDB
#CondDB().Upgrade     = True

# New DDDB Settings, 07/09/2013
#LHCbApp().DDDBtag     = "dddb-20130806"
#LHCbApp().CondDBtag   = "sim-20130722-vc-md100"
## New Geometry 
"""
CondDB().AllLocalTagsByDataType=['VP_Compact_MicroChannel+UT','FT_MonoLayer'] 
CondDB.LocalTags = {
   'DDDB' : [
   'VP-CompactMicroChannelOptimize-Local-20130408', 
   'VP-Compact-Local-20130319',
   'VP-UT-Local-NoPuVeto-20121024',
   'UT-Pipe-Upgrade-Local-20120928', 
   'FT-MonoLayer-Local-20130722' 
   ]
   }
"""
#geometry 2-25-14
#LHCbApp().DDDBtag     = "dddb-20131025"
#LHCbApp().CondDBtag   = "sim-20130830-vc-md100"

#LHCbApp().DDDBtag = 'dddb-20131025'
#LHCbApp().CondDBtag = 'sim-20130830-vc-md100'
#CondDB().LoadCALIBDB = 'HLT1'

###CHANGE ME
#Brunel().DDDBtag = 'dddb-20150424'
#Brunel().CondDBtag = 'sim-20140204-vc-md100'

Brunel().DDDBtag = 'dddb-20150724'                                                                                                                                                                                                           
Brunel().CondDBtag = 'sim-20161124-2-vc-mu100'  
###################################

# Tracking Settings
from Configurables import TrackSys
TrackSys().TrackTypes= [ "Velo", "Seeding", "Downstream"] #Choose the track types you want to reconstruct
from Configurables import RecSysConf
#RecSysConf().RecoSequence = ["Decoding","Tr"]# More options: "Vertex","RICH","CALO","MUON","PROTO","SUMMARY"
Brunel().RecoSequence = ["Decoding","VELO", "TrHLT1", "Vertex", "TrHLT2"]

Brunel().Detectors = ['Velo', 'PuVeto', 'TT', 'IT', 'OT',  'Magnet' ]



# MiscSettings
from Configurables import RecMoniConf
RecMoniConf().MoniSequence = [ ]
from Configurables import L0Conf
L0Conf().EnsureKnownTCK=False

#mc linking
#GaudiSequencer("MCLinksTrSeq").Members = []
# from Configurables import MCParticle2MCHitAlg
# TTAssoc = MCParticle2MCHitAlg( "MCP2TTMCHitAlg", MCHitPath = "MC/TT/Hits", OutputData = "/Event/MC/Particles2MCTTHits" )
# ITAssoc = MCParticle2MCHitAlg( "MCP2ITMCHitAlg", MCHitPath = "MC/IT/Hits", OutputData = "/Event/MC/Particles2MCITHits" )
# OTAssoc = MCParticle2MCHitAlg( "MCP2OTMCHitAlg", MCHitPath = "MC/OT/Hits", OutputData = "/Event/MC/Particles2MCOTHits" )


# # tell the Data On Demand Service about them
# DataOnDemandSvc().AlgMap[ "/Event/Link/MC/Particles2MCTTHits" ]    = TTAssoc
# DataOnDemandSvc().AlgMap[ "/Event/Link/MC/Particles2MCOTHits" ]    = OTAssoc
# DataOnDemandSvc().AlgMap[ "/Event/Link/MC/Particles2MCITHits" ]    = ITAssoc
# DataOnDemandSvc().NodeMap[ "/Event/Link" ]    = "DataObject"
# DataOnDemandSvc().NodeMap[ "/Event/Link/MC" ] = "DataObject"

#GaudiSequencer("MCLinksTrSeq").Members = ["PrTrackAssociator"]

from Configurables import PatLongLivedTracking as pllt
pllt().WithDebugTool=True
pllt().ForceMCTrack=False
pllt().TimingMeasurement =  True



ApplicationMgr().ExtSvc +=  [ NTupleSvc() ]
fileName="~/work/tracking_data/my/Brunel_BdJPsiKs_MagD"
#fileName="Brunel_my_fisher_debug_10kev"
tupleName = "FILE1 DATAFILE='" + fileName  + '.root' + "' TYP='ROOT' OPT='NEW'"
NTupleSvc().Output = [ tupleName ]
NTupleSvc().OutputLevel = 1
from Configurables import TrackAssociator
def doIt():
   GaudiSequencer("TrackHLT2SeedPatSeq").Members += [ TrackAssociator("AssocSeed", TracksInContainer = "Rec/Track/Seed") ]
   GaudiSequencer("MCLinksUnpackSeq").Members = []
#   from Configurables import PatChecker
   from Configurables import PrChecker 
   from Configurables import PatLHCbID2MCParticle
   from Configurables import PatCheckerNTuple 
   
   #GaudiSequencer("CheckPatSeq").Members = []

   PatCheckerNTuple().InputTracks="Rec/Track/Downstream"
  
   GaudiSequencer("CheckPatSeq").Members += [ PrChecker("PrChecker", Upgrade = False) ]


   GaudiSequencer("CheckPatSeq").Members += [PatLHCbID2MCParticle(),  PatCheckerNTuple()]

   
appendPostConfigAction(doIt)
