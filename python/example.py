from citysum import CitySum

cs = CitySum('/data/metocean/gfs20170124_18z.nc')
cs.prints()

print cs.as_int()
