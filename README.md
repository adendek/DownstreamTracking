# LHCb Downstream Tracking study  
This repository contains source code of study on improvement of LHCb Downstream Tracking algorithm.  
Detailed description of the problem can be find in the file [Baseline](https://github.com/adendek/DownstreamTracking/blob/master/SeedClasifier/Baseline.ipynb)
It is **highly recommended** to start reading from mentioned file. 

##Installation python Machine Learing part of the project
To setup the ML part of the  downstream tracking study you need to:  
* Log to the remote computing cluster eg lxplus  
 * ``` ssh -L 7000:localhost:6000 username@lxplus.cern.ch ``` 
* Clone the repository   
 * ``` git clone https://github.com/adendek/DownstreamTracking.git  ```
* install all python packages    
  * ``` pip install --user --upgrade -r requirements.txt ``` 
* Start the jupyter   
  * ``` jupyter notebook --no-browser --port=6000```  
