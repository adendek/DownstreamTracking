from GaudiKernel.ProcessJobOptions import importOptions
from Gaudi.Configuration import *
from Configurables import Brunel , LHCbApp , DDDBConf
from Configurables import LoKi__Hybrid__MCParticleSelector as LoKiMCSelector

Brunel().InputType   = "DST" 
Brunel().WithMC      = False
Brunel().Simulation  = False
Brunel().OutputType  = "DST"
Brunel().DataType    = "2016"
Brunel().EvtMax      = -1
Brunel().PrintFreq   = 1
Brunel().DatasetName = "test"
Brunel().SplitRawEventInput = 4.2

def doItBetter():

    from Configurables import PatLongLivedTracking
            
    from Configurables import OutputStream
    OutputStream("DstWriter").ItemList=['/Event/Rec/Header#1', '/Event/Rec/Status#1', '/Event/Rec/Summary#1', '/Event/pRec/Track/Best#1', '/Event/pRec/Vertex/Primary#1', '/Event/pRec/Track/FittedHLT1VeloTracks#1', '/Event/pRec/Rich/PIDs#1', '/Event/pRec/Muon/MuonPID#1', '/Event/pRec/Calo/Electrons#1', '/Event/pRec/Calo/Photons#1', '/Event/pRec/Calo/MergedPi0s#1', '/Event/pRec/Calo/SplitPhotons#1', '/Event/pRec/ProtoP/Charged#1', '/Event/pRec/ProtoP/Neutrals#1', '/Event/pRec/Vertex/V0#1', '/Event/pRec/Track/Muon#1', '/Event/Calo/RawEvent#1', '/Event/HC/RawEvent#1', '/Event/Tracker/RawEvent#1', '/Event/Velo/RawEvent#1', '/Event/Muon/RawEvent#1', '/Event/Rich/RawEvent#1', '/Event/Trigger/RawEvent#1']
    #print "##################################"
    #print OutputStream("DstWriter").Output
    #print "##################################"
    OutputStream("DstWriter").Output = "DATAFILE='PFN:/eos/lhcb/user/d/decianm/minbiasPatLLT.dst' SVC='RootCnvSvc' OPT='REC'"

    GaudiSequencer("RawEventSplitSeq").Members = []
    
appendPostConfigAction( doItBetter )
from Gaudi.Configuration import *
from GaudiConf import IOHelper
IOHelper('ROOT').inputFiles([
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00002035_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00002208_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00001952_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00003120_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00003238_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00003408_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00003408_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00003384_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00003492_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00003312_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00003660_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00003962_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00004817_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00004866_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00005001_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00005031_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00005078_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00005139_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00005120_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00005333_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00005573_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00005780_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00006805_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00008441_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00008473_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00008696_1.minibias.dst',
    '/eos/lhcb/grid/prod/lhcb/LHCb/Collision16/MINIBIAS.DST/00054259/0000/00054259_00009623_1.minibias.dst'
    ])


