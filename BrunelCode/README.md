## Brunel installation instruction

To install the latest version of Tracking you need to log into lxpus and them type:

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

Then you need to copy all source files from this directory into into the appropriate folder before compilation.  
Make sure you put the source files into correct directory! 
The content of directory [BrunelCode/Tr/PatAlgorithm](BrunelCode/Tr/PatAlgorithm) 
have to be moved into **BrunelDev_v51r1/Tf/PatAlgorithms** and so on.

## Now you need to install the compile the project
```bash
cd BrunelDev_v51r1/ 
make -j10
```

In case of compilation error you need to remove uncompilable files. If error occurred during compilation of PatDownstreamTracking or related files please open the [issue](https://github.com/adendek/DownstreamTracking/issues)!  

## Run the Brunel 

Now you can run the Brunel. 

```bash
cd  Rec/Brunel/jobs
gaudirun.py ../options/Brunel_2015.py ../data/Run2-XDIGI.py | tee Brunel.log
```
If you don't want to capture the logs you can remove the pipe from the last command. 

The Brunel should create two files. One of them is the training ntuple. 

 
## Attention Workaround!
 You need to manually change line PatBBDTSeedClassifier.cpp:127 to set correct location of the **BBDT_lookuptable_binary.dat** 
 
 
### The directory test contain set of Unit Tests to check correctness of evaluation of the trained classifier
 
