from libc cimport stdint
from cpython cimport bool
from libc.stdio cimport printf
from libc.string cimport const_char


cdef extern from "citysum_c.h":
    int _citysum "citysum"(const char *filename, stdint.uint64_t *first, stdint.uint64_t *second)


cdef class CitySum(object):

    cdef stdint.uint64_t sum_first;
    cdef stdint.uint64_t sum_second;

    def __cinit__(self, char *filename):
        self.sum_first = 0xc00fee
        self.sum_second = 0xc00fee
        _citysum(filename, &self.sum_first, &self.sum_second)

    def as_int(self):
        return self.sum_first, self.sum_second;

    def prints(self):
        printf("sum: %zx:%zx\n", self.sum_first, self.sum_second)
