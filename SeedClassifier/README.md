#Installation python Machine Learning part of the project
To setup the ML part of the  downstream tracking study you need to:  
* Log to the remote computing cluster e.g, lxplus  
 * ``` ssh -L 7000:localhost:6000 username@lxplus.cern.ch ``` 
* Clone the repository   
 * ``` git clone https://github.com/adendek/DownstreamTracking.git  ```
* install all python packages    
  * ``` pip install --user --upgrade -r requirements.txt ``` 
* start the jupyter notebook
  * ``` jupyter notebook --no-browser --port=6000```  
