## Brunel installation instruction

To install the latest version of Tracking you need to log into lxpus and them type:

```bash
lb-dev Brunel v52r0
cd BrunelDev_v52r0/
git lb-use Rec
git lb-checkout Rec/v21r0 Tf/PatAlgorithms 
git lb-checkout Rec/v21r0 Tf/PatKernel 
git lb-checkout Rec/v21r0 Tr/TrackMCTools 
mkdir jobs
```

Then you need to copy all source files from [this](https://github.com/adendek/DownstreamTracking/tree/master/BrunelCode) directory into the appropriate folder before compilation. 

The exception is folder [tests](https://github.com/adendek/DownstreamTracking/tree/master/BrunelCode/tests). It contains 
set of Unit Tests, based on gtest, to check correctness of evaluation of the trained classifier. It is not a part of a Brunel project.

Make sure you put the source files into correct directory! 
The content of directory [BrunelCode/Tr/PatAlgorithm](BrunelCode/Tr/PatAlgorithm) 
have to be moved into **BrunelDev_v52r0/Tf/PatAlgorithms** and so on.

## Now you need the compile the project
```bash
cd BrunelDev_v52r0/ 
make -j10
```

In case of compilation error  of please open new [issue](https://github.com/adendek/DownstreamTracking/issues)!  

## Run PatLongLived tracking 

Now you can run PatLongLived tracking algorithm. 

```bash
cd  jobs
../run gaudirun.py ../options/<options> data/<dataset> | tee <log_file>
```
In case of internet connection problems instead of above command you can use :

```bash
nohup ../run gaudirun.py ../options/<options> data/<dataset> >> <log_file> & 
```

You can monitor progress by typing

```bash
tail -f <logfile>
```


If you don't want to capture the logs you can remove <logfile>. 

The Brunel should create two root files. One of them is the training ntuple. 

 
## Attention Workaround!
 You need to manually change line PatBBDTSeedClassifier.cpp:127 to set correct location of the **BBDT_tuple.csv**  
