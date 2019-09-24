// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2019, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *TMPLoggerName NS_TYPED_EXTENSIBLE_ENUM;
FOUNDATION_EXPORT TMPLoggerName const TMPLoggerNameASL NS_SWIFT_NAME(TMPLoggerName.asl); // TMPASLLogger
FOUNDATION_EXPORT TMPLoggerName const TMPLoggerNameTTY NS_SWIFT_NAME(TMPLoggerName.tty); // TMPTTYLogger
FOUNDATION_EXPORT TMPLoggerName const TMPLoggerNameOS NS_SWIFT_NAME(TMPLoggerName.os); // TMPOSLogger
FOUNDATION_EXPORT TMPLoggerName const TMPLoggerNameFile NS_SWIFT_NAME(TMPLoggerName.file); // TMPFileLogger

NS_ASSUME_NONNULL_END
