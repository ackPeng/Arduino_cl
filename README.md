Grove touch sensor MPR121  [![Build Status](https://travis-ci.com/Seeed-Studio/Seeed_MRP121.svg?branch=master)](https://travis-ci.com/Seeed-Studio/Seeed_MRP121)
=================================  
 


Introduction of sensor
----------------------------  
The MPR121 features an increased internal intelligence plus Freescale’s second generation capacitance detection engine.

***
Usage:
==========  
Download all the source files and open examples/MPR121_demo/MPR121_demo.ino in arduino IDE. Compile and download and run it on a arduino board.

****
Notice:
=========
>1. This example/MPR121_demo/MPR121_demo.ino is just a simple touch/release demo for general use case.
>2. The pin INT on the board is stay high,When the electrode is touched(key is press),trigger a low level,then return to high.
>3. If you want to achieve a more precise control,Set sensor's baseline,threshold.
    Touch condition: Baseline - Electrode filtered data > Touch threshold 
    Release condition: Baseline - Electrode filtered data < Release threshold
    Get more detail from **doc/MPR121_touch_datasheet.pdf** 



***
This software is written by downey  for seeed studio<br>
Email:dao.huang@seeed.cc
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>
