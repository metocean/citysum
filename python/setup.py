from distutils.core import setup, Extension
from Cython.Build import cythonize

ext = Extension(name="citysum",
                sources=["city.c", "citysum_c.c", "citysum.pyx"])

setup(ext_modules=cythonize(ext),
      name='citysum',
      version='0.0.1')
