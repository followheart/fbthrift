/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/compiler/test/fixtures/constants/gen-cpp2/module_types.h"
#include <thrift/lib/cpp/TApplicationException.h>
#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/server/Cpp2ConnContext.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
namespace cpp2 {

} // cpp2
namespace std {

} // std
namespace apache { namespace thrift {

}} // apache::thrift
namespace cpp2 {

} // cpp2
namespace std {

} // std
namespace apache { namespace thrift {

}} // apache::thrift
namespace cpp2 {

template <class Protocol_>
uint32_t Internship::read(Protocol_* iprot) {
  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::TProtocolException;

  bool isset_weeks = false;

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    if (fid == std::numeric_limits<int16_t>::min()) {
      if (fname == "weeks") {
        fid = 1;
        ftype = apache::thrift::protocol::T_I32;
      }
      else if (fname == "title") {
        fid = 2;
        ftype = apache::thrift::protocol::T_STRING;
      }
      else if (fname == "employer") {
        fid = 3;
        ftype = apache::thrift::protocol::T_I32;
      }
    }
    switch (fid) {
      case 1:
      {
        if (ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->weeks);
          isset_weeks = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      }
      case 2:
      {
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->title);
          this->__isset.title = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      }
      case 3:
      {
        if (ftype == apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->employer = ( ::cpp2::Company)ecast0;
          this->__isset.employer = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      }
      default:
      {
        xfer += iprot->skip(ftype);
        break;
      }
    }
    xfer += iprot->readFieldEnd();
  }
  xfer += iprot->readStructEnd();

  if (!isset_weeks) {
    throw TProtocolException(TProtocolException::MISSING_REQUIRED_FIELD, "Required field 'weeks' was not found in serialized data! Struct: Internship");
  }
  return xfer;
}

template <class Protocol_>
uint32_t Internship::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Internship");
  xfer += prot_->serializedFieldSize("weeks", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->serializedSizeI32(this->weeks);
  xfer += prot_->serializedFieldSize("title", apache::thrift::protocol::T_STRING, 2);
  xfer += prot_->serializedSizeString(this->title);
  if (this->__isset.employer) {
    xfer += prot_->serializedFieldSize("employer", apache::thrift::protocol::T_I32, 3);
    xfer += prot_->serializedSizeI32((int32_t)this->employer);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Internship::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Internship");
  xfer += prot_->serializedFieldSize("weeks", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->serializedSizeI32(this->weeks);
  xfer += prot_->serializedFieldSize("title", apache::thrift::protocol::T_STRING, 2);
  xfer += prot_->serializedSizeString(this->title);
  if (this->__isset.employer) {
    xfer += prot_->serializedFieldSize("employer", apache::thrift::protocol::T_I32, 3);
    xfer += prot_->serializedSizeI32((int32_t)this->employer);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Internship::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("Internship");
  xfer += prot_->writeFieldBegin("weeks", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->writeI32(this->weeks);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("title", apache::thrift::protocol::T_STRING, 2);
  xfer += prot_->writeString(this->title);
  xfer += prot_->writeFieldEnd();
  if (this->__isset.employer) {
    xfer += prot_->writeFieldBegin("employer", apache::thrift::protocol::T_I32, 3);
    xfer += prot_->writeI32((int32_t)this->employer);
    xfer += prot_->writeFieldEnd();
  }
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
namespace cpp2 {

template <class Protocol_>
uint32_t UnEnumStruct::read(Protocol_* iprot) {
  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::TProtocolException;


  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    if (fid == std::numeric_limits<int16_t>::min()) {
      if (fname == "city") {
        fid = 1;
        ftype = apache::thrift::protocol::T_I32;
      }
    }
    switch (fid) {
      case 1:
      {
        if (ftype == apache::thrift::protocol::T_I32) {
          int32_t ecast1;
          xfer += iprot->readI32(ecast1);
          this->city = ( ::cpp2::City)ecast1;
          this->__isset.city = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      }
      default:
      {
        xfer += iprot->skip(ftype);
        break;
      }
    }
    xfer += iprot->readFieldEnd();
  }
  xfer += iprot->readStructEnd();

  return xfer;
}

template <class Protocol_>
uint32_t UnEnumStruct::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("UnEnumStruct");
  xfer += prot_->serializedFieldSize("city", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->serializedSizeI32((int32_t)this->city);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t UnEnumStruct::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("UnEnumStruct");
  xfer += prot_->serializedFieldSize("city", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->serializedSizeI32((int32_t)this->city);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t UnEnumStruct::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("UnEnumStruct");
  xfer += prot_->writeFieldBegin("city", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->writeI32((int32_t)this->city);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
namespace cpp2 {

template <class Protocol_>
uint32_t Range::read(Protocol_* iprot) {
  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::TProtocolException;

  bool isset_min = false;
  bool isset_max = false;

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    if (fid == std::numeric_limits<int16_t>::min()) {
      if (fname == "min") {
        fid = 1;
        ftype = apache::thrift::protocol::T_I32;
      }
      else if (fname == "max") {
        fid = 2;
        ftype = apache::thrift::protocol::T_I32;
      }
    }
    switch (fid) {
      case 1:
      {
        if (ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->min);
          isset_min = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      }
      case 2:
      {
        if (ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->max);
          isset_max = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      }
      default:
      {
        xfer += iprot->skip(ftype);
        break;
      }
    }
    xfer += iprot->readFieldEnd();
  }
  xfer += iprot->readStructEnd();

  if (!isset_min) {
    throw TProtocolException(TProtocolException::MISSING_REQUIRED_FIELD, "Required field 'min' was not found in serialized data! Struct: Range");
  }
  if (!isset_max) {
    throw TProtocolException(TProtocolException::MISSING_REQUIRED_FIELD, "Required field 'max' was not found in serialized data! Struct: Range");
  }
  return xfer;
}

template <class Protocol_>
uint32_t Range::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Range");
  xfer += prot_->serializedFieldSize("min", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->serializedSizeI32(this->min);
  xfer += prot_->serializedFieldSize("max", apache::thrift::protocol::T_I32, 2);
  xfer += prot_->serializedSizeI32(this->max);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Range::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Range");
  xfer += prot_->serializedFieldSize("min", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->serializedSizeI32(this->min);
  xfer += prot_->serializedFieldSize("max", apache::thrift::protocol::T_I32, 2);
  xfer += prot_->serializedSizeI32(this->max);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Range::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("Range");
  xfer += prot_->writeFieldBegin("min", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->writeI32(this->min);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("max", apache::thrift::protocol::T_I32, 2);
  xfer += prot_->writeI32(this->max);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
namespace cpp2 {

} // cpp2