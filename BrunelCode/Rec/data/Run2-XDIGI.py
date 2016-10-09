#-- GAUDI jobOptions generated on Thu Jan  8 15:22:37 2015
#-- Contains event types : 
#--   10000000 - 27 files - 53343 events - 87.23 GBytes


#--  Extra information about the data processing phases:


#--  Processing Pass Step-126924 

#--  StepId : 126924 
#--  StepName : Digi13 for 2015 - 25ns 
#--  ApplicationName : Boole 
#--  ApplicationVersion : v29r0 
#--  OptionFiles : $APPCONFIGOPTS/Boole/Default.py;$APPCONFIGOPTS/Boole/EnableSpillover.py;$APPCONFIGOPTS/Boole/xdigi.py;$APPCONFIGOPTS/Boole/DataType-2012.py;$APPCONFIGOPTS/Boole/Boole-SiG4EnergyDeposit.py;$APPCONFIGOPTS/Persistency/Compression-ZLIB-1.py 
#--  DDDB : fromPreviousStep 
#--  CONDDB : fromPreviousStep 
#--  ExtraPackages : AppConfig.v3r200 
#--  Visible : N 


#--  Processing Pass Step-126922 

#--  StepId : 126922 
#--  StepName : Nominal 2015 - MD - Nu1.6 (Lumi 4 at 25ns) - 25ns spillover - Pythia8 
#--  ApplicationName : Gauss 
#--  ApplicationVersion : v47r0 
#--  OptionFiles : $APPCONFIGOPTS/Gauss/Beam6500GeV-md100-nu1.6.py;$APPCONFIGOPTS/Gauss/EnableSpillover-25ns.py;$APPCONFIGOPTS/Gauss/DataType-2015.py;$APPCONFIGOPTS/Gauss/RICHRandomHits.py;$DECFILESROOT/options/@{eventType}.py;$LBPYTHIA8ROOT/options/Pythia8.py;$APPCONFIGOPTS/Gauss/G4PL_FTFP_BERT_EmNoCuts.py;$APPCONFIGOPTS/Persistency/Compression-ZLIB-1.py 
#--  DDDB : dddb-20140729 
#--  CONDDB : sim-20140730-vc-md100 
#--  ExtraPackages : AppConfig.v3r200;DecFiles.v27r33 
#--  Visible : Y 

from Gaudi.Configuration import * 
from GaudiConf import IOHelper
IOHelper('ROOT').inputFiles([
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000023_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000004_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000005_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000007_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000009_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000010_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000011_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000012_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000013_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000016_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000017_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000018_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000020_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000022_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000023_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000026_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000027_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000001_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000003_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000006_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000008_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000015_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000019_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000021_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000024_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000025_1.xdigi',
'LFN:/lhcb/MC/Dev/XDIGI/00040581/0000/00040581_00000028_1.xdigi'
], clear=True)
FileCatalog().Catalogs = [ 'xmlcatalog_file:data/Run2-XDIGI.xml' ]
