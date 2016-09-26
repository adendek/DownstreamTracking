## Brunel installation instruction

To install new version of Tracking you need to log into lxpus and them type:

```bash
lb-dev Brunel v51r1
cd BrunelDev_v51r1/
git lb-use Rec
git lb-checkout Rec/2016-patches Tf/PatAlgorithms 
git lb-checkout Rec/2016-patches Tf/PatKernel 
git lb-checkout Rec/2016-patches Tr/TrackMCTools 
git lb-use Brunel
git lb-checkout Brunel/2016-patches  Rec/Brunel
```

Then you need to copy all sources files from this directory into your Brunel once. 
Make sure you put the source files into correct directory. 
The content of directory [BrunelCode/Tr/PatAlgorithm](BrunelCode/Tr/PatAlgorithm) 
have to be moved into **BrunelDev_v51r1/Tf/PatAlgorithms** and so one.
 
## Attention Workaround!
 You need to manualy change line PatBBDTSeedClassifier.cpp:127 to set correct location of the **BBDT_lookuptable_binary.dat** 
 I have no idea how to export environmental variable via lb-dev and CMake.  
 
 
### The directory test contain set of Unit Tests to check correctness of evaluation of the trained classifier
 
