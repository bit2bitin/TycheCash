// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <boost/serialization/vector.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/variant.hpp>
#include <boost/serialization/set.hpp>
#include <boost/serialization/map.hpp>
#include <boost/foreach.hpp>
#include <boost/serialization/is_bitwise_serializable.hpp>
#include "TycheCashCore/TycheCashBasic.h"
#include "UnorderedContainersBoostSerialization.h"
#include "crypto/crypto.h"

//namespace TycheCash {
namespace boost
{
  namespace serialization
  {

  //---------------------------------------------------
  template <class Archive>
  inline void serialize(Archive &a, Crypto::PublicKey &x, const boost::serialization::version_type ver)
  {
    a & reinterpret_cast<char (&)[sizeof(Crypto::PublicKey)]>(x);
  }
  template <class Archive>
  inline void serialize(Archive &a, Crypto::SecretKey &x, const boost::serialization::version_type ver)
  {
    a & reinterpret_cast<char (&)[sizeof(Crypto::SecretKey)]>(x);
  }
  template <class Archive>
  inline void serialize(Archive &a, Crypto::KeyDerivation &x, const boost::serialization::version_type ver)
  {
    a & reinterpret_cast<char (&)[sizeof(Crypto::KeyDerivation)]>(x);
  }
  template <class Archive>
  inline void serialize(Archive &a, Crypto::KeyImage &x, const boost::serialization::version_type ver)
  {
    a & reinterpret_cast<char (&)[sizeof(Crypto::KeyImage)]>(x);
  }

  template <class Archive>
  inline void serialize(Archive &a, Crypto::Signature &x, const boost::serialization::version_type ver)
  {
    a & reinterpret_cast<char (&)[sizeof(Crypto::Signature)]>(x);
  }
  template <class Archive>
  inline void serialize(Archive &a, Crypto::Hash &x, const boost::serialization::version_type ver)
  {
    a & reinterpret_cast<char (&)[sizeof(Crypto::Hash)]>(x);
  }
  
  template <class Archive> void serialize(Archive& archive, TycheCash::MultisignatureInput &output, unsigned int version) {
    archive & output.amount;
    archive & output.signatureCount;
    archive & output.outputIndex;
  }

  template <class Archive> void serialize(Archive& archive, TycheCash::MultisignatureOutput &output, unsigned int version) {
    archive & output.keys;
    archive & output.requiredSignatureCount;
  }

  template <class Archive>
  inline void serialize(Archive &a, TycheCash::KeyOutput &x, const boost::serialization::version_type ver)
  {
    a & x.key;
  }

  template <class Archive>
  inline void serialize(Archive &a, TycheCash::BaseInput &x, const boost::serialization::version_type ver)
  {
    a & x.blockIndex;
  }

  template <class Archive>
  inline void serialize(Archive &a, TycheCash::KeyInput &x, const boost::serialization::version_type ver)
  {
    a & x.amount;
    a & x.outputIndexes;
    a & x.keyImage;
  }

  template <class Archive>
  inline void serialize(Archive &a, TycheCash::TransactionOutput &x, const boost::serialization::version_type ver)
  {
    a & x.amount;
    a & x.target;
  }


  template <class Archive>
  inline void serialize(Archive &a, TycheCash::Transaction &x, const boost::serialization::version_type ver)
  {
    a & x.version;
    a & x.unlockTime;
    a & x.inputs;
    a & x.outputs;
    a & x.extra;
    a & x.signatures;
  }


  template <class Archive>
  inline void serialize(Archive &a, TycheCash::Block &b, const boost::serialization::version_type ver)
  {
    a & b.majorVersion;
    a & b.minorVersion;
    a & b.timestamp;
    a & b.previousBlockHash;
    a & b.nonce;
    //------------------
    a & b.baseTransaction;
    a & b.transactionHashes;
  }
}
}

//}
