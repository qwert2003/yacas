
/** \file lispstring.cpp
 *  implementation of the more heavy functions that should not be inlined.
 */

#include "yacas/yacasprivate.h"
#include "yacas/lispstring.h"
#include "yacas/stubs.h"

LispInt LispString::operator==(const LispString& aString) const
{
    return static_cast<const std::string&>(*this) == static_cast<const std::string&>(aString);
}

LispStringSmartPtr& LispStringSmartPtr::operator=(const LispString* aString)
{
  // Increment first.
  if (aString)
    ++aString->iReferenceCount;
  if (iString)
  {
    --iString->iReferenceCount;
    if (iString->iReferenceCount == 0) delete iString;
  }
  iString = aString;
  return *this;
}

LispStringSmartPtr::~LispStringSmartPtr()
{
  if (iString && !--iString->iReferenceCount)
    delete iString;
}

