# Seeed TMG3993 Library  [![Build Status](https://travis-ci.com/Seeed-Studio/Seeed_TMG3993.svg?branch=master)](https://travis-ci.com/Seeed-Studio/Seeed_TMG3993)

This is the Arduino library for Seeed's TMG3993 based products. For now, it's Grove - Light&Gesture&Color&Proximity Sensor.

TODO: fix this image when the product is launched.

[![product_image](url)](http://www.seeedstudio.com)


## Usage Tips

The gesture functionality is not supported yet, since this functionality needs algorithms provided by AMS. We will update this library as soon as we get the support from AMS.


## Examples

### Example1

This example reads the raw (uint16_t) data of the proximity sensor.

### Example2

This example is also used to detect proximity, but in interrupt way. Two thresholds need to be configured - low and high. Any proximity value which is inside this range will trigger nothing, but the value outside this range will trigger events. In detail, when the proximity sensor values are below the `low` threshold over 10 times, a `proximity removed` event will be emitted, when the proximity sensor values are higher than the `high` threshold over 10 times, a `proximity detected` event will be emitted. The `10 times` here can be configured via `setInterruptPersistenceReg` (see `setupRecommendedConfigForProximity` for an example).

### Example3

This example reads the R, G, B, C sensor values. `C` is defined as `the non-color filtered clear channel` in the chip's datasheet. This examples also calculates Lux value for the ambient light based on the equation in the `Application Note` of this sensor.

TODO: fix this url when the wiki is available.

For more information, please refer to [wiki page](<wiki url>).

----

This software is written by Jack Shao for seeed studio and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>


[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/grove-light-gesture-color-proximity-sensor)](https://github.com/igrigorik/ga-beacon)







