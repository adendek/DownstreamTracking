########################################################################
from os import environ
import GaudiKernel.SystemOfUnits as Units 
from Gaudi.Configuration import *
#from Hlt.Configuration import *
from Configurables import (GaudiSequencer,
                           DecayTreeTuple,
                           LoKi__Hybrid__TupleTool,
                           DaVinci,
                           FilterDesktop)

from Configurables import LoKi__Hybrid__PlotTool as PlotTool 
from Configurables import LoKi__Hybrid__FilterCriterion as LoKiFilterCriterion
from DecayTreeTuple.Configuration import *

from PhysSelPython.Wrappers import (SelectionSequence, Selection, DataOnDemand)
from Configurables import LoKi__VoidFilter as Filter 
LoKiTool = LoKi__Hybrid__TupleTool( 'LoKiTool')
#
######################################################################################################
# central settings
#
simulation     = False
year           = "2016"
magnetPolarity = "Down"
######################################################################################################
# if you are setting something wrong, it should die here...
if year not in [ "2016" ]:
    raise RuntimeError(year + " is not a valid year")
if magnetPolarity not in ["Up", "Down"]:
    raise RuntimeError(magnetPolarity + " is not a valid magnet polarity")

######################################################################################################
from Configurables import CombineParticles
KsPiPi= CombineParticles("KsPiPi")
KsPiPi.DecayDescriptor =  "KS0 -> pi+ pi-"
KsPiPi.CombinationCut = "ADAMASS('KS0')<100*MeV"
KsPiPi.MotherCut = "(VFASPF(VCHI2/VDOF)<10)"
KsPiPi.DaughtersCuts = { "pi+" : "ALL",
                         "pi-" : "ALL" }
KsPiPi.MotherCut = "(M > 400) & (M < 600) & (BPVVDCHI2 > 100.) & (VFASPF(VCHI2/VDOF) < 10)"
from PhysSelPython.Wrappers import Selection
from StandardParticles import StdNoPIDsDownPions, StdLoosePions
LooseKsPiPi = Selection("SelLooseKsPiPi", 
                        Algorithm = KsPiPi, 
                        RequiredSelections = [StdNoPIDsDownPions ])
                        #RequiredSelections = [StdLoosePions])

from PhysSelPython.Wrappers import SelectionSequence
SeqKsPiPi = SelectionSequence('SeqKsPiPi', TopSelection = LooseKsPiPi)

KsPiPiTuple = DecayTreeTuple("KsPiPiTuple")

# input locations
KsPiPiTuple.Inputs = [ LooseKsPiPi.outputLocation() ]
# decay descriptors
KsPiPiTuple.Decay = "KS0 -> ^pi+ ^pi-"
# define the tools and configure them
KsPiPiTuple.ToolList = [
    "TupleToolKinematic"
    ,"TupleToolGeometry"
    ,"TupleToolPid"
    ,"TupleToolANNPID"
    #,"TupleToolTrackInfo"
    ,"TupleToolRecoStats"
    ,"TupleToolTrigger"
    ,"TupleToolPrimaries"
    ]

KsPiPiTuple.addTupleTool("TupleToolTrackInfo/TupleToolTrackInfo")
KsPiPiTuple.TupleToolTrackInfo.Verbose = True

# define the list of triggers that could have fired...

KsPiPiTuple.addTupleTool("LoKi::Hybrid::TupleTool/LoKiTool")
KsPiPiTuple.LoKiTool.Variables = {
    "eta"                     : "ETA",
    "phi"                     : "PHI",
    "LV01"                    : "LV01" }

######################################################################################################
from Configurables import CombineParticles
LambdaPPi = CombineParticles("LambdaPPi")
LambdaPPi.DecayDescriptor =  "[Lambda0 -> p+ pi-]cc"
LambdaPPi.CombinationCut = "ADAMASS('Lambda0')<100*MeV"
LambdaPPi.DaughtersCuts = { "p+" : "ALL",
                            "pi-" : "ALL" }
LambdaPPi.MotherCut = "(ADMASS('Lambda0')<100*MeV) & (BPVVDCHI2 > 100.) & (VFASPF(VCHI2/VDOF) < 10)"
from PhysSelPython.Wrappers import Selection
from StandardParticles import StdNoPIDsDownPions, StdNoPIDsDownProtons
LooseLambdaPPi = Selection("SelLooseLambdaPPi", 
                          Algorithm = LambdaPPi, 
                          RequiredSelections = [StdNoPIDsDownPions, StdNoPIDsDownProtons])

