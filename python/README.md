This is a python / Cython file sum using CityHash.  

To install either type ```make``` and ```make clean``` to install type ```python setup.py install```.  

example usage:  
```
from citysum import CitySum

cs = CitySum('/data/metocean/gfs20170124_18z.nc')
cs.prints()

print cs.as_int()

```
