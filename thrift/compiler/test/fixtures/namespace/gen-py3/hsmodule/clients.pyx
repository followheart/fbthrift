#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
from libcpp.memory cimport shared_ptr, make_shared, unique_ptr, make_unique
from libcpp.string cimport string
from libcpp cimport bool as cbool
from cpython cimport bool as pbool
from libc.stdint cimport int8_t, int16_t, int32_t, int64_t
from libcpp.vector cimport vector as vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap
from cython.operator cimport dereference as deref, typeid
from cpython.ref cimport PyObject
from thrift.py3.client cimport py3_get_exception, cRequestChannel_ptr, makeClientWrapper
from folly cimport cFollyTry, cFollyUnit, c_unit
from libcpp.typeinfo cimport type_info
import thrift.py3.types
cimport thrift.py3.types
import thrift.py3.client
cimport thrift.py3.client
from folly.futures cimport bridgeFutureWith
from folly.executor cimport get_executor

import asyncio
import sys
import traceback

cimport hsmodule.types
import hsmodule.types

from hsmodule.clients_wrapper cimport cHsTestServiceAsyncClient, cHsTestServiceClientWrapper


cdef void HsTestService_init_callback(
    cFollyTry[int64_t]&& result,
    PyObject* future
):
    cdef object pyfuture = <object> future
    cdef int64_t citem
    if result.hasException():
        try:
            result.exception().throwException()
        except Exception as ex:
            pyfuture.set_exception(ex)
    else:
        citem = result.value();
        pyfuture.set_result(citem)


cdef class HsTestService(thrift.py3.client.Client):

    def __cinit__(HsTestService self):
        loop = asyncio.get_event_loop()
        self._connect_future = loop.create_future()
        self._executor = get_executor()

    cdef const type_info* _typeid(HsTestService self):
        return &typeid(cHsTestServiceAsyncClient)

    @staticmethod
    cdef _hsmodule_HsTestService_set_client(HsTestService inst, shared_ptr[cHsTestServiceClientWrapper] c_obj):
        """So the class hierarchy talks to the correct pointer type"""
        inst._hsmodule_HsTestService_client = c_obj

    cdef _hsmodule_HsTestService_reset_client(HsTestService self):
        """So the class hierarchy resets the shared pointer up the chain"""
        self._hsmodule_HsTestService_client.reset()

    def __dealloc__(HsTestService self):
        if self._cRequestChannel or self._hsmodule_HsTestService_client:
            print('client was not cleaned up, use the context manager', file=sys.stderr)

    async def __aenter__(HsTestService self):
        await self._connect_future
        if self._cRequestChannel:
            HsTestService._hsmodule_HsTestService_set_client(
                self,
                makeClientWrapper[cHsTestServiceAsyncClient, cHsTestServiceClientWrapper](
                    self._cRequestChannel
                ),
            )
            self._cRequestChannel.reset()
        else:
            raise asyncio.InvalidStateError('Client context has been used already')
        return self

    async def __aexit__(HsTestService self, *exc):
        self._check_connect_future()
        loop = asyncio.get_event_loop()
        future = loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._hsmodule_HsTestService_client).disconnect(),
            closed_HsTestService_py3_client_callback,
            <PyObject *>future
        )
        # To break any future usage of this client
        badfuture = loop.create_future()
        badfuture.set_exception(asyncio.InvalidStateError('Client Out of Context'))
        badfuture.exception()
        self._connect_future = badfuture
        await future
        self._hsmodule_HsTestService_reset_client()

    async def init(
            HsTestService self,
            arg_int1):
        self._check_connect_future()
        loop = asyncio.get_event_loop()
        future = loop.create_future()
        bridgeFutureWith[int64_t](
            self._executor,
            deref(self._hsmodule_HsTestService_client).init(
                arg_int1,
            ),
            HsTestService_init_callback,
            <PyObject *> future
        )
        return await future



cdef void closed_HsTestService_py3_client_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* fut,
):
    cdef object pyfuture = <object> fut
    pyfuture.set_result(None)