SeqLambdaPPi = SelectionSequence('SeqLambdaPPi', TopSelection = LooseLambdaPPi)

LambdaPPiTuple = DecayTreeTuple("LambdaPPiTuple")

# input locations
LambdaPPiTuple.Inputs = [ LooseLambdaPPi.outputLocation() ]
# decay descriptors
LambdaPPiTuple.Decay =  "[Lambda0 -> ^p+ ^pi-]CC"
# define the tools and configure them
LambdaPPiTuple.ToolList = [
    "TupleToolKinematic"
    ,"TupleToolGeometry"
    ,"TupleToolPid"
    ,"TupleToolANNPID"
    ,"TupleToolTrackInfo"
    ,"TupleToolRecoStats"
    ,"TupleToolTrigger"
    ,"TupleToolPrimaries"
    ]

# define the list of triggers that could have fired...

LambdaPPiTuple.addTupleTool("LoKi::Hybrid::TupleTool/LoKiTool")
LambdaPPiTuple.LoKiTool.Variables = {
    "eta"                     : "ETA",
    "phi"                     : "PHI",
    "LV01"                    : "LV01" }

#BJpsiKS.addBranches({  # remove all "^" except where needed.
#        "Jpsi"       : "^(J/psi(1S) -> mu- mu+)",
#        "muplus"     : "J/psi -> mu- ^mu+",
#        "muminus"    : "J/psi -> ^mu- mu+"
#        })

### Bplus tools
### Jpsi tools
#BJpsiKS.Jpsi.addTupleTool("TupleToolDownEff")

################################################################
################################################################
Seq1 = GaudiSequencer("Seq1")
Seq1.Members += [ SeqKsPiPi.sequence(), KsPiPiTuple ]
Seq1.Members += [ SeqLambdaPPi.sequence(), LambdaPPiTuple ]
Seq1.ShortCircuit = False
Seq1.ModeOR = True
# ######################################################################################################
DaVinci().MainOptions = ""
DaVinci().UserAlgorithms = [Seq1]
########################################################################
DaVinci().EvtMax    = -1
DaVinci().DataType  = "2016"
DaVinci().PrintFreq = 100
DaVinci().Lumi      = False

DaVinci().InputType = "DST"

if simulation is True:
    DaVinci().Simulation = True
    DaVinci().Lumi       = False
    DaVinci().InputType  = "DST"
    DaVinci().TupleFile  = "KsPiPi" + year + magnetPolarity + "MC.root"
    
if simulation is False: 
    #DaVinci().RootInTES = "/Event/Leptonic"
    DaVinci().TupleFile = "KsPiPi" + year + magnetPolarity + ".root"

## db tags
if simulation is True:
    if year is "2016":
        if magnetPolarity is "Down":
            DaVinci().CondDBtag = "sim-20161124-2-vc-md100"
            DaVinci().DDDBtag   = "dddb-20150724"
        if magnetPolarity is "Up":
            DaVinci().CondDBtag = "sim-20161124-2-vc-mu100"
            DaVinci().DDDBtag   = "dddb-20150724"
            
    #if year is "2012":
    #    if magnetPolarity is "Down":
    #        DaVinci().CondDBtag = "sim-20130522-1-vc-md100"
    #        DaVinci().DDDBtag   = "dddb-20130929-1"
    #    if magnetPolarity is "Up":
    #        DaVinci().CondDBtag = "sim-20130522-1-vc-mu100"
    #        DaVinci().DDDBtag   = "dddb-20130929"

### mag polarity does not matter
#if simulation is False:
#    if year is "2011":
#        DaVinci().CondDBtag = "cond-20141107"
#        DaVinci().DDDBtag   = "dddb-20130929"#

#    if year is "2012":
#        DaVinci().CondDBtag = "cond-20141107"
#        DaVinci().DDDBtag   = "dddb-20130929-1"


####################################################
# local files for testing go here
####################################################
from Gaudi.Configuration import *
from GaudiConf import IOHelper

IOHelper('ROOT').inputFiles(['/eos/lhcb/user/d/decianm/minbiasMLPPatLLT_1.dst',
                             '/eos/lhcb/user/d/decianm/minbiasMLPPatLLT_2.dst',
                             '/eos/lhcb/user/d/decianm/minbiasMLPPatLLT_3.dst'])